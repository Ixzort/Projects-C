#include "s21_grep.h"

int main(int argc, char *argv[]) {
  char pattern[BUFFSIZE] = {0};

  init_flags();
  if (argc > 1) {
    parse_function(argc, argv, pattern);
    open_file(argc, argv, pattern);
  } else {
    printf(
        "usage: s21_grep [-eivclnhsfo] [-e pattern] [-f file] [pattern] "
        "[file...]\n");
  }
  return (0);
}

void init_flags() {
  Flags_struct.e = false;
  Flags_struct.i = false;
  Flags_struct.v = false;
  Flags_struct.c = false;
  Flags_struct.l = false;
  Flags_struct.n = false;
  Flags_struct.h = false;
  Flags_struct.s = false;
  Flags_struct.f = false;
  Flags_struct.o = false;
  Flags_struct.files_count = 0;
  Flags_struct.empty_line = 0;
}

void func_e_flag(int *e_count, char *pattern) {
  if (*e_count) {
    strcat(pattern, "|");
  }
  if (!*optarg) {
    optarg = ".";
    Flags_struct.empty_line += 1;
  }
  strcat(pattern, optarg);
  *e_count += 1;
}

void func_f_flag(int *e_count, char *pattern) {
  FILE *fp = NULL;
  char line[BUFFSIZE] = {0};

  if ((fp = fopen(optarg, "r"))) {
    fseek(fp, 0, SEEK_SET);
    while (fgets(line, BUFFSIZE, fp) != NULL) {
      if (line[strlen(line) - 1] == '\n') line[strlen(line) - 1] = 0;
      if (*e_count > 0) strcat(pattern, "|");
      if (*line == '\0') {
        Flags_struct.empty_line = 1;
        strcat(pattern, ".");
      } else {
        strcat(pattern, line);
      }
      *e_count += 1;
    }
    fclose(fp);
  } else {
    printf("s21_grep: %s: No such file\n", optarg);
    exit(1);
  }
}

void parse_function(int argc, char *argv[], char *pattern) {
  int option, e_count = 0;
  const char *optstring = "e:f:ivclnhso";

  while (true) {
    option = getopt_long(argc, argv, optstring, NULL, NULL);
    if (option == -1) break;
    switch (option) {
      case 'e':
        Flags_struct.e = true;
        func_e_flag(&e_count, pattern);
        break;
      case 'i':
        Flags_struct.i = true;
        break;
      case 'v':
        Flags_struct.v = true;
        break;
      case 'c':
        Flags_struct.c = true;
        break;
      case 'l':
        Flags_struct.l = true;
        break;
      case 'n':
        Flags_struct.n = true;
        break;
      case 'h':
        Flags_struct.h = true;
        break;
      case 's':
        Flags_struct.s = true;
        break;
      case 'f':
        Flags_struct.f = true;
        func_f_flag(&e_count, pattern);
        break;
      case 'o':
        Flags_struct.o = true;
        break;
      default:
        exit(1);
    }
  }
  if (Flags_struct.empty_line) Flags_struct.o = 0;
  if (!Flags_struct.e && !Flags_struct.f) {
    if (!*argv[optind]) argv[optind] = ".";
    strcat(pattern, argv[optind]);
    optind += 1;
  }
}

void open_file(int argc, char *argv[], char *pattern) {
  Flags_struct.files_count = argc - optind;

  for (; optind < argc; optind++) {
    FILE *file;
    if ((file = fopen(argv[optind], "r")) != NULL) {
      output(argv, pattern, file);
      fclose(file);
    } else {
      if (!Flags_struct.s)
        printf("s21_grep: %s: No such file or directory\n", argv[optind]);
    }
  }
}

void output(char *argv[], char *pattern, FILE *file) {
  regex_t regex;
  int success = 0;
  int regflag = REG_EXTENDED;
  char str[BUFFSIZE] = {0};
  size_t line_number = 1;
  int lines_count = 0;
  regmatch_t pmatch[1] = {0};
  size_t nmatch = 1;

  if (Flags_struct.i) regflag |= REG_ICASE;
  regcomp(&regex, pattern, regflag);

  while (!feof(file)) {
    if (fgets(str, BUFFSIZE, file)) {
      int new_line_o_counter = 1;
      success = regexec(&regex, str, nmatch, pmatch, 0);
      if (Flags_struct.v) success = success ? 0 : 1;

      if (success != REG_NOMATCH) {
        if (!Flags_struct.c && !Flags_struct.l) {
          if (Flags_struct.files_count > 1 && !Flags_struct.h) {
            printf("%s:", argv[optind]);
          }
          if (Flags_struct.n) {
            printf("%lu:", line_number);
          }
          if (Flags_struct.o && !Flags_struct.v) {
            new_line_o_counter = 0;
            char *ptr = str;
            while (!success) {
              if (pmatch[0].rm_eo == pmatch[0].rm_so) break;
              printf("%.*s\n", (int)(pmatch[0].rm_eo - pmatch[0].rm_so),
                     ptr + pmatch[0].rm_so);
              ptr += pmatch[0].rm_eo;
              success = regexec(&regex, ptr, nmatch, pmatch, REG_NOTBOL);
            }
          }

          if (!Flags_struct.o) printf("%s", str);
          if (str[strlen(str) - 1] != '\n' && new_line_o_counter) {
            printf("\n");
          }
        }
        lines_count += 1;
      }

      line_number += 1;
    }
  }

  if (Flags_struct.c) {
    if (Flags_struct.files_count > 1 && !Flags_struct.h) {
      printf("%s:", argv[optind]);
    }
    if (Flags_struct.l && lines_count)
      printf("1\n");
    else
      printf("%d\n", lines_count);
  }

  if (Flags_struct.l && lines_count) {
    printf("%s\n", argv[optind]);
  }
  regfree(&regex);
}