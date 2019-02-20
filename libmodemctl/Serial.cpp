#include <iostream>
#include <thread>
#include <future>
#include "Serial.h"

std::string Serial::readline(int timeout) {
    std::future<std::string> fut = std::async(std::launch::async, &Serial::_readline, this);
    std::mutex mtx;
    std::unique_lock<std::mutex> lck(mtx);
    while (read_cv.wait_for(lck, std::chrono::seconds(timeout))==std::cv_status::timeout){
        throw std::runtime_error("Timeout");
    }
    return fut.get();
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

std::string Serial::_readline() {
    std::string data;
    char c{};
    std::lock_guard<std::mutex> lk(mutex);
    do {
        port_->read_some(boost::asio::buffer(&c, 1));
        data.push_back(c);
    } while (c != delimiter);
    read_cv.notify_one();
    return data;
}
