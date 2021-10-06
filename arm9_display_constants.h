// ARM9 Graphics I/O Map
// Everything here is relative to Nds9MemoryMap::ARM9_IO_PORTS

#include <cstdint>

namespace DisplayEngineA {

static constexpr uint32_t DISPCNT = 0x0;
static constexpr uint32_t DISPSTAT = 0x4;
static constexpr uint32_t VCOUNT = 0x6;

static constexpr uint32_t BG0CNT = 0x8;
static constexpr uint32_t BG1CNT = 0xA;
static constexpr uint32_t BG2CNT = 0xC;
static constexpr uint32_t BG3CNT = 0xE;

static constexpr uint32_t BG0HOFS = 0x10;
static constexpr uint32_t BG0VOFS = 0x12;
static constexpr uint32_t BG1HOFS = 0x14;
static constexpr uint32_t BG1VOFS = 0x16;
static constexpr uint32_t BG2HOFS = 0x18;
static constexpr uint32_t BG2VOFS = 0x1A;
static constexpr uint32_t BG3HOFS = 0x1C;
static constexpr uint32_t BG3VOFS = 0x1E;
static constexpr uint32_t BG2PA = 0x20;
static constexpr uint32_t BG2PB = 0x22;
static constexpr uint32_t BG2PC = 0x24;
static constexpr uint32_t BG2PD = 0x26;

static constexpr uint32_t BG2X = 0x28;
static constexpr uint32_t BG2Y = 0x2C;

static constexpr uint32_t BG3PA = 0x30;
static constexpr uint32_t BG3PB = 0x32;
static constexpr uint32_t BG3PC = 0x34;
static constexpr uint32_t BG3PD = 0x36;

static constexpr uint32_t BG3X = 0x38;
static constexpr uint32_t BG3Y = 0x3C;

static constexpr uint32_t WIN0H = 0x40;
static constexpr uint32_t WIN1H = 0x42;
static constexpr uint32_t WIN0V = 0x44;
static constexpr uint32_t WIN1V = 0x46;

static constexpr uint32_t WININ = 0x48;
static constexpr uint32_t WINOUT = 0x4A;

static constexpr uint32_t MOSAIC = 0x4C;

static constexpr uint32_t BLDCNT = 0x50;
static constexpr uint32_t BLDALPHA = 0x52;
static constexpr uint32_t BLDY = 0x54;

static constexpr uint32_t DISP3DCNT = 0x60;
static constexpr uint32_t DISPCAPCNT = 0x64;
static constexpr uint32_t DISP_MMEM_FIFO = 0x68;

static constexpr uint32_t MASTER_BRIGHT = 0x6C;

}  // namespace DisplayEngineA

namespace DisplayEngineB {

static constexpr uint32_t DISPCNT = 0x0;

static constexpr uint32_t BG0CNT = 0x8;
static constexpr uint32_t BG1CNT = 0xA;
static constexpr uint32_t BG2CNT = 0xC;
static constexpr uint32_t BG3CNT = 0xE;

static constexpr uint32_t BG0HOFS = 0x10;
static constexpr uint32_t BG0VOFS = 0x12;
static constexpr uint32_t BG1HOFS = 0x14;
static constexpr uint32_t BG1VOFS = 0x16;
static constexpr uint32_t BG2HOFS = 0x18;
static constexpr uint32_t BG2VOFS = 0x1A;
static constexpr uint32_t BG3HOFS = 0x1C;
static constexpr uint32_t BG3VOFS = 0x1E;
static constexpr uint32_t BG2PA = 0x20;
static constexpr uint32_t BG2PB = 0x22;
static constexpr uint32_t BG2PC = 0x24;
static constexpr uint32_t BG2PD = 0x26;

static constexpr uint32_t BG2X = 0x28;
static constexpr uint32_t BG2Y = 0x2C;

static constexpr uint32_t BG3PA = 0x30;
static constexpr uint32_t BG3PB = 0x32;
static constexpr uint32_t BG3PC = 0x34;
static constexpr uint32_t BG3PD = 0x36;

static constexpr uint32_t BG3X = 0x38;
static constexpr uint32_t BG3Y = 0x3C;

static constexpr uint32_t WIN0H = 0x40;
static constexpr uint32_t WIN1H = 0x42;
static constexpr uint32_t WIN0V = 0x44;
static constexpr uint32_t WIN1V = 0x46;

static constexpr uint32_t WININ = 0x48;
static constexpr uint32_t WINOUT = 0x4A;

static constexpr uint32_t MOSAIC = 0x4C;

static constexpr uint32_t BLDCNT = 0x50;
static constexpr uint32_t BLDALPHA = 0x52;
static constexpr uint32_t BLDY = 0x54;

static constexpr uint32_t MASTER_BRIGHT = 0x6C;

}  // namespace DisplayEngineB