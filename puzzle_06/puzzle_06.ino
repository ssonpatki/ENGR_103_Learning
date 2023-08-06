#include <Adafruit_CircuitPlayground.h>

byte buttonA = 4;
byte buttonB = 5;
byte switchPin = 7;

volatile bool buttonFlagA = 0;
volatile bool buttonFlagB = 0; 
volatile bool switchState = 0;
volatile bool switchFlag = 0; 
volatile int modeControl = 0;
volatile int m = 0;

int randomRed = random(0,256);
int randomGreen = random(0,256);
int randomBlue = random(0,256);

void setup() {
  CircuitPlayground.begin();
  Serial.begin(9600);
  randomSeed(analogRead(0)); // Seed the random, randomly
  pinMode(buttonA, INPUT_PULLDOWN);
  pinMode(buttonB, INPUT_PULLDOWN);
  pinMode(switchPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonA), ISRa, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonB), ISRb, FALLING);
  attachInterrupt(digitalPinToInterrupt(switchPin), onOff, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (switchFlag) {
  Serial.println("lights switch");
  delay(5);
  switchState = digitalRead(switchPin);
  switchFlag = 0;
 }
 if (buttonFlagA) {
   modeControl = ++m;
   Serial.println("modeControl+1");
   delay(5);
   if (modeControl > 5) {
     m = 0;
     Serial.println("back to beginning");
   }
   buttonFlagA = 0;
 }
 if (buttonFlagB) {
   modeControl = --m;
   Serial.println("modeControl-1");
   delay(5);
   if (modeControl < 0) {
     m = 5;
     Serial.println("back to end");
   }
   buttonFlagB = 0;
 }
 if (switchState) {
   switch(modeControl) { 
     case 0:
      CircuitPlayground.clearPixels();
      break;
     case 1: //takes two button presses to get to case 1
      rainbowCycle(100,10);
      break;
     case 2:
      confetti(50);
      break;
     case 3:
      counter();
      break;
     case 4:
      discoBall();
      break;
     case 5:
      pastels();
      break;
     default:
      break;
    }
 } else { 
    CircuitPlayground.clearPixels();
  } 
}

void ISRa() {
  buttonFlagA = 1;
}

void ISRb() {
  buttonFlagB = 1;
}

void onOff() {
  switchFlag = 1;
}

void rainbowCycle(int currentSpeed, int stripLen) {
  uint32_t offset = millis() / currentSpeed;
  for(int i=0; i<10; ++i) {
    CircuitPlayground.setPixelColor(i, CircuitPlayground.colorWheel(((i * 256 / stripLen) + offset) & 255));
  }
}

void confetti (int LEDTime) {
  int timeOnOff = LEDTime/2;
  int randomLED = random(0,10);
  int randomColorR = random(0,150);
  int randomColorG = random(0,150);
  int randomColorB = random(0,150);
  CircuitPlayground.setPixelColor(randomLED, randomColorR, randomColorG, randomColorB);
  delay(timeOnOff);
  CircuitPlayground.setPixelColor(randomLED, 0,   0,   0);
  delay(timeOnOff);
} 

void counter() {
  for (int i = -2; i <= 10; i++) { 
    for (int fadeIn = 0; fadeIn < 256; fadeIn++) {
    CircuitPlayground.setPixelColor(i, fadeIn, randomGreen, randomBlue);
    
    CircuitPlayground.setPixelColor(i++, fadeIn, randomGreen, randomBlue); 
    
    CircuitPlayground.setPixelColor(i+2, fadeIn, randomGreen, randomBlue); 
    }

    for (int fadeOut = 255; fadeOut >= 0; fadeOut--) {
    CircuitPlayground.setPixelColor(i, fadeOut, randomGreen, randomBlue);
   
    CircuitPlayground.setPixelColor(i--, fadeOut, randomGreen, randomBlue); 
   
    CircuitPlayground.setPixelColor(i-2, fadeOut, randomGreen, randomBlue); 
    }
  }
}

void discoBall() {
  for (int i = 0; i < 10; i++) {
    int pixelNumber = random(0,10);
    CircuitPlayground.setPixelColor(pixelNumber, randomRed, randomGreen, randomBlue);
    CircuitPlayground.setPixelColor(pixelNumber+2, randomRed, randomGreen, randomBlue); 
    CircuitPlayground.setPixelColor(pixelNumber+4, randomRed, randomGreen, randomBlue); 
    delay(1);
    CircuitPlayground.setPixelColor(pixelNumber, 0, 0, 0);
    CircuitPlayground.setPixelColor(pixelNumber+2, 0, 0, 0); 
    CircuitPlayground.setPixelColor(pixelNumber+4, 0, 0, 0); 
    }
}

int pastelColor[8][3] = {
  {255,102,102},
  {255,178,102},
  {255,255,102},
  {102,255,178},
  {102,178,255},
  {102,102,255},
  {178,102,255},
  {255,102,178},
};

void pastels() {
for (int pixelNumber = 0; pixelNumber < 10; pixelNumber++) {
  for (int i = 0; i < sizeof(pastelColor)/sizeof(pastelColor[0]); i++) {
   CircuitPlayground.setPixelColor(pixelNumber, pastelColor[i][0], pastelColor[i][1], pastelColor[i][2]);
   delay(100);
   CircuitPlayground.setPixelColor(pixelNumber, 0, 0, 0);
  }
}
delay(100);
}

