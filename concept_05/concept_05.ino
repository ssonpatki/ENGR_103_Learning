#include <Adafruit_CircuitPlayground.h>

void setup() {

  CircuitPlayground.begin();

  // put your setup code here, to run once:

  Serial.begin(9600);

}

void loop() {

  //rainbowCycle(100, 10);
  //confetti(100);
  counter();
  //discoBall();
  //pastels();

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
    CircuitPlayground.setPixelColor(i, fadeIn, 0, 0);
    
    CircuitPlayground.setPixelColor(i++, fadeIn, 0, 0); 
    
    CircuitPlayground.setPixelColor(i+2, fadeIn, 0, 0); 
    }

    for (int fadeOut = 255; fadeOut >= 0; fadeOut--) {
    CircuitPlayground.setPixelColor(i, fadeOut, 0, 0);
   
    CircuitPlayground.setPixelColor(i--, fadeOut, 0, 0); 
   
    CircuitPlayground.setPixelColor(i-2, fadeOut, 0, 0); 
    }

    for (int fadeIn = 0; fadeIn < 256; fadeIn++) {
    CircuitPlayground.setPixelColor(i, 0, fadeIn, 0);
    
    CircuitPlayground.setPixelColor(i++,  0, fadeIn, 0); 
    
    CircuitPlayground.setPixelColor(i+2,  0, fadeIn, 0); 
    }

    for (int fadeOut = 255; fadeOut >= 0; fadeOut--) {
    CircuitPlayground.setPixelColor(i,  0, fadeOut, 0);
   
    CircuitPlayground.setPixelColor(i--, 0, fadeOut, 0); 
  
    CircuitPlayground.setPixelColor(i-2, 0, fadeOut, 0); 
    }

    for (int fadeIn = 0; fadeIn < 256; fadeIn++) {
    CircuitPlayground.setPixelColor(i, 0, 0, fadeIn);
   
    CircuitPlayground.setPixelColor(i++, 0, 0, fadeIn); 
   
    CircuitPlayground.setPixelColor(i+2, 0, 0, fadeIn); 
    }

    for (int fadeOut = 255; fadeOut >= 0; fadeOut--) {
    CircuitPlayground.setPixelColor(i, 0, 0, fadeOut);
  
    CircuitPlayground.setPixelColor(i--, 0, 0, fadeOut); 
    
    CircuitPlayground.setPixelColor(i-2, 0, 0, fadeOut); 
    }
  }
  delay(100);
}

void discoBall() {
  for (int i = 0; i < 10; i++) {
    int pixelNumber = random(0,10);
    int randomRed = random(0,256);
    int randomGreen = random(0,256);
    int randomBlue = random(0,256);
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



