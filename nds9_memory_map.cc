#include "nds9_memory_map.h"

#include <stdexcept>

Nds9MemoryMap::Nds9MemoryMap() {
  for (size_t i = 0; i < NumMemoryMapSections; i++) {
    MemoryMapChunks[i] = (uint8_t*)malloc(MemoryMapSizes[i]);
  }
};

Nds9MemoryMap::~Nds9MemoryMap() {
  for (size_t i = 0; i < NumMemoryMapSections; i++) free(MemoryMapChunks[i]);
};

uint32_t Nds9MemoryMap::loadWord(uint32_t addr) {
  size_t section_num = getMemoryMapSectionNumber(addr);
  addr -= MemoryMapSections[section_num];
  validateChunkAddress(addr, section_num);
  return *((uint32_t*)(MemoryMapChunks[section_num] + addr));
}

uint16_t Nds9MemoryMap::loadHalfWord(uint32_t addr) {
  size_t section_num = getMemoryMapSectionNumber(addr);
  addr -= MemoryMapSections[section_num];
  validateChunkAddress(addr, section_num);
  return *((uint16_t*)(MemoryMapChunks[section_num] + addr));
}

uint8_t Nds9MemoryMap::loadByte(uint32_t addr) {
  size_t section_num = getMemoryMapSectionNumber(addr);
  addr -= MemoryMapSections[section_num];
  validateChunkAddress(addr, section_num);
  return MemoryMapChunks[section_num][addr];
}

void Nds9MemoryMap::storeWord(uint32_t addr, uint32_t val) {
  size_t section_num = getMemoryMapSectionNumber(addr);
  addr -= MemoryMapSections[section_num];
  validateChunkAddress(addr, section_num);
  (*(uint32_t*)(MemoryMapChunks[section_num] + addr)) = val;
}

void Nds9MemoryMap::storeHalfWord(uint32_t addr, uint16_t val) {
  size_t section_num = getMemoryMapSectionNumber(addr);
  addr -= MemoryMapSections[section_num];
  validateChunkAddress(addr, section_num);
  (*(uint16_t*)(MemoryMapChunks[section_num] + addr)) = val;
}

void Nds9MemoryMap::storeByte(uint32_t addr, uint8_t val) {
  size_t section_num = getMemoryMapSectionNumber(addr);
  addr -= MemoryMapSections[section_num];
  validateChunkAddress(addr, section_num);
  MemoryMapChunks[section_num][addr] = val;
}

size_t Nds9MemoryMap::getMemoryMapSectionNumber(uint32_t addr) {
  if (addr < MemoryMapSections[0])
    throw std::out_of_range("Address not in memory range");
  size_t i;
  for (i = 1; i < sizeof(MemoryMapSections) / sizeof(MemoryMapSections[0]);
       i++) {
    if (addr < MemoryMapSections[i]) return i - 1;
  }
  return i;
};