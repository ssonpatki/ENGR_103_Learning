//Use Circuitboard buttons to turn LED on and off

#include <Adafruit_CircuitPlayground.h>

//Initialize buttons to default state/value
bool buttonA = 0;
bool buttonB = 0;
bool slideSwitch = 0;

void logicalAND() {
  buttonA = CircuitPlayground.leftButton();  //reads left button
  buttonB = CircuitPlayground.rightButton(); 
  if (buttonA && buttonB) {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}

void logicalOR() {
  buttonA = CircuitPlayground.leftButton();  //reads left button
  buttonB = CircuitPlayground.rightButton(); 
  if (buttonA || buttonB) {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  CircuitPlayground.begin(); //initalizer function for hardware inside circuit playground
}

//if one button is pressed
void loop() {
  slideSwitch = CircuitPlayground.slideSwitch();
  if (slideSwitch == 1) { // 1 = + = left
    logicalAND();
  } else { // 0 = - = right
    logicalOR();
  }
  delay(10);
}

