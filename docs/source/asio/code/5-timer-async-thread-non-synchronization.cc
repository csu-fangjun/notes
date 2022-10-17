#include "asio.hpp"
#include <iostream>
#include <thread>

class printer {
public:
  printer(asio::io_context &io)
      : t1_(io, asio::chrono::seconds(1)), t2_(io, asio::chrono::seconds(1)) {
    t1_.async_wait([this](const asio::error_code &e) { print1(e); });
    t2_.async_wait([this](const asio::error_code &e) { print2(e); });
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
(py38) kuangfangjun:code$ ./5-timer-async-thread-non-synchronization
print1 id: print2 id: 140164266059584, counter 0
140164247860992, counter 1
print1 id: 140164266059584, counter 2
print2 id: 140164247860992, counter 3
print1 id: 140164266059584, counter 4
print2 id: 140164247860992, counter 5
print1 id: 140164266059584, counter 6
print2 id: 140164247860992, counter 7
(py38) kuangfangjun:code$ ./5-timer-async-thread-non-synchronization
print2 id: print1 id: 140191018206976, counter 140191036405568, counter 0
0
print1 id: 140191018206976, counter print2 id: 2
140191036405568, counter 3
print1 id: 140191018206976, counter 4
print2 id: 140191036405568, counter 5
print1 id: 140191018206976, counter 6
print2 id: 140191036405568, counter 7
#endif
