#include "asio.hpp"
#include <iostream>
#include <thread>

class printer {
public:
  printer(asio::io_context &io)
      : strand_(asio::make_strand(io)), t1_(io, asio::chrono::seconds(1)),
        t2_(io, asio::chrono::seconds(1)) {
    t1_.async_wait(asio::bind_executor(
        strand_, [this](const asio::error_code &e) { print1(e); }));
    t2_.async_wait(asio::bind_executor(
        strand_, [this](const asio::error_code &e) { print2(e); }));
  }

  void print1(const asio::error_code &ec) {
    if (counter_ < 8) {
      std::cout << "print1 id: " << std::this_thread::get_id() << ", counter "
                << counter_ << "\n";
      counter_ += 1;
      t1_.expires_at(t1_.expiry() + asio::chrono::seconds(1));
      t1_.async_wait([this](const asio::error_code &e) { print1(e); });
    }
  }

  void print2(const asio::error_code &ec) {
    if (counter_ < 8) {
      std::cout << "print2 id: " << std::this_thread::get_id() << ", counter "
                << counter_ << "\n";
      counter_ += 1;
      t2_.expires_at(t2_.expiry() + asio::chrono::seconds(1));
      t2_.async_wait([this](const asio::error_code &e) { print2(e); });
    }
  }

private:
  asio::strand<asio::io_context::executor_type> strand_;
  asio::steady_timer t1_;
  asio::steady_timer t2_;
  int counter_ = 0;
};

int main() {
  asio::io_context io;
  printer p(io);
  std::thread t([&io]() { io.run(); }); // NOTE: print1() and print2() can run
                                        // either in t or in the main thread
  io.run();
  t.join();
}
#if 0
(py38) kuangfangjun:code$ ./6-timer-async-thread-with-synchronization
print1 id: 140648598263616, counter 0
print2 id: 140648598263616, counter 1
print1 id: 140648580065024, counter 2
print2 id: 140648598263616, counter 3
print1 id: 140648580065024, counter 4
print2 id: 140648598263616, counter 5
print1 id: 140648580065024, counter 6
print2 id: 140648598263616, counter 7
(py38) kuangfangjun:code$ ./6-timer-async-thread-with-synchronization
print1 id: 139671509145408, counter 0
print2 id: 139671509145408, counter 1
print1 id: 139671490946816, counter 2
print2 id: 139671509145408, counter 3
print1 id: 139671490946816, counter 4
print2 id: 139671509145408, counter 5
print1 id: 139671490946816, counter 6
print2 id: 139671509145408, counter 7
#endif
