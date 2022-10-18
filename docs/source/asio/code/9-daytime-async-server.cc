#include "asio.hpp"
#include <ctime>
#include <iostream>
#include <memory>

using asio::ip::tcp;

std::string make_daytime_string() {
  using namespace std;
  time_t now = time(0);
  return ctime(&now);
}

class tcp_connection : public std::enable_shared_from_this<tcp_connection> {
public:
  using pointer = std::shared_ptr<tcp_connection>;

  static pointer create(asio::io_context &io) {
    return pointer(new tcp_connection(io));
    // return std::make_shared<tcp_connection>(io);
  }

  tcp::socket &socket() { return socket_; }

  void start() {
    message_ = make_daytime_string();
    auto p = shared_from_this();
    asio::async_write(
        socket_, asio::buffer(message_),
        [p](const asio::error_code &ec, size_t bytes_transferred) {
          p->handle_write(ec, bytes_transferred);
        });
  }

private:
  tcp_connection(asio::io_context &io) : socket_(io) {}

  void handle_write(const asio::error_code & /*ec*/,
                    size_t /*bytes_transferred*/) {}

  tcp::socket socket_;
  std::string message_;
};

class tcp_server {
public:
  tcp_server(asio::io_context &io)
      : io_(io), acceptor_(io, tcp::endpoint(tcp::v4(), 13)) {
    start_accept();
  }

private:
  void start_accept() {
    tcp_connection::pointer new_connection = tcp_connection::create(io_);
    acceptor_.async_accept(new_connection->socket(),
                           [this, new_connection](const asio::error_code &ec) {
                             this->handle_accept(new_connection, ec);
                           });
  }
  void handle_accept(tcp_connection::pointer new_connection,
                     const asio::error_code &ec) {
    if (!ec) {
      new_connection->start();
    }
    start_accept();
  }

  asio::io_context &io_;
  tcp::acceptor acceptor_;
};

int main() {
  try {
    asio::io_context io;
    tcp_server server(io);
    io.run();
  } catch (std::exception &e) {
    std::cout << "Exception: " << e.what();
  }
  return 0;
}
