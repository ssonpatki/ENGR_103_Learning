#include <Adafruit_CircuitPlayground.h>

float tempC, tempF, soundPressure;
float midi[127];
int A_four = 440; 


void setup() {
  Serial.begin(9600);
  generateMIDI();
  CircuitPlayground.begin();
}

void loop() {
  tempC = CircuitPlayground.temperature();
  tempF = CircuitPlayground.temperatureF();
  soundPressure = CircuitPlayground.mic.soundPressureLevel(10);

if (soundPressure < 85) { //
  Serial.println("good sound level");
  Serial.print("tempC: ");
  Serial.print(tempC);
  Serial.print(" tempF: ");
  Serial.println(tempF);
  delay(1000);

  for (int i = 0; i < 10; i++) {
    if (tempF < 68) {
      delay(1);
      Serial.println("temp is chilly");
      CircuitPlayground.setPixelColor(i, 0, 0, 255);
    } else if (68 <= tempF && tempF <= 74) {
      delay(1);
      Serial.print("temp is pleasant");
      CircuitPlayground.setPixelColor(i, 0, 255, 0);
    } else {
      delay(1);
      Serial.println("temp is hot");
      CircuitPlayground.setPixelColor(i, 255, 0, 0);
    } 
  } 

} else {
  Serial.println("too loud");
  blink();
  CircuitPlayground.playTone(60, 400);
  delay(1);
}
delay(100);
}

void generateMIDI()
{
  for (int x = 0; x < 127; ++x)
  {
    midi[x] = (A_four / 32.0) * pow(2.0, ((x - 9.0) / 12.0));
    Serial.println(midi[x]);
  }
}

void blink() {
for (int j = 0; j < 2; j++) {
for (int i = 0; i < 10; i++) {
  CircuitPlayground.setPixelColor(i, 255, 255, 255);
  delay(10);
  }
for (int i = 0; i < 10; i++) {
  CircuitPlayground.setPixelColor(i, 0, 0, 0);
  delay(10);
  }
  delay(1);
}
delay(10);
}

