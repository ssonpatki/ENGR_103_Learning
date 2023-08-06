#include <Adafruit_CircuitPlayground.h>
#include <AsyncDelay.h>

AsyncDelay delay_1s;

float tempC, tempF, soundPressure;
float midi[127];
int A_four = 440; 
int value;
int toneValue = 0;

byte switchPin = 7;
volatile bool switchState = 0;
volatile bool switchFlag = 0; 

int randomRed = random(0,256);
int randomGreen = random(0,256);
int randomBlue = random(0,256);

void generateMIDI()
{
  for (int x = 0; x < 127; ++x)
  {
    midi[x] = (A_four / 32.0) * pow(2.0, ((x - 9.0) / 12.0));
    Serial.println(midi[x]);
  }
}

void onOff() {
  switchFlag = 1;
}

int sadSong[30][2] = {
    {127, 200}, 
    {60, 400}, 
    {63, 200}, 
    {65, 400}, 
    {67, 200}, 
    {67, 1400},
    {65, 200}, 
    {63, 200}, 
    {65, 800}, 
    {70, 800}, 
    {62, 200}, 
    {60, 200}, 
    {58, 1400}, 
    {127, 200}, 
    {60, 400}, 
    {63, 200}, 
    {65, 200},
    {67, 200},
    {70, 200},
    {67, 1400},
    {70, 400}, 
    {72, 800}, 
    {70, 200},
    {67, 200}, 
    {65, 1400},
    {63, 200},
    {65, 200},
    {67, 800},
    {70, 800},
    {60, 1600},
  };

int happySong[16][2] = { 
    {74, 200},
    {69, 200}, 
    {74, 200},  
    {76, 200},
    {73, 200}, 
    {69, 200}, 
    {73, 200},
    {74, 200},
    {71, 200},
    {69, 200},
    {69, 200},
    {67, 200},
    {67, 200},
    {66,200},
    {64, 200},
    {62,200},
  };

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


void setup() {
  Serial.begin(9600);
  generateMIDI();
  CircuitPlayground.begin();
  pinMode(switchPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(switchPin), onOff, CHANGE);
  delay_1s.start(1000, AsyncDelay::MILLIS);
}

void loop() {
  // put your main code here, to run repeatedly:
 if (delay_1s.isExpired()) {
// light for temperature
 tempC = CircuitPlayground.temperature();
 tempF = CircuitPlayground.temperatureF();

  Serial.print("tempC: ");
  Serial.print(tempC);
  Serial.print(" tempF: ");
  Serial.println(tempF);
  delay(1000);


if (tempF < 65) {
  delay(1);
  Serial.println("temp is chilly");
  discoBall();
} else if (65 <= tempF && tempF <= 74) {
  delay(1);
  Serial.print("temp is pleasant");
  pastels();
} else {
  delay(1);
  Serial.println("temp is hot");
  counter();
} 
   

// sound for moisture
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

toneValue = map(value, 200, 1020, 0, 127);

if (toneValue < 0) {
  toneValue = 0;
} else if (toneValue > 127) {
  toneValue = 127;
}

if (value < 810) { // not moist
  Serial.println("need water");
  for(int i = 0; i < sizeof(sadSong) / sizeof(sadSong[0]); i++) 
    {
    CircuitPlayground.playTone(midi[sadSong[i][0]], sadSong[i][1]);
    Serial.println(midi[sadSong[i][0]]);
    delay(1);
    }

} else if (value > 1020) { // too moist
  Serial.println("too much water");
  for(int i = 0; i < sizeof(sadSong) / sizeof(sadSong[0]); i++) 
    {
    CircuitPlayground.playTone(midi[sadSong[i][0]], sadSong[i][1]);
    Serial.println(midi[sadSong[i][0]]);
    delay(1);
    }

} else {
  Serial.println("good moisture");
  for(int i = 0; i < sizeof(happySong) / sizeof(happySong[0]); i++) 
    {
    CircuitPlayground.playTone(midi[happySong[i][0]], happySong[i][1]);
    Serial.println(midi[happySong[i][0]]);
    delay(1);
    }
}
}
delay_1s.repeat();
}
delay(500);
}

