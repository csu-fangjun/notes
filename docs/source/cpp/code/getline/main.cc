#include <cassert>
#include <iostream>
#include <sstream>
#include <string>

int main() {
  std::string s = "1,2,3";
  std::stringstream ss(s);
  std::getline(ss, s, ',');
  assert(s == "1");

  std::getline(ss, s, ',');
  assert(s == "2");

  std::getline(ss, s, ',');
  assert(s == "3");
  return 0;
}
