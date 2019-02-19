#pragma once

#include <utility>
#include <string>
#include "Serial.h"
#include <pybind11/pybind11.h>

#define RESP_DEFAULT_TIMEOUT 1000 //1 second timout for response

class ModemResponse {
public:
    ModemResponse(std::vector<std::string> values, bool ok) : values(std::move(values)), command_ok(ok) {};
    std::vector<std::string> values;
    bool command_ok;
};


class ModemInfo {
public:
    std::string manuf_id;
    std::string model_id;
    std::string revision;
    std::string serial_number;
};


class Modem : private Serial {
private:
    ModemResponse send_command(const std::string &cmd);

    ModemResponse get_response();

    std::unique_ptr<ModemInfo> info{new ModemInfo};

    void echo_on(bool on);

    void update_status();


public:
    Modem(const std::string &portname, unsigned int baudrate) : Serial(portname, baudrate) {};

    ~Modem() override = default;

    void send_at();

    std::string get_manuf_id();

    std::string get_model_id();

    std::string get_revision();

    std::string get_serial_number();

    void connect();

    void disconnect();
};

namespace py = pybind11;

PYBIND11_MODULE(Modem, m){
    py::class_<Modem>(m,"Modem")
        .def(py::init<const std::string&, unsigned int>())
        .def("connect", &Modem::connect)
        .def("disconnect", &Modem::disconnect)
        .def("get_manuf_id", &Modem::get_manuf_id)
        .def("get_model_id", &Modem::get_model_id)
        .def("get_revision", &Modem::get_revision)
        .def("get_serial_number", &Modem::get_serial_number);
}