cmake_minimum_required(VERSION 2.8)
project(avoidcollision)
find_package(qibuild)

set(_srcs 
  avoidcollision.h
  objectFinder.h
  avoidcollision.cpp
  ycylib2.h
  ycylib2.cpp
  main.cpp
)

qi_create_bin(avoidcollision ${_srcs})

qi_use_lib(avoidcollision ALCOMMON ALPROXIES ALVISION OPENCV2_WORLD)
