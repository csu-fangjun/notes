#include "websocketpp/uri.hpp"
#include <assert.h>
#include <iostream>

static void check_valid_ipv4() {
  std::string s = "10.192.168.1";
  bool b = websocketpp::uri_helper::ipv4_literal(s.begin(), s.end());
  assert(b == true);

  s = "256.192.168.1";
  b = websocketpp::uri_helper::ipv4_literal(s.begin(), s.end());
  assert(b == false);
}

static void check_uri() {
  websocketpp::uri uri("ws://localhost:81");
  assert(uri.str() == "ws://localhost:81/");
  assert(uri.get_valid() == true);
  assert(uri.is_ipv6_literal() == false);
  assert(uri.get_secure() == false);
  assert(uri.get_scheme() == "ws");
  assert(uri.get_host() == "localhost");
  assert(uri.get_port() == 81);
  assert(uri.get_port_str() == "81");
  assert(uri.get_host_port() == "localhost:81");
  assert(uri.get_authority() == "localhost:81");
  assert(uri.get_resource() == "/");
  assert(uri.get_query() == "");
}

static void check_uri2() {
  websocketpp::uri uri("wss://localhost/foo/bar?hello=12");
  assert(uri.str() == "wss://localhost/foo/bar?hello=12");
  assert(uri.get_valid() == true);
  assert(uri.is_ipv6_literal() == false);
  assert(uri.get_secure() == true);
  assert(uri.get_scheme() == "wss");
  assert(uri.get_host() == "localhost");
  assert(uri.get_port() == 443);
  assert(uri.get_port_str() == "443");
  assert(uri.get_host_port() == "localhost");
  assert(uri.get_authority() == "localhost:443");
  assert(uri.get_resource() == "/foo/bar?hello=12");
  assert(uri.get_query() == "hello=12");
}

void test_uri() {
  check_valid_ipv4();
  check_uri();
  check_uri2();
}
