#include <getopt.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gp.h"

#define ABOUT "gp v1.0"
#define USAGE "usage: gp [-l <int>] [-n <int>] [-p] [-h]" \
              "[-x digits|uppers|lowers|symbols]"

int main(int argc, char *argv[]) {
  bool digits = true,
       lowers = true,
       uppers = true,
       symbols = true;
  gp_grouplist grouplist;
  size_t length = GP_DEFAULT_LENGTH, number = GP_DEFAULT_NUMBER, opt;

  while ((opt = getopt(argc, argv, ":l:n:px:h")) != -1) {
    if ('l' == opt) {
      length = atoi(optarg);
      if (0 == length) {
        puts(USAGE);
        return EXIT_FAILURE;
      }
    } else if ('n' == opt) {
      number = atoi(optarg);
      if (0 == number) {
        puts(USAGE);
        return EXIT_FAILURE;
      }
    } else if ('p' == opt) {
      length = 4;
      uppers = false;
      lowers = false;
      symbols = false;
    } else if ('x' == opt) {
      if (!strcmp(optarg, "digits")) {
        digits = false;
      } else if (!strcmp(optarg, "uppers")) {
        uppers = false;
      } else if (!strcmp(optarg, "lowers")) {
        lowers = false;
      } else if (!strcmp(optarg, "symbols")) {
        symbols = false;
      } else {
        puts(USAGE);
        return EXIT_FAILURE;
      }
    } else if ('h' == opt) {
        puts(ABOUT);
        puts(USAGE);
        return EXIT_SUCCESS;
    } else {
        puts(USAGE);
        return EXIT_FAILURE;
    }
  }

  gp_init_grouplist(&grouplist, digits, lowers, uppers, symbols);

  while (number--) {
    gp_puts(&grouplist, length);
  }

  return EXIT_SUCCESS;
}
