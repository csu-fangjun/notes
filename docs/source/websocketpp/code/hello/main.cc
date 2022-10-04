#include "websocketpp/client.hpp"
#include "websocketpp/config/asio_no_tls_client.hpp"
#include <iostream>
#include <memory>
#include <string>
#include <thread>

using client = websocketpp::client<websocketpp::config::asio_client>;

class connection_metadata {
public:
  using ptr = std::shared_ptr<connection_metadata>;
  connection_metadata(int32_t id, websocketpp::connection_hdl hdl,
                      std::string uri)
      : m_id(id), m_hdl(hdl), m_status("Connecting"), m_uri(uri),
        m_server("N/A") {}
  void on_open(client *c, websocketpp::connection_hdl hdl) {
    m_status = "Open";
    client::connection_ptr con = c->get_con_from_hdl(hdl);
    m_server = con->get_response_header("Server");
  }

  void on_fail(client *c, websocketpp::connection_hdl hdl) {
    m_status = "Failed";
    client::connection_ptr con = c->get_con_from_hdl(hdl);
    m_server = con->get_response_header("Server");
    m_error_reason = con->get_ec().message();
  }

  friend std::ostream &operator<<(std::ostream &out,
                                  const connection_metadata &data);

private:
  int32_t m_id;
  websocketpp::connection_hdl m_hdl;
  std::string m_status;
  std::string m_uri;
  std::string m_server;
  std::string m_error_reason;
};

std::ostream &operator<<(std::ostream &out, const connection_metadata &data) {
  out << "> URI: " << data.m_uri << "\n"
      << "> Status: " << data.m_status << "> Remote Server: "
      << (data.m_server.empty() ? "None Specified" : data.m_server) << "\n"
      << "> Error/close reason: "
      << (data.m_error_reason.empty() ? "N/A" : data.m_error_reason);
  return out;
}

class websocket_endpoint {
public:
  websocket_endpoint() : m_next_id(0) {
    m_endpoint.clear_access_channels(websocketpp::log::alevel::all);
    m_endpoint.clear_error_channels(websocketpp::log::elevel::all);

    m_endpoint.init_asio();
    m_endpoint.start_perpetual();

    m_thread.reset(new std::thread(&client::run, &m_endpoint));
  }

  int32_t connect(std::string uri) {
    websocketpp::lib::error_code ec;
    client::connection_ptr con = m_endpoint.get_connection(uri, ec);
    if (ec) {
      std::cout << "> Connect initialization error: " << ec.message()
                << std::endl;
      return -1;
    }
    int32_t new_id = m_next_id++;
    connection_metadata::ptr metadata_ptr(
        new connection_metadata(new_id, con->get_handle(), uri));
    m_connection_list[new_id] = metadata_ptr;

    con->set_open_handler(
        [metadata_ptr = metadata_ptr, this](websocketpp::connection_hdl hdl) {
          metadata_ptr->on_open(&m_endpoint, hdl);
        });

    con->set_fail_handler(
        [metadata_ptr = metadata_ptr, this](websocketpp::connection_hdl hdl) {
          metadata_ptr->on_fail(&m_endpoint, hdl);
        });
    m_endpoint.connect(con);

    return new_id;
  }

  connection_metadata::ptr get_metadata(int32_t id) const {
    auto metadata_it = m_connection_list.find(id);
    if (metadata_it == m_connection_list.end()) {
      return connection_metadata::ptr();
    } else {
      return metadata_it->second;
    }
  }

private:
  client m_endpoint;
  std::shared_ptr<std::thread> m_thread;
  std::map<int32_t, connection_metadata::ptr> m_connection_list;
  int32_t m_next_id;
};

void test_uri();

int main() {
  test_uri();
  return 0;

  bool done = false;
  std::string input;
  websocket_endpoint endponit;

  while (true) {
    std::cout << "Enter command: ";
    std::getline(std::cin, input);
    if (input == "quit") {
      done = true;
    } else if (input == "help") {
      std::cout << "\nCommand List:\n"
                << "connect <ws uri>\n"
                << "show <connection_id>\n"
                << "help: Display the help and exit\n"
                << "quit: Exit the program\n"
                << "\n";
    } else if (input.substr(0, 7) == "connect") {
      int32_t id = endponit.connect(input.substr(8));
      if (id != -1) {
        std::cout << "Created connection with id " << id << "\n";
      }
    } else if (input.substr(0, 4) == "show") {
      int32_t id = atoi(input.substr(5).c_str());
      connection_metadata::ptr metadata = endponit.get_metadata(id);
      if (metadata) {
        std::cout << *metadata << std::endl;
      } else {
        std::cout << "Unknown connection id " << id << std::endl;
      }
    } else {
      std::cout << "Unrecognized command\n";
    }
    if (done)
      break;
  }
  return 0;
}
// Use connect ws://websocket-echo.com
// for testing
