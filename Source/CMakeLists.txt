cmake_minimum_required(VERSION 3.1...3.26)

project(
  serial
  VERSION 1.0
  LANGUAGES CXX)

find_package(Boost 1.36.0)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  add_executable(serial 
    main.cpp
    Serial.h
    Serial.cpp)
endif()