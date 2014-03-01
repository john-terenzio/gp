#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gp.h"

#define ABOUT "gp v0.0.2"
#define USAGE "usage: gp [-l num] [-n num] [--lowercase] " \
              "[--numeric] [--symbols]"

int main(int argc, const char *argv[]) {
  bool digits = true, lowers = true, uppers = true, symbols = false;
  gp_grouplist grouplist;
  uint8_t length = GP_DEFAULT_LENGTH, number = GP_DEFAULT_NUMBER, i;
  for (i = 1; i < argc; ++i) {
    if (!strcmp(argv[i], "-l")) {
      if (i + 1 < argc) {
        length = atoi(argv[i + 1]);
      }
    } else if (!strcmp(argv[i], "-n")) {
      if (i + 1 < argc) {
        number = atoi(argv[i + 1]);
      }
      number = number > GP_MAXIMUM_NUMBER ? GP_MAXIMUM_NUMBER : number;
    } else if (!strcmp(argv[i], "--lowercase")) {
      uppers = false;
    } else if (!strcmp(argv[i], "--numeric")) {
      lowers = false;
      uppers = false;
    } else if (!strcmp(argv[i], "--symbols")) {
      symbols = true;
    } else if (!strcmp(argv[i], "--help")) {
      puts(USAGE);
      return EXIT_SUCCESS;
    } else if (!strcmp(argv[i], "--version")) {
      puts(ABOUT);
      return EXIT_SUCCESS;
    }
  }
  gp_init_grouplist(&grouplist, digits, lowers, uppers, symbols);
  while (number--) {
    gp_puts(&grouplist, length);
  }
  return EXIT_SUCCESS;
}
