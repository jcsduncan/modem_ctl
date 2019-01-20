#include <iostream>
#include "Modem.h"
#include "Serial.h"

void print(const std::string &resp) {
    std::cout << resp << "\n";
}

int main() {
    Modem modem("/dev/ttyACM3", 115200);
    modem.connect();
    modem.send_at();
    print(modem.get_manuf_id());
    print(modem.get_model_id());
    print(modem.get_revision());
    print(modem.get_serial_number());
    modem.disconnect();
    return 0;
}