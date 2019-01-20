//
// Created by dunx on 19/01/19.
//

#include <ctime>
#include <future>
#include <thread>
#include "Modem.h"
#include "at_commands.h"
#include "utils.h"

void Modem::send_at() {
    send_command(CMD_AT);
}

ModemResponse Modem::get_response() {
    /*Todo: implement timeout*/
    std::vector<std::string> responses;
    std::string line;
    while (true) {
        line = rtrim(readline());
        if (!line.empty()) {
            if (line == RESP_OK) {
                return ModemResponse(responses, !(line == RESP_OK));
            } else if (line == RESP_ERROR) {
                /*Todo: Custom exception. Parse extended modem errors */
                throw (std::runtime_error("Command Error"));
            } else {
                responses.push_back(line);
            }

        }
    }
}

void Modem::echo_on(bool on) {
    send_command(on ? CMD_ATE_ON : CMD_ATE_OFF);
}

ModemResponse Modem::send_command(const std::string &cmd) {
    write(cmd);
    return get_response();
}

std::string Modem::get_manuf_id() {
    return info->manuf_id;
}

std::string Modem::get_model_id() {
    return info->model_id;
}

std::string Modem::get_revision() {
    return info->revision;
}

std::string Modem::get_serial_number() {
    return info->serial_number;
}

void Modem::connect() {
    open();
    echo_on(false);
    info->manuf_id = send_command(CMD_CGMI).values[0];
    info->model_id = send_command(CMD_CGMM).values[0];
    info->revision = send_command(CMD_CGMR).values[0];
    info->serial_number = send_command(CMD_CGSN).values[0];
}

void Modem::disconnect() {
    close();
}

void Modem::update_status() {

}

