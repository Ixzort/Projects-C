#ifndef S21_CAT_H_
#define S21_CAT_H_

#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

struct {
  bool b;
  bool e;
  bool v;
  bool s;
  bool t;
  bool n;
} Flags_struct;

static struct option Long_options[] = {{"number-nonblank", no_argument, 0, 0},
                                       {"number", no_argument, 0, 0},
                                       {"squeeze-blank", no_argument, 0, 0},
                                       {0, 0, 0, 0}};

void init_flags();
void parse_function(int argc, char *argv[]);
void output(int argc, char *argv[]);

#endif