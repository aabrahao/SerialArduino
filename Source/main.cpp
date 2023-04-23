#include <iostream>
#include "Serial.h"

int main(int argc, char *argv[]) {
    Serial serial("/dev/ttyACM0");
    std::string cmd;
    while (true) {
        std::cout << "?> ";
        std::getline(std::cin, cmd);
        if (cmd == "bye")
            break;
        serial.write(cmd);
        std::string reply = serial.read();
        std::cout << "arduino> " << reply << std::endl;
    }
    std::cout << "Bye!" << std::endl;
    return 0;
}