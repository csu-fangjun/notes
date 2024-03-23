#include <iomanip>
#include <iostream>
#include <sstream>

void TestQuoted() {
  // -std=c+=14
  std::string s = "abc";
  std::ostringstream os;

  // "abc"
  os << std::quoted(s) << "\n";

  std::cout << os.str() << "\n";
}

int main() {
  TestQuoted();
  return 0;
}
