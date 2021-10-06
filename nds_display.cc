#include "nds_display.h"

#include <CImg.h>

#include <chrono>
#include <iostream>

constexpr char NdsDisplay::window_title[];

NdsDisplay::NdsDisplay(uint8_t* arm9_io_ports, uint8_t* bg_vram_a,
                       uint8_t* bg_vram_b, uint8_t* obj_vram_a,
                       uint8_t* obj_vram_b, uint8_t* lcdc_vram)
    : img(width, height, 1, 3),
      display(img, window_title, 0 /*normalization*/),
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
  while (!nds_display->stop_thread_flag) {
    std::this_thread::sleep_for(
        std::chrono::duration<double>(1.0 / nds_display->fps));
    std::cout << "Printing from display thread" << std::endl;
  }
}
