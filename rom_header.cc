#include "rom_header.h"

#include <cstdlib>
#include <iostream>

using namespace std;

ostream& operator<<(ostream& os, const RomHeader& header) {
  os << "Game Title: " << string(header.game_title, sizeof(header.game_title))
     << endl
     << "Game Code: " << string(header.game_code, sizeof(header.game_code))
     << endl
     << "ROM Version: " << +header.rom_version << endl
     << "ARM9 ROM offset: "
     << "0x" << hex << header.arm9_rom_offset << endl
     << "ARM9 entry address: "
     << "0x" << hex << header.arm9_entry_address << endl
     << "ARM9 load address: "
     << "0x" << hex << header.arm9_load_address << endl
     << "ARM9 code size: "
     << "0x" << hex << header.arm9_code_size << endl
     << "ARM7 ROM offset: "
     << "0x" << hex << header.arm7_rom_offset << endl
     << "ARM7 entry address: "
     << "0x" << hex << header.arm7_rom_offset << endl
     << "ARM7 load address: "
     << "0x" << hex << header.arm7_rom_offset << endl
     << "ARM7 code size: "
     << "0x" << hex << header.arm7_code_size << endl;
  return os;
}
