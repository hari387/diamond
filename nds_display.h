#include <CImg.h>

#include <atomic>
#include <cstdint>
#include <string>
#include <thread>

#include "absl/strings/string_view.h"
#include "arm9_display_constants.h"

class NdsDisplay {
 private:
  uint8_t* arm9_io_ports;
  uint8_t* bg_vram_a;
  uint8_t* bg_vram_b;
  uint8_t* obj_vram_a;
  uint8_t* obj_vram_b;
  uint8_t* lcdc_vram;

  static constexpr char window_title[] = "Diamond";

  // pixel dimensions of each screen
  static constexpr unsigned int width = 256;
  static constexpr unsigned int height = 192;

  cimg_library::CImg<> img;
  cimg_library::CImgDisplay display;

  static constexpr double fps = 20.0;

  std::atomic<bool> stop_thread_flag;
  std::thread display_thread;

  static void displayMain(NdsDisplay* nds_display);

 public:
  NdsDisplay(uint8_t* arm9_io_ports, uint8_t* bg_vram_a, uint8_t* bg_vram_b,
             uint8_t* obj_vram_a, uint8_t* obj_vram_b, uint8_t* lcdc_vram);
  ~NdsDisplay();
};