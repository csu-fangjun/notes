#include <assert.h>
#include <ratio>

int main() {
  {
    std::ratio<1, 3> r;
    assert(r.num == 1);
    assert(r.den == 3);
  }

  // some predefined constants
  {
    std::pico r;
    assert(r.num == 1);
    assert(r.den == 1e12);
  }

  {
    std::nano r;
    assert(r.num == 1);
    assert(r.den == 1e9);
  }

  {
    std::micro r;
    assert(r.num == 1);
    assert(r.den == 1e6);
  }

  {
    std::milli r;
    assert(r.num == 1);
    assert(r.den == 1e3);
  }

  {
    std::kilo r;
    assert(r.num == 1e3);
    assert(r.den == 1);
  }

  {
    std::mega r;
    assert(r.num == 1e6);
    assert(r.den == 1);
  }

  {
    std::giga r;
    assert(r.num == 1e9);
    assert(r.den == 1);
  }
  return 0;
}
