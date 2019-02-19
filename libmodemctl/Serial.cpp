#include "Serial.h"
#include <iostream>

std::string Serial::readline() {
    std::string data;
    char c{};
    std::lock_guard<std::mutex> lk(mutex);
    do {
        port_->read_some(boost::asio::buffer(&c, 1));
        data.push_back(c);
    } while (c != delimiter);

    return data;
}

void Serial::open() {
    std::lock_guard<std::mutex> lk(mutex);
    port_->open(com_port_name);
    port_->set_option(boost::asio::serial_port_base::baud_rate(baudrate));
}

void Serial::close() {
    std::lock_guard<std::mutex> lk(mutex);
    port_->close();
}
