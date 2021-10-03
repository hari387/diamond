#include <cstdint>
#include <map>
#include <stdexcept>

class Nds9MemoryMap {
 private:
  enum MemoryMapSection : uint32_t {
    MAIN_MEMORY = 0x20000000,
    SHARED_WRAM = 0x30000000,
    ARM9_IO_PORTS = 0x40000000,
    STD_PALETTES = 0x50000000,
    BG_VRAM_A = 0x60000000,
    BG_VRAM_B = 0x62000000,
    OBJ_VRAM_A = 0x64000000,
    OBJ_VRAM_B = 0x66000000,
    LCDC_VRAM = 0x68000000,
    OAM = 0x70000000,
    GBA_ROM = 0x80000000,
    GBA_RAM = 0xA0000000,
    ARM9_BIOS = 0xFFFF0000
  };

  // array of sections and their addresses
  static constexpr MemoryMapSection MemoryMapSections[] = {
      MAIN_MEMORY, SHARED_WRAM, ARM9_IO_PORTS, STD_PALETTES, BG_VRAM_A,
      BG_VRAM_B,   OBJ_VRAM_A,  OBJ_VRAM_B,    LCDC_VRAM,    OAM,
      GBA_ROM,     GBA_RAM,     ARM9_BIOS};

  static constexpr size_t NumMemoryMapSections =
      sizeof(MemoryMapSections) / sizeof(MemoryMapSections[0]);

  // array of sizes corresponding to sections
  static constexpr uint32_t MemoryMapSizes[] = {
      0x400000, 0x2000000, 0x4000, 0x800,     0x80000, 0x20000, 0x40000,
      0x20000,  0xA4000,   0x800,  0x2000000, 0x10000, 0x8000};

  size_t getMemoryMapSectionNumber(uint32_t addr);

  void validateChunkAddress(uint32_t chunk_addr, size_t section_num) {
    if (chunk_addr >= MemoryMapSizes[section_num])
      throw std::out_of_range("Address not in memory range");
  };

 protected:
  // array of pointers to memory chunk of corresponding section
  uint8_t* MemoryMapChunks[sizeof(MemoryMapSections)];

 public:
  Nds9MemoryMap();
  ~Nds9MemoryMap();

  uint32_t loadWord(uint32_t addr);
  uint16_t loadHalfWord(uint32_t addr);
  uint8_t loadByte(uint32_t addr);

  void storeWord(uint32_t addr, uint32_t val);
  void storeHalfWord(uint32_t addr, uint16_t val);
  void storeByte(uint32_t addr, uint8_t val);
};
