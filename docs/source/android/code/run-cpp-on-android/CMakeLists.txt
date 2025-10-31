if (CMAKE_VERSION VERSION_GREATER_EQUAL "4.0.0")
  set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
endif()

cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

project(qnn-demo)
include_directories(/Users/fangjun/Downloads/qairt/2.39.0.250926/include/QNN/)
add_executable(qnn-demo ./main.cc)

