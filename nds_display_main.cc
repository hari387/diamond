#include <cstdint>
#include <iostream>

#include "nds_display.h"

int main(int argc, char** argv) {
  uint16_t screen_buf[192 * 256];
  memset(screen_buf, 0, sizeof(screen_buf));
  NdsDisplay nds_display(NULL, NULL, NULL, NULL, NULL, (uint8_t*)screen_buf);
  sleep(1);
  for (size_t i = 0; i < sizeof(screen_buf) / sizeof(screen_buf[0]); i++)
    screen_buf[i] = 0x1f;  // red in 16 bit format XBBBBBGGGGGRRRRR
  sleep(1);
  for (size_t i = 0; i < sizeof(screen_buf) / sizeof(screen_buf[0]); i++)
    screen_buf[i] = 0x3e0;  // green in 16 bit format XBBBBBGGGGGRRRRR
  sleep(1);
  for (size_t i = 0; i < sizeof(screen_buf) / sizeof(screen_buf[0]); i++)
    screen_buf[i] = 0x7c00;  // blue in 16 bit format XBBBBBGGGGGRRRRR
  sleep(1);
}