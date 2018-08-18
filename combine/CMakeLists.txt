cmake_minimum_required(VERSION 2.8)
project(combine)

find_package(qibuild)

# Create a executable named shijue
# with the source file: main.cpp
qi_create_bin(combine "main.cpp")

# Add a simple test:
qi_use_lib(combine OPENCV2_WORLD)
