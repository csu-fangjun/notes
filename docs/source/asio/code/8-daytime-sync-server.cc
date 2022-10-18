#include "asio.hpp"
#include <ctime>
#include <iostream>
#include <string>

using asio::ip::tcp;
std::string make_daytime_string() {
  using namespace std;
  time_t now = time(0);
  return ctime(&now);
}

int main() {
  try {
    asio::io_context io;
    // need sudo permission to bind port 13
    tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 13));
    std::cout << "started\n";
    for (;;) {
      tcp::socket socket(io);
      acceptor.accept(socket);

      auto message = make_daytime_string();
      asio::error_code ec;
      asio::write(socket, asio::buffer(message), ec);
    }
  } catch (std::exception &e) {
    std::cout << "Exception: " << e.what() << "\n";
  }
  return 0;
}
