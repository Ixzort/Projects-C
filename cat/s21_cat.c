#include "s21_cat.h"

int main(int argc, char *argv[]) {
  init_flags();
  parse_function(argc, argv);
  output(argc, argv);
  return 0;
}

void init_flags() {
  Flags_struct.b = false;
  Flags_struct.e = false;
  Flags_struct.v = false;
  Flags_struct.s = false;
  Flags_struct.t = false;
  Flags_struct.n = false;
}

void parse_function(int argc, char *argv[]) {
  int counter;
  int counter_index = 0;
  const char *flags_for_parse = "+beEnstT";

  opterr = 0;
  while (true) {
    counter =
        getopt_long(argc, argv, flags_for_parse, Long_options, &counter_index);
    if (counter == -1) break;
    switch (counter) {
      case 0:
        if (strcmp(Long_options[counter_index].name, "number-nonblank") == 0)
          Flags_struct.b = true;
        if (strcmp(Long_options[counter_index].name, "number") == 0)
          Flags_struct.n = true;
        if (strcmp(Long_options[counter_index].name, "squeeze-blank") == 0)
          Flags_struct.s = true;
        break;
      case 'b':
        Flags_struct.b = true;
        break;
      case 'e':
        Flags_struct.v = true;
        Flags_struct.e = true;
        break;
      case 'E':
        Flags_struct.e = true;
        break;
      case 's':
        Flags_struct.s = true;
        break;
      case 't':
        Flags_struct.v = true;
        Flags_struct.t = true;
        break;
      case 'T':
        Flags_struct.t = true;
        break;
      case 'n':
        Flags_struct.n = true;
        break;
      default:
        printf("s21_cat: illegal option -- %s\n", argv[optind - 1] + 1);
        printf("usage: s21_cat [-beEnstT] [file ...]\n");
    }
  }
  if (Flags_struct.b) Flags_struct.n = false;
}

void output(int argc, char *argv[]) {
  int sym_askii = 0;
  size_t line_number = 1;
  size_t empty_line_flag = 0;
  bool new_line = true;

  for (int i = optind; i < argc; i++) {
    FILE *file = fopen(argv[i], "r");
    if (file == NULL) {
      printf("s21_cat: %s: No such file or directory\n", argv[i]);
      continue;
    }
    while ((sym_askii = fgetc(file)) != EOF) {
      if (Flags_struct.s) {
        if (sym_askii == '\n') {
          empty_line_flag += 1;
          if (empty_line_flag > 2) {
            continue;
          }
        } else {
          empty_line_flag = 0;
        }
      }
      if (Flags_struct.n && new_line) {
        printf("%6ld\t", line_number);
        line_number += 1;
        new_line = false;
      }
      if (Flags_struct.b && new_line && sym_askii != '\n') {
        printf("%6ld\t", line_number);
        line_number += 1;
        new_line = false;
      }
      if (Flags_struct.t && sym_askii == '\t') {
        printf("^");
        sym_askii = 'I';
      }
      if (Flags_struct.v && sym_askii != '\n' && sym_askii != '\t') {
        if (sym_askii >= 0 && sym_askii <= 31) {
          printf("^");
          sym_askii += 64;
        } else if (sym_askii == 127) {
          printf("^");
          sym_askii -= 64;
        }
      }
      if (Flags_struct.e && sym_askii == '\n') {
        printf("$");
      }
      if (sym_askii == '\n') {
        new_line = true;
      }
      printf("%c", sym_askii);
    }
    fclose(file);
  }
}