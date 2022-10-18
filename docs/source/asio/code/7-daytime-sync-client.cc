#include "asio.hpp"
#include <array>
#include <iostream>

using asio::ip::tcp;
int main(int argc, char *argv[]) {
  try {
    if (argc != 2) {
      std::cerr << "Usage: client <host>" << std::endl;
      return 1;
    }

    asio::io_context io;
    tcp::resolver resolver(io);

    tcp::resolver::results_type endpoints =
        resolver.resolve(argv[1], "daytime");

    tcp::socket socket(io);
    asio::connect(socket, endpoints);

    for (;;) {
      std::array<char, 128> buf;
      asio::error_code ec;
      size_t len = socket.read_some(asio::buffer(buf), ec);
      if (ec == asio::error::eof) {
        break;
      } else if (ec) {
        throw asio::system_error(ec);
      }
      std::cout.write(buf.data(), len);
    }
  } catch (std::exception &e) {
    std::cerr << "exception: " << e.what() << "\n";
  }
  return 0;
}
