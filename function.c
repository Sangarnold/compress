#include <stdio.h>
#incude <stdlib.h>
#include <string.h>
#include <stdint.h>

#define SRC_W 1920
#define SRC_H 1080
#define DST_W 640
#define DST_H 360

void scale_1080p_to_360p(const uint8_t *src, uint8_t *dst)
{
  const int src_stride = SRC_W * 3;
  const int dst_stride = DST_W * 3;

  for (int y=0; y<DST_H; y++){
      int src_y = (y*SRC_H) / DST_H;
      const uint8_t *src_row = src + src_y * src_stride;
      uint8_t *dst_row = dst + y*dst_stride;

  for(int x=0; x<DST_W; x++){
      int src_x = (x*SRC_W) / DST_W;
      const uint8_t *s = src_row + src_x * 3;
      uint8_t *d = dst_row + x*3;

      d[0] = s[0];
      d[1] = s[1];
      d[2] = s[2];
  }
  }
}
