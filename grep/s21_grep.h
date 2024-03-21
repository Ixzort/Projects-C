#ifndef S21_GREP_H_
#define S21_GREP_H_

#include <getopt.h>
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFSIZE 4096  //размер страницы

struct Options {
  bool e, i, v, c, l, n, h, s, f, o;
  int files_count;
  int empty_line;
} Flags_struct;

void init_flags();
void parse_function(int argc, char *argv[], char *pattern);
void open_file(int argc, char *argv[], char *pattern);
void func_e_flag(int *e_count, char *pattern);
void func_f_flag(int *e_count, char *pattern);
void output(char *argv[], char *pattern, FILE *file);

#endif