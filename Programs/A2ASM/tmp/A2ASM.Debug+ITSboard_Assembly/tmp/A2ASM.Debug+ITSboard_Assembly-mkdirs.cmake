# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/markopetreski/ITS-BRD-VSC/Programs/A2ASM/tmp/A2ASM.Debug+ITSboard_Assembly"
  "/Users/markopetreski/ITS-BRD-VSC/Programs/A2ASM/tmp/1"
  "/Users/markopetreski/ITS-BRD-VSC/Programs/A2ASM/tmp/A2ASM.Debug+ITSboard_Assembly"
  "/Users/markopetreski/ITS-BRD-VSC/Programs/A2ASM/tmp/A2ASM.Debug+ITSboard_Assembly/tmp"
  "/Users/markopetreski/ITS-BRD-VSC/Programs/A2ASM/tmp/A2ASM.Debug+ITSboard_Assembly/src/A2ASM.Debug+ITSboard_Assembly-stamp"
  "/Users/markopetreski/ITS-BRD-VSC/Programs/A2ASM/tmp/A2ASM.Debug+ITSboard_Assembly/src"
  "/Users/markopetreski/ITS-BRD-VSC/Programs/A2ASM/tmp/A2ASM.Debug+ITSboard_Assembly/src/A2ASM.Debug+ITSboard_Assembly-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/markopetreski/ITS-BRD-VSC/Programs/A2ASM/tmp/A2ASM.Debug+ITSboard_Assembly/src/A2ASM.Debug+ITSboard_Assembly-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/markopetreski/ITS-BRD-VSC/Programs/A2ASM/tmp/A2ASM.Debug+ITSboard_Assembly/src/A2ASM.Debug+ITSboard_Assembly-stamp${cfgdir}") # cfgdir has leading slash
endif()
