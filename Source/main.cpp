#include <iostream>
#include "Serial.h"

class Reinterpretor {
public:
    void operator()(const std::string &message) const {
        std::cout << "arduino reinterpreted>" << message << std::endl;
    }
};

int main(int argc, char *argv[]) {
    Serial serial("/dev/ttyACM0");
    std::string cmd;
    while (true) {
        std::cout << "?> ";
        std::getline(std::cin, cmd);
        if (cmd == "bye")
            break;
        serial.write(cmd);
    }
    std::cout << "Bye!" << std::endl;
    return 0;
}