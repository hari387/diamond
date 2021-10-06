#include <CImg.h>
#include <capstone/capstone.h>
#include <unistd.h>

#include <bitset>
#include <iostream>
#include <string>

#include "rom_header.h"

using namespace cimg_library;

uint8_t code[1024];

RomHeader header;

int main(int argc, char** argv) {
  const int width = 320;
  const int height = 240;
  // Create 3-channel RGB image
  CImg<> img(width, height, 1, 3);

  // Create main window
  CImgDisplay main_window(img, "Random Data", 0);
  const unsigned char color[] = {255, 255, 255};

  for (int i = 0; i < 100; ++i) {
    for (int j = 0; j < 150; ++j) {
      img.draw_point(i, j, color);
    }
  }
  main_window.display(img);

  if (argc < 2) {
    std::cerr << "Usage: ./diamond [rom_file]" << std::endl;
    exit(1);
  }
  std::string rom_file_name = argv[1];
  std::cout << "Reading " << rom_file_name << std::endl;
  FILE* rom_file = fopen(rom_file_name.c_str(), "rb");
  fread(&header, 1, sizeof(header), rom_file);

  header.arm9_code_size = std::min(header.arm9_code_size, (uint32_t)1024);

  std::cout << header << std::endl;

  fseek(rom_file, header.arm9_rom_offset, SEEK_SET);
  fread(code, 1, header.arm9_code_size, rom_file);

  csh handle;
  cs_insn* insn;
  size_t count;

  if (cs_open(CS_ARCH_ARM, CS_MODE_ARM, &handle) != CS_ERR_OK) return -1;
  cs_option(handle, CS_OPT_DETAIL, CS_OPT_ON);

  count = cs_disasm(handle, code, header.arm9_code_size, 0x1000, 0, &insn);
  if (count > 0) {
    size_t j;
    for (j = 0; j < count; j++) {
      printf("%d 0x%lx:\t%s\t\t%s\n", insn[j].id, insn[j].address,
             insn[j].mnemonic, insn[j].op_str);
      fflush(stdout);
      uint32_t instr = *((uint32_t*)code + j);
      std::cout << std::bitset<sizeof(uint32_t) * 8>(instr) << std::endl;
    }

    cs_free(insn, count);
  } else {
    printf("ERROR: Failed to disassemble given code!\n");
  }

  cs_close(&handle);

  uint32_t stuff1 = 0xfffffff8;
  int32_t stuff2 = 0xfffffff8;

  printf("%u\t%d\n", stuff1, stuff2);
}