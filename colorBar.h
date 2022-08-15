#ifndef __OUTDEV__
#define __OUTDEV__ spr
#endif

void colorBar(uint16_t xp, uint16_t yp, uint16_t w, uint16_t h) {

  uint16_t x = w;
  uint16_t y = h;

  typedef struct {
    uint32_t col;
    uint16_t xlen;
    uint16_t ylen;
  } COLORBAR_T;

  COLORBAR_T coltop[] = {
    0xF0F0F0, x /  7, y / 12 * 8,
    0xF0F000, x /  7, y / 12 * 8,
    0x00F0F0, x /  7, y / 12 * 8,
    0x00FF00, x /  7, y / 12 * 8,
    0xF000F0, x /  7, y / 12 * 8,
    0xF00000, x /  7, y / 12 * 8,
    0x0000F0, x /  7, y / 12 * 8,
  };
  COLORBAR_T colmid[] = {
    0x0000F0, x /  7, y / 12 * 1,
    0x000000, x /  7, y / 12 * 1,
    0xF000F0, x /  7, y / 12 * 1,
    0x000000, x /  7, y / 12 * 1,
    0x00F0F0, x /  7, y / 12 * 1,
    0x000000, x /  7, y / 12 * 1,
    0xF0F0F0, x /  7, y / 12 * 1,
  };
  COLORBAR_T colbtm[] = {
    0x404040, x /  6, y / 12 * 3,
    0xFFFFFF, x /  6, y / 12 * 3,
    0x808080, x /  6, y / 12 * 3,
    0x000000, x /  5, y / 12 * 3,
    0x202020, x / 21, y / 12 * 3,
    0x000000, x / 21, y / 12 * 3,
    0x303030, x / 21, y / 12 * 3,
    0x000000, x /  6, y / 12 * 3,
  };

  int xlen, ylen;
  uint32_t col;
  uint16_t xpos, ypos;

  xpos = xp;
  ypos = yp;
  for (int i = 0; i < sizeof(coltop) / 8; i++) {
    xlen = coltop[i].xlen;
    ylen = coltop[i].ylen;
    col = coltop[i].col;
    __OUTDEV__.fillRect(xpos, ypos, xlen, ylen, col);
    xpos += xlen;
  }

  xpos = xp;
  ypos += ylen;
  for (int i = 0; i < sizeof(colmid) / 8; i++) {
    xlen = colmid[i].xlen;
    ylen = colmid[i].ylen;
    col = colmid[i].col;
    __OUTDEV__.fillRect(xpos, ypos, xlen, ylen, col);
    xpos += xlen;
  }

  xpos = xp;
  ypos += ylen;
  for (int i = 0; i < sizeof(colbtm) / 8; i++) {
    xlen = colbtm[i].xlen;
    ylen = colbtm[i].ylen;
    col = colbtm[i].col;
    __OUTDEV__.fillRect(xpos, ypos, xlen, ylen, col);
    xpos += xlen;
  }
}
