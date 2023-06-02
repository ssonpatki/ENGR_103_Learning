#include <Adafruit_CircuitPlayground.h>

byte switchPin = 7;
volatile bool switchState = 0;
volatile bool switchFlag = 0; 
int randomNumber = random(0, 10);

void onOff() {
  switchFlag = 1;
}

void buttonFlagA() {
  buttonFlagA = !buttonFlagA;
}

void buttonFlagB() {
  buttonFlagB = !buttonFlagB;
}

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  randomSeed(analogRead(0));
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(buttonA, INPUT_PULLDOWN);
  pinMode(buttonB, INPUT_PULLDOWN);
  attachInterrupt(digitalPinToInterrupt(switchPin), onOff, CHANGE);
  attachInterrupt(digitalPinToInterrupt(buttonA), buttonFlagA, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonB), buttonFlagB, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
if (switchFlag) {
  Serial.println("read moisture");
  delay(5);
  switchState = digitalRead(switchPin);
  switchFlag = 0;
 }

if (switchState) {
value = CircuitPlayground.readCap(6);

Serial.print("Capacitence: "); //higher value when moisture

Serial.println(value);
}

}
