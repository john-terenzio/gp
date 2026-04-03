#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stringrand.h"

// Return a random 32 bit integer in [0, n)
static uint32_t randintn(uint32_t n) {
  static FILE *urandom = NULL;
  uint32_t r, limit;

  if (!urandom) {
    urandom = fopen(URANDOM_PATH, "rb");
    if (!urandom) {
      perror("Failed to open " URANDOM_PATH);
      exit(EXIT_FAILURE);
    }
  }

  // Rejection sampling: discard values that would cause bias
  limit = UINT32_MAX - (UINT32_MAX % n);
  do {
    if (fread(&r, sizeof(uint32_t), 1, urandom) != 1) {
      perror("Failed to read " URANDOM_PATH);
      exit(EXIT_FAILURE);
    }
  } while (r >= limit);

  return r % n;
}

// Chose a random character from a string and return it
char strrand(const char *str) {
  return str[randintn(strlen(str))];
}

// Shuffle a string in place using the Fisher-Yates algorithm and return
// a pointer to it
char *strshuffle(char *str) {
  char tmp;
  size_t i = strlen(str), j;

  while (i) {
    j = randintn(i--);
    tmp = str[j];
    str[j] = str[i];
    str[i] = tmp;
  }

  return str;
}
