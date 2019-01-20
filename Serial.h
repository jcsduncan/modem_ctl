#include <utility>

//
// Created by dunx on 17/01/19.
//

#ifndef LEARNING_SERIAL_H
#define LEARNING_SERIAL_H

#include <boost/asio/serial_port.hpp>
#include <boost/asio.hpp>
#include <string>
#include <array>
#include <mutex>

class Serial {
    using io_service = boost::asio::io_service;
    using serial_port = boost::shared_ptr<boost::asio::serial_port>;
protected:
    virtual ~Serial() { close(); }; // destructor

    std::mutex mutex;
    io_service io;
    serial_port port_;

    template<typename T>
    size_t write(T data) {
        std::lock_guard<std::mutex> lk(mutex);
        return port_->write_some(boost::asio::buffer(std::string(data)));
    }

    std::string readline();

    void open();

    void close();

public:
    /* Ctor */
    explicit Serial(std::string portname, unsigned int baudrate = 9600, char delim = '\n') : baudrate{baudrate},
                                                                                             com_port_name{std::move(
                                                                                                     portname)},
                                                                                             delimiter{delim} {
        port_ = serial_port(new boost::asio::serial_port(io));
    };

    Serial(const Serial &p) = delete; // Delete copy ctor
    Serial &operator=(const Serial &p) = delete; //Delete copy assignment
    char delimiter;
    std::string com_port_name;
    unsigned int baudrate;
};


#endif //LEARNING_SERIAL_H
