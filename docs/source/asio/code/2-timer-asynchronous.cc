#include "asio.hpp"
#include <iostream>

void print(const asio::error_code &) { std::cout << "done\n"; }

int main() {
  asio::io_context io;
  std::cout << "sleep for 1 seconds\n";
  asio::steady_timer t(io, asio::chrono::seconds(1));

  t.async_wait(&print);
  t.async_wait(&print);
  io.run();
  return 0;
}
