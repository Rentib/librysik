#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "../rysik.h"

#define MAX(A, B) ((A) > (B) ? (A) : (B))
#define MIN(A, B) ((A) < (B) ? (A) : (B))
#define ABS(A)    ((A) < 0 ? -(A) : (A))

static inline void
horizontal_line(Rysik *rys, int x, int y, size_t w, uint32_t color)
{
  uint32_t *pixel = rys->pixels + x + rys->width * y;
  while (w--) *pixel++ = color;
}
