#include "SerialPort.h"
#include "Gpio.h"

void run(const String &message);

SerialPort port(115200, run);
Gpio led(LED_BUILTIN);

void setup() {
  port.setup();
  led.setup();
}

void loop() {
  port.update();
}

void run(const String &message) {
  auto action = command(message);
  if (action == "move") {
    float vx = argument(message, 1);
    float vy = argument(message, 2);
    move(vx, vy);
  } else if (action == "halt") {
    move(0, 0);
  } else if (action == "look") {
    float angle = argument(message, 1);
    look(angle);
  } else if (action == "on") {
    led.on();
  } else if (action == "off") {
    led.off();
  } else if (action == "hi") {
    port.send("Hi there!");
  } else {
    port.send("Ops, '" + message + "' command not found!");
  }
}

void move(float vx, float vy) {
  
}

void look(float angle) {
  
}
