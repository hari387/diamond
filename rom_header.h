#include <cstdint>
#include <iostream>

struct RomHeader {
  char game_title[12];
  char game_code[4];
  uint16_t maker_code;
  uint8_t unit_code;
  char encryption_seed;
  uint8_t device_capacity;
  char reserved1[7];
  uint16_t game_revision;
  uint8_t rom_version;
  char internal_flags;
  uint32_t arm9_rom_offset;
  uint32_t arm9_entry_address;
  uint32_t arm9_load_address;
  uint32_t arm9_code_size;
  uint32_t arm7_rom_offset;
  uint32_t arm7_entry_address;
  uint32_t arm7_load_address;
  uint32_t arm7_code_size;
  char reserved2[16];
  uint32_t arm9_overlay_offset;
  uint32_t arm9_overlay_size;
  uint32_t arm7_overlay_offset;
  uint32_t arm7_overlay_size;

  friend std::ostream& operator<<(std::ostream& os, const RomHeader& header);
};