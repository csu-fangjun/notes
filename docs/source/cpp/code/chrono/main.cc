// Requires c++14
// g++ -std=c++14 main.cc
#include <assert.h>
#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
#include <thread>
#include <type_traits>
#include <vector>

void test_duration() {
  std::chrono::seconds s(1);
  static_assert(
      std::is_same<decltype(s),
                   std::chrono::duration<long long, std::ratio<1>>>::value,
      "");
  static_assert(sizeof(s) == sizeof(long long), "");

  assert(s.count() == 1);

  std::chrono::milliseconds ms(1);
  static_assert(
      std::is_same<decltype(ms), std::chrono::duration<
                                     long long, std::ratio<1, 1000>>>::value,
      "");

  static_assert(sizeof(ms) == sizeof(long long), "");

  assert(ms.count() == 1);
  ms = s; // implicit cast
  assert(ms.count() == 1000);

  s = std::chrono::duration_cast<std::chrono::seconds>(ms);
  assert(s.count() == 1);

  using namespace std::chrono_literals;
  auto s2 = 10s;
  static_assert(std::is_same<decltype(s), decltype(s2)>::value, "");
  assert(s2.count() == 10);

  ms = s2;
  assert(ms.count() == 1e4);
  ms = ms + s;
  assert(ms.count() == 11000);

  // s = 3; // error
  // std::cout << s << "\n"; // error

  s = 1s;
  ms = 1ms;
  ms = s + ms;
  assert(ms.count() == 1001);
  s = std::chrono::duration_cast<std::chrono::seconds>(ms);
  assert(s.count() == 1);

  ms = 1100ms;
  s = std::chrono::duration_cast<std::chrono::seconds>(ms); // truncated
  assert(s.count() == 1);

  std::chrono::minutes m = 1min;
  s = m;
  assert(s.count() == 60);

  std::chrono::hours h = 1h;
  s = h;
  assert(s.count() == 60 * 60);

  std::chrono::seconds s3; // s3.count() is uninitialized
  // assert(s3.count() == 0); // does not hold
}

void test_time_1() {
  // the resolution of std::time() is in seconds
  std::time_t t = std::time(nullptr);
  t = 1669039051;
  // 16690369051
  // 16690369052
  // 16690369053
  // t is an integer, representing the elapsed seconds since 1970.1.1 00:00 UTC

  // the returned value points to a static allocated memory. Not thread safe.
  // it is overwritten in the next call
  std::tm *tm = std::localtime(&t);

  // 2022-11-21 21:57:31
  printf("%d-%d-%d %d:%d:%d\n", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday,
         tm->tm_hour, tm->tm_min, tm->tm_sec);
  // tm_year, years since 1900
  // tm_mon: months since january (0-11)
  std::vector<std::string> days = {"sunday",    "saturday", "monday", "tuesday",
                                   "wednesday", "thursday", "friday"};
  // tm_wday: days since sunday (0-6)
  printf("weekday: %s, %d\n", days[tm->tm_wday].c_str(), tm->tm_wday);
  // weekday: saturday, 1

  // tm_yday: days since january 1 (0-365)
  printf("day of the year: %d\n", tm->tm_yday);
  // day of the year: 324

  // std::asctime() is not threadsafe
  //
  // Mon Nov 21 21:57:31 2022
  printf("%s\n", std::asctime(tm));

  // Mon Nov 21 13:57:31 2022
  std::tm *gm = std::gmtime(&t); // UTC
  printf("%s\n", std::asctime(gm));

  // Mon Nov 21 21:57:31 2022
  printf("%s\n", std::ctime(&t));
  // std::ctime(&t) == std::asctime(std::localtime(&t))

  // tm is in localtime
  //
  // https://en.cppreference.com/w/cpp/chrono/c/strftime
  {
    char s[100];
    std::strftime(s, sizeof(s), "%Y", tm);
    assert(s == std::string("2022"));
  }

  {
    char s[100];
    std::strftime(s, sizeof(s), "%y", tm);
    assert(s == std::string("22")); // the last 2 digits of the year
  }

  {
    char s[100];
    std::strftime(s, sizeof(s), "%C", tm);
    assert(s == std::string("20")); // the first 2 digits of the year
  }

  {
    char s[100];
    std::strftime(s, sizeof(s), "%b", tm);
    assert(s == std::string("Nov"));
  }

  {
    char s[100];
    std::strftime(s, sizeof(s), "%B", tm);
    assert(s == std::string("November"));
  }

  {
    char s[100];
    std::strftime(s, sizeof(s), "%m", tm);
    assert(s == std::string("11")); // month
  }

  {
    char s[100];
    std::strftime(s, sizeof(s), "%U", tm);
    // week of the year. Sunday is the first day of the week
    assert(s == std::string("47"));
  }

  {
    char s[100];
    std::strftime(s, sizeof(s), "%W", tm);
    // week of the year. Monday is the first day of the week
    assert(s == std::string("47"));
  }

  {
    char s[100];
    std::strftime(s, sizeof(s), "%j", tm);
    // day of the year: 1-366
    assert(s == std::string("325"));
  }

  {
    char s[100];
    std::strftime(s, sizeof(s), "%d", tm);
    // day of the month: 1-31
    assert(s == std::string("21"));
  }
}

void test_time_2() {
  struct std::tm tm {};
  tm.tm_year = 1970 - 1900;
  tm.tm_mon = 0;
  tm.tm_mday = 1;
  tm.tm_sec = 1;
  tm.tm_isdst = 0;
  // Cannot use std::mktime() here since it treats tm as localtime
  // std::time_t t = std::mktime(&tm);

  std::time_t t = timegm(&tm);
  assert(t == 1); // epoch time is 1970, january 1, 00:00:00
}

void test_timepoint() {
  {
    // conversion between timepoint and time_t
    std::time_t t = std::time(nullptr);

    std::chrono::system_clock::time_point tp =
        std::chrono::system_clock::from_time_t(t);

    auto duration = tp.time_since_epoch();
    auto s = std::chrono::duration_cast<std::chrono::seconds>(duration);
    assert(t == s.count());
  }

  {
    std::chrono::system_clock::time_point now =
        std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::time_t t2 = std::time(nullptr);
    assert(t == t2);
  }
}

void test_sleep() {
  std::time_t t = std::time(nullptr);
  // note: std::ctime contains "\n"
  std::cout << "start to sleep at " << std::ctime(&t);
  auto now = std::chrono::steady_clock::now();
  using std::chrono::operator""s;
  std::this_thread::sleep_until(now + 1s);
  t = std::time(nullptr);
  std::cout << "finish sleeping at " << std::ctime(&t);
}

void test_sleep_2() {
  auto start = std::chrono::steady_clock::now();
  using std::chrono::operator""ms;
  // use sleep_until with a timepoint
  std::this_thread::sleep_until(start + 500ms);
  auto end = std::chrono::steady_clock::now();
  std::cout << "finish sleeping at "
            << std::chrono::duration<double, std::milli>(end - start).count()
            << " ms\n";
}

void test_sleep_3() {
  auto start = std::chrono::steady_clock::now();
  using std::chrono::operator""ms;
  // use sleep_for with a duration
  std::this_thread::sleep_for(10ms);
  auto end = std::chrono::steady_clock::now();
  std::cout << "finish sleeping at "
            << std::chrono::duration<double, std::milli>(end - start).count()
            << " ms\n";
}

int main() {
  test_duration();
  test_time_1();
  test_time_2();
  test_timepoint();
  test_sleep();
  test_sleep_2();
  test_sleep_3();
  return 0;
}
