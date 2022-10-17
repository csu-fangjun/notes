#include "asio.hpp"
#include <iostream>

class printer {
public:
  printer(asio::io_context &io)
      : t_(io, asio::chrono::seconds(1)), counter_(0) {
    t_.async_wait([this](const asio::error_code &ec) { print(ec); });
  }

  void print(const asio::error_code &ec) {
    if (counter_ < 6) {
      std::cout << counter_ << "\n";
      counter_ += 1;
      t_.async_wait([this](const asio::error_code &e) { this->print(e); });
    }
  }

private:
  asio::steady_timer t_;
  int counter_;
};
int main() {
  asio::io_context io;
  printer p(io);
  io.run();
  return 0;
}
