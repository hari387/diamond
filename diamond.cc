#include <CImg.h>
#include <unistd.h>

#include <bitflags/bitflags.hpp>
#include <iostream>
#include <string>

using namespace cimg_library;

BEGIN_BITFLAGS(Flags)
FLAG(flag_a)
FLAG(flag_b)
END_BITFLAGS(Flags)

int main(int argc, char **argv) {
  const int width = 320;
  const int height = 240;
  // Create 3-channel RGB image
  CImg<> img(width, height, 1, 3);

  // Create main window
  CImgDisplay main_window(img, "Random Data", 0);
  const unsigned char color[] = {255, 128, 64};

  for (int i = 0; i < 100; ++i) {
    for (int j = 0; j < 150; ++j) {
      img.draw_point(i, j, color);
    }
  }
  main_window.display(img);

  Flags flags = Flags::flag_a;
  std::cout << flags.contains(Flags::flag_a) << std::endl;  // true
  std::cout << flags.contains(Flags::flag_b) << std::endl;  // false
}