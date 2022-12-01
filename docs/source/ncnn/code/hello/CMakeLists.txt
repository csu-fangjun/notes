set(CMAKE_CXX_STANDARD 11)
add_executable(main
  main.cc
  test-net.cc
  test-param-dict.cc
  test-data-reader.cc
  )
target_link_libraries(main ncnn)
