#include <iostream>

#include "rom_header.h"

using namespace std;

RomHeader header;

int main(int argc, char** argv) {
  if (argc < 2) {
    cerr << "Usage: ./rom_header [rom_file]" << endl;
    exit(1);
  }
  string rom_file_name = argv[1];
  cout << "Reading " << rom_file_name << endl;
  FILE* rom_file = fopen(rom_file_name.c_str(), "rb");
  fread(&header, 1, sizeof(header), rom_file);
  cout << header;
}