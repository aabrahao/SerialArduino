#include "Command.h"
#include "Gpio.h"

Gpio led(LED_BUILTIN);

void setup() {
  Serial.begin(115200);
}

void loop() {
  static String buffer;
  if (Serial.available() > 0) {
    char c = Serial.read();
    if (c == '\n') {
      buffer = clean(buffer);
      run(buffer);
      buffer = String();
    } else
      buffer += c;
  }
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
  } else if (action == "hello") {
    Serial.print("Hi there!\n");
  } else {
    print("Ops, '");
    print(message);
    println("' command not found!");
    return;
  }
  Serial.print(message + "\n");
}

void move(float vx, float vy) {
  print("Move motor ");
  print(vx);
  print(" ");
  println(vy);
}

void look(float angle) {
  print("Look camera ");
  println(angle);
}
