cmake_minimum_required(VERSION 2.8)
project(testsvm)
find_package(qibuild)

set(_srcs 
  testsvm.h
  testsvm.cpp
  main.cpp
  wxzSVM.h
  wxzSVM.cpp
)

qi_create_bin(testsvm ${_srcs})

qi_use_lib(testsvm ALCOMMON ALPROXIES ALVISION OPENCV2_WORLD)
