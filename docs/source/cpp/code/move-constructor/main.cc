#include <iostream>

class Foo {
public:
  Foo() { std::cout << "Default constructor foo\n"; }
  Foo(const Foo &) { std::cout << "Copy constructor foo\n"; }
  Foo(Foo &&) { std::cout << "Move constructor foo\n"; }
  ~Foo() { std::cout << "Destructor foo\n"; }

  Foo &operator=(const Foo &) { std::cout << "Copy assignment foo\n"; }
  Foo &operator=(Foo &&) { std::cout << "Move assignment foo\n"; }
};

Foo GetFoo() {
  Foo f;
  return f;
}

class Bar {
public:
  Bar(Foo f) : f_(std::move(f)) {}
  ~Bar() { std::cout << "Destructor bar\n"; }

private:
  Foo f_;
};

class Baz {
public:
  Baz(const Foo &f) : f_(f) {}
  ~Baz() { std::cout << "Destructor baz\n"; }

private:
  Foo f_;
};

int main() {
  Bar b(GetFoo());
  std::cout << "--test baz--\n";
  Baz z(GetFoo());
  std::cout << "--test end--\n";
  return 0;
}
