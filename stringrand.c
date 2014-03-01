#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#pragma GCC diagnostic ignored "-Wunused-result"

// Return a random 32 bit integer in [0, n)
static uint32_t randintn(uint32_t n) {
  static FILE *urandom = NULL;
  uint32_t r;
  if (!urandom) {
    urandom = fopen("/dev/urandom", "rb");
  }
  fread(&r, sizeof(uint32_t), 1, urandom);
  return floor(((double)r / UINT32_MAX) * n);
}

// Chose a random character from a string and return it
char strrand(const char *str) {
  return str[randintn(strlen(str))];
}

// Shuffle a string in place using the Fisher-Yates algorithm and return
// a pointer to it
char *strshuffle(char *str) {
  char tmp;
  uint32_t i = strlen(str), j;
  while (i) {
    j = randintn(i--);
    tmp = str[j];
    str[j] = str[i];
    str[i] = tmp;
  }
  return str;
}
