#include "nds_display.h"

int main(int argc, char** argv) {
  unsigned char screen_buf[192 * 256 * 3];
  memset(screen_buf, 128, sizeof(screen_buf));
  NdsDisplay nds_display(NULL, NULL, NULL, NULL, NULL, screen_buf);
  sleep(2);
}