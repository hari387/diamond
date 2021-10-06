#include "nds_display.h"

#include <CImg.h>

#include <chrono>
#include <cstdint>
#include <iostream>

constexpr char NdsDisplay::window_title[];

NdsDisplay::NdsDisplay(uint8_t* arm9_io_ports, uint8_t* bg_vram_a,
                       uint8_t* bg_vram_b, uint8_t* obj_vram_a,
                       uint8_t* obj_vram_b, uint8_t* lcdc_vram)
    : img(width, height, 1, 3),
      display(img, window_title, 0),
      stop_thread_flag(false) {
  this->arm9_io_ports = arm9_io_ports;
  this->bg_vram_a = bg_vram_a;
  this->bg_vram_b = bg_vram_b;
  this->obj_vram_a = obj_vram_a;
  this->obj_vram_b = obj_vram_b;
  this->lcdc_vram = lcdc_vram;

  display_thread = std::thread(NdsDisplay::displayMain, this);
}

NdsDisplay::~NdsDisplay() {
  stop_thread_flag = true;
  display_thread.join();
}

void NdsDisplay::displayMain(NdsDisplay* nds_display) {
  uint8_t color[] = {0, 0, 0};
  while (!nds_display->stop_thread_flag) {
    uint16_t* buf = (uint16_t*)nds_display->lcdc_vram;
    for (int i = 0; i < 192; i++) {
      for (int j = 0; j < 256; j++) {
        // *buf is in the form XBBBBBGGGGGRRRRR in binary.
        // We extract the colors and scale them up by shifting right 3 to make
        // them 8 bit.
        color[0] = ((*buf) & 0x1f) << 3;          // 0x1f == 0b11111
        color[1] = (((*buf) & 0x3e0) >> 5) << 3;  // 0x3e0 == 0b1111100000
        color[2] = (((*buf) & 0x7c00) >> 10)
                   << 3;  // 0x7c00 == 0b111110000000000
        nds_display->img.draw_point(j /*x-coordinate*/, i /*y-coordinate*/,
                                    color);
        buf++;
      }
    }
    nds_display->display.display(nds_display->img);
    std::this_thread::sleep_for(
        std::chrono::duration<double>(1.0 / nds_display->fps));
  }
}
