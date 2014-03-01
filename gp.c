#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gp.h"
#include "stringrand.h"

// Groups of possible characters
static char *DIGITS = "0123456789";
static char *LOWERS = "abcdefghijklmnopqrstuvwxyz";
static char *UPPERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static char *SYMBOLS = ".?~!@#$%&*";

// Takes a gp_grouplist struct and populates it with the appropriate groups,
// supergroup is a string of all the chosen groups' characters
void gp_init_grouplist(gp_grouplist *grouplist, bool digits, bool lowers,
                       bool uppers, bool symbols) {
  grouplist->length = 0;
  grouplist->supergroup[0] = 0;
  if (digits) {
    grouplist->groups[grouplist->length++] = DIGITS;
    strcat(grouplist->supergroup, DIGITS);
  }
  if (lowers) {
    grouplist->groups[grouplist->length++] = LOWERS;
    strcat(grouplist->supergroup, LOWERS);
  }
  if (uppers) {
    grouplist->groups[grouplist->length++] = UPPERS;
    strcat(grouplist->supergroup, UPPERS);
  }
  if (symbols) {
    grouplist->groups[grouplist->length++] = SYMBOLS;
    strcat(grouplist->supergroup, SYMBOLS);
  }
}

// Print a random string (password) of length <= 255 having at least one
// character from each group
void gp_puts(gp_grouplist *grouplist, uint8_t length) {
  char out[GP_MAXIMUM_LENGTH + 1] = "";
  uint8_t i, j;
  if (length < grouplist->length) {
    length = grouplist->length;
  } else {
    length = length > GP_MAXIMUM_LENGTH ? GP_MAXIMUM_LENGTH : length;
  }
  for (i = 0, j = 0; i < grouplist->length; ++i, ++j) {
    out[j] = strrand(grouplist->groups[i]);
  }
  for (i = 0; i < length - grouplist->length; ++i, ++j) {
    out[j] = strrand(grouplist->supergroup);
  }
  out[j] = 0;
  puts(strshuffle(out));
}
