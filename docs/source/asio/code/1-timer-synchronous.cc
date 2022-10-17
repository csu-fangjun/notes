#include "asio.hpp"
#include <iostream>

int main() {
  asio::io_context io;
  std::cout << "sleep for 1 second\n";
  asio::steady_timer t(io, asio::chrono::seconds(1));
  t.wait();
  std::cout << "hello world\n";
  return 0;
}
