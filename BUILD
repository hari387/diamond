cc_binary(
  name = "diamond",
  srcs = ["diamond.cc"],
  deps = ["rom_header_lib"],
  linkopts = ["-lX11", "-lpthread", "-lcapstone"],
)

cc_binary(
  name = "rom_header_main",
  deps = ["rom_header_lib"],
  srcs = ["rom_header_main.cc"],
)

cc_binary(
  name = "nds_display_main",
  deps = ["nds_display_lib"],
  srcs = ["nds_display_main.cc"],
  linkopts = ["-lX11"]
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

cc_library(
  name = "nds_display_lib",
  hdrs = ["nds_display.h", "arm9_display_constants.h"],
  srcs = ["nds_display.cc"],
  deps = ["@com_google_absl//absl/strings"]
)
