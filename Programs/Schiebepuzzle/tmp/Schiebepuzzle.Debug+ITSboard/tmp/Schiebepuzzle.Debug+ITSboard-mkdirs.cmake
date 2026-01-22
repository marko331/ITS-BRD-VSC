# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/franz/GIT_HUB/ML_GSP_VSC_KRF/Programs/Schiebepuzzle/tmp/Schiebepuzzle.Debug+ITSboard"
  "/Users/franz/GIT_HUB/ML_GSP_VSC_KRF/Programs/Schiebepuzzle/tmp/1"
  "/Users/franz/GIT_HUB/ML_GSP_VSC_KRF/Programs/Schiebepuzzle/tmp/Schiebepuzzle.Debug+ITSboard"
  "/Users/franz/GIT_HUB/ML_GSP_VSC_KRF/Programs/Schiebepuzzle/tmp/Schiebepuzzle.Debug+ITSboard/tmp"
  "/Users/franz/GIT_HUB/ML_GSP_VSC_KRF/Programs/Schiebepuzzle/tmp/Schiebepuzzle.Debug+ITSboard/src/Schiebepuzzle.Debug+ITSboard-stamp"
  "/Users/franz/GIT_HUB/ML_GSP_VSC_KRF/Programs/Schiebepuzzle/tmp/Schiebepuzzle.Debug+ITSboard/src"
  "/Users/franz/GIT_HUB/ML_GSP_VSC_KRF/Programs/Schiebepuzzle/tmp/Schiebepuzzle.Debug+ITSboard/src/Schiebepuzzle.Debug+ITSboard-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/franz/GIT_HUB/ML_GSP_VSC_KRF/Programs/Schiebepuzzle/tmp/Schiebepuzzle.Debug+ITSboard/src/Schiebepuzzle.Debug+ITSboard-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/franz/GIT_HUB/ML_GSP_VSC_KRF/Programs/Schiebepuzzle/tmp/Schiebepuzzle.Debug+ITSboard/src/Schiebepuzzle.Debug+ITSboard-stamp${cfgdir}") # cfgdir has leading slash
endif()
