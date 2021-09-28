cc_binary(
  name = "diamond",
  srcs = ["diamond.cc"],
  linkopts = ["-lX11", "-lpthread"],
)

cc_binary(
  name = "rom_header_main",
  deps = ["rom_header_lib"],
  srcs = ["rom_header_main.cc"],
)

cc_library(
  name = "rom_header_lib",
  hdrs = ["rom_header.h"],
  srcs = ["rom_header.cc"]
  )