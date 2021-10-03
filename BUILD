cc_binary(
  name = "diamond",
  srcs = ["diamond.cc"],
  deps = ["rom_header_lib"],
  linkopts = ["-lX11", "-lpthread", "-lcapstone"],
)

cc_binary(
  name = "rom_header_main",
  deps = ["rom_header_lib", "nds9_memory_map"],
  srcs = ["rom_header_main.cc"],
)

cc_library(
  name = "rom_header_lib",
  hdrs = ["rom_header.h"],
  srcs = ["rom_header.cc"]
)

cc_library(
  name = "nds9_memory_map",
  hdrs = ["nds9_memory_map.h"],
  srcs = ["nds9_memory_map.cc"]
)
