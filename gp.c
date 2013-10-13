#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stringrand.h"

#define DEFAULT_LENGTH 12
#define MAXIMUM_LENGTH 64
#define DEFAULT_NUMBER 1
#define MAXIMUM_NUMBER 64

// groups of possible characters
static const char *GROUPS[] = {
  "0123456789",
  "abcdefghijklmnopqrstuvwxyz",
  "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
};

// print a random string (password) of length l <= 255 having at least one
// character from each group
void putsp(uint8_t l) {
  char all[256] = "", out[MAXIMUM_LENGTH] = "";
  uint8_t n = sizeof(GROUPS) / sizeof(GROUPS[0]), i, j;
  l = l < n ? n : l > MAXIMUM_LENGTH ? MAXIMUM_LENGTH : l;
  for (i = 0, j = 0; i < n; ++i, ++j) {
    out[j] = strrand(GROUPS[i]);
    strcat(all, GROUPS[i]);
  }
  for (i = 0; i < l - n; ++i, ++j) {
    out[j] = strrand(all);
  }
  out[j] = 0;
  puts(strshuffle(out));
}

int main(int argc, const char *argv[]) {
  uint8_t l = DEFAULT_LENGTH, n = DEFAULT_NUMBER, i;
  for (i = 1; i < argc - 1; ++i) {
    if (!strcmp(argv[i], "-l")) {
      l = atoi(argv[i + 1]);
    } else if (!strcmp(argv[i], "-n")) {
      n = atoi(argv[i + 1]);
      n = n > MAXIMUM_NUMBER ? MAXIMUM_NUMBER : n;
    }
  }
  while (n--) {
    putsp(l);
  }
  return EXIT_SUCCESS;
}
