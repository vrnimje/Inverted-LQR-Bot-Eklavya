file(REMOVE_RECURSE
  ".bin_timestamp"
  "bootloader/bootloader.bin"
  "bootloader/bootloader.elf"
  "bootloader/bootloader.map"
  "config/sdkconfig.cmake"
  "config/sdkconfig.h"
  "esp-idf-vscode-boilerplate.bin"
  "esp-idf-vscode-boilerplate.map"
  "flash_project_args"
  "project_elf_src.c"
  "CMakeFiles/gen_project_binary"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/gen_project_binary.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
