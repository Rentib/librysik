#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "rysik.h"

#define WIDTH  800
#define HEIGHT 600

bool
save_to_ppm(Rysik *rys, char *restrict filename)
{
  FILE *fp;
  if (!(fp = fopen(filename, "wb"))) return false;

  fprintf(fp, "P6\n%zu %zu\n255\n", rys->width, rys->height);
  for (uint32_t i = 0; i < rys->width * rys->height; ++i) {
    uint8_t color[3] = {
        (((rys->pixels[i]) >> (8 * 0)) & 0xFF),
        (((rys->pixels[i]) >> (8 * 1)) & 0xFF),
        (((rys->pixels[i]) >> (8 * 2)) & 0xFF),
    };
    fwrite(color, 3, 1, fp);
  }

  fclose(fp);
  return true;
}

int
main(void)
{
  Rysik *rys;
  rys = rysik_init(WIDTH, HEIGHT);

  rysik_fill(rys, 0xFF0000FF);
  rysik_rect(rys, 100, 100, 200, 300, 0xFFFF0000);
  rysik_rect(rys, 100, 100, 300, 200, 0x6900FF00);
  rysik_circle(rys, 400, 300, 200, 0xAA00FFFF);
  rysik_circle(rys, 100, 300, 200, 0xAAFFFF00);
  rysik_fill(rys, 0xFFFFFFFF);
  rysik_line(rys, 0, 0, WIDTH, HEIGHT, 0xFF00FF00);
  rysik_line(rys, 0, HEIGHT, WIDTH, 0, 0xFF00FF00);
  rysik_triangle(rys, 100, 100, 200, 300, 300, 200, 0xFF0000FF);
  rysik_ellipse(rys, 300, 400, 200, 100, 0xFF00FF00);

  save_to_ppm(rys, "test.ppm");
  rysik_destroy(rys);
}
