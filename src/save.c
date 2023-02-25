#include <stdio.h>

#include "internals.h"

bool
rysik_save_to_ppm(Rysik *rys, char *restrict filename)
{
  FILE *fp;
  if (!(fp = fopen(filename, "wb"))) return false;

  fprintf(fp, "P6\n%zu %zu\n255\n", rys->width, rys->height);
  for (uint32_t i = 0; i < rys->width * rys->height; ++i) {
    uint8_t color[3] = {
        RYSIK_RED(rys->pixels[i]),
        RYSIK_GREEN(rys->pixels[i]),
        RYSIK_BLUE(rys->pixels[i]),
    };
    fwrite(color, 3, 1, fp);
  }

  fclose(fp);
  return true;
}
