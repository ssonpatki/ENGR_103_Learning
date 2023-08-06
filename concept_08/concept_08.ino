#include <Adafruit_CircuitPlayground.h>

float soundPressure, brightValue;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() {
  soundPressure = CircuitPlayground.mic.soundPressureLevel(10);

Serial.print("soundPressure= "); Serial.println(soundPressure);

brightValue = map(soundPressure, 45, 95, 2, 225);

if (brightValue < 2) {
  brightValue = 2;
} else if (brightValue > 255) {
  brightValue = 255;
}

Serial.print("brighValue= "); Serial.println(brightValue);

CircuitPlayground.setBrightness(brightValue);

for (int i = 0; i < 10; i++) {
  CircuitPlayground.setPixelColor(i, 150, 150, 150);
  delay(10);
  }

delay(100);
}
