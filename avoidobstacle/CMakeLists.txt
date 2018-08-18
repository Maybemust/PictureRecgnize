cmake_minimum_required(VERSION 2.8)
project(avoidobstacle)
find_package(qibuild)

set(_srcs 
  avoidcollision.h
  objectFinder.h
  avoidcollision.cpp
  ycylib2.h
  ycylib2.cpp
  main.cpp
  wxzSVM.h
  wxzSVM.cpp
)

qi_create_bin(avoidobstacle ${_srcs})

qi_use_lib(avoidobstacle ALCOMMON ALPROXIES ALVISION OPENCV2_WORLD)
