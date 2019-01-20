#include <utility>

//
// Created by dunx on 19/01/19.
//

#ifndef LEARNING_MODEM_H
#define LEARNING_MODEM_H

#include <string>
#include "Serial.h"

#define RESP_DEFAULT_TIMEOUT 1000 //1 second timout for response

class ModemResponse {
public:
    ModemResponse(std::vector<std::string> values, bool ok) : values(std::move(values)), command_ok(ok) {};
    std::vector<std::string> values;
    bool command_ok;
};


typedef struct modem_info {
    std::string manuf_id;
    std::string model_id;
    std::string revision;
    std::string serial_number;
} modem_info;


class Modem : private Serial {
private:
    ModemResponse send_command(const std::string &cmd);

    ModemResponse get_response();

    std::unique_ptr<modem_info> info{new modem_info};

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


#endif //LEARNING_MODEM_H
