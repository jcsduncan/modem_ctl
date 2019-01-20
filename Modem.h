#pragma once

#include <utility>
#include <string>
#include "Serial.h"

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

