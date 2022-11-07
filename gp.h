#include <stdint.h>
#include <stdbool.h>

#define GP_DEFAULT_LENGTH 16
#define GP_MAXIMUM_LENGTH 64
#define GP_DEFAULT_NUMBER 1
#define GP_MAXIMUM_NUMBER 64

typedef struct {
  char *groups[4];
  char supergroup[128];
  size_t length;
} gp_grouplist;

void gp_init_grouplist(gp_grouplist *grouplist, bool digits, bool lowers,
                       bool uppers, bool symbols);
void gp_puts(gp_grouplist *grouplist, size_t length);
