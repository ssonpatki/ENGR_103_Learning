//Use Circuitboard buttons and switch to create a stopwatch

#include <AsyncDelay.h>
#include <Adafruit_CircuitPlayground.h>

int buttonA = 4;
int buttonB = 5;
int count = 0;
int switchPin = 7;

volatile bool switchState = 0;
volatile bool buttonFlag = 0;
volatile bool switchFlag = 0; 

AsyncDelay delay_1s; //creates an instance of AsyncDelay Library

void onOff() {
  switchFlag = !switchFlag;
}

void resetCounter() {
  buttonFlag = !buttonFlag;
}

void setup(void) {
  //set up counter
  CircuitPlayground.begin();
  Serial.begin(9600);
  while(!Serial); //!Serial (monitor closed)= !0 = 1 = pause in program; !Serial (monitor open) = !1 = 0 = continue program
  Serial.println("Starting timers");
  delay_1s.start(1000, AsyncDelay::MILLIS); // Start counting

  //use switch
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(buttonA, INPUT_PULLDOWN);
  pinMode(buttonB, INPUT_PULLDOWN);
  attachInterrupt(digitalPinToInterrupt(switchPin), onOff, CHANGE); 
  attachInterrupt(digitalPinToInterrupt(buttonA), resetCounter, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonB), resetCounter, FALLING);
}

void loop(void) {
  if (buttonA || buttonB) {
    //ISR resetCounter is called
  }
  if (buttonFlag) {
    delay(5);
    count = 0;
    Serial.println(count);
    delay_1s.start(1000, AsyncDelay::MILLIS);
    buttonFlag = 0;
  } 
  if (switchPin) {
    //ISR onOff is called
  }
  if (switchFlag) {
    delay(5);
    switchState = digitalRead(switchPin);
    delay_1s.start(1000, AsyncDelay::MILLIS);
    // Serial.print("hello")
    switchFlag = 0; 
  }
  if (delay_1s.isExpired() && !switchState) {
    Serial.print("My counter value is ");
    Serial.println(count++); //adds one to value of count variable
    delay_1s.repeat(); // Count from when the delay expired, not now
  }
  }

