#include "asio.hpp"
#include <iostream>

void print(const asio::error_code &ec, asio::steady_timer *t, int *counter) {
  if (*counter < 3) {
    std::cout << *counter << "\n";
    *counter += 1;
    t->expires_at(t->expiry() + asio::chrono::seconds(1));
    t->async_wait(
        [t, counter](const asio::error_code &e) { print(e, t, counter); });
  }
}

int main() {
  asio::io_context io;
  asio::steady_timer t(io, asio::chrono::seconds(1));
  int counter = 0;

  // use a lambda to pass extra parameters
  t.async_wait(
      [&t, &counter](const asio::error_code &ec) { print(ec, &t, &counter); });
  io.run();
  return 0;
}
