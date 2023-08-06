#include <AsyncDelay.h>
#include <Adafruit_CircuitPlayground.h>

float midi[127];
int A_four = 440; 
int eflat_major[8] = {63, 65, 67, 68, 70, 72, 73, 75}; 

int buttonA = 4;
int buttonB = 5;
volatile bool buttonFlagA = 0;
volatile bool buttonFlagB = 0;

void generateMIDI()
{
  for (int x = 0; x < 127; ++x)
  {
    midi[x] = (A_four / 32.0) * pow(2.0, ((x - 9.0) / 12.0));
    Serial.println(midi[x]);
  }
}

void melodyA() {
  buttonFlagA = !buttonFlagA;
}

void melodyB() {
  buttonFlagB = !buttonFlagB;
}

int song[12][2] = {
    {60, 400},  
    {63, 200}, 
    {65, 400}, 
    {67, 200},  
    {67, 1000}, 
    {65, 200},  
    {63, 200},
    {65, 800},
    {70, 800},
    {62, 200},
    {60, 200},
    {58, 1000},
  };

void setup() {
  Serial.begin(9600);
  while(!Serial);
  CircuitPlayground.begin();
  generateMIDI(); 
  pinMode(buttonA, INPUT_PULLDOWN);
  pinMode(buttonB, INPUT_PULLDOWN);
  attachInterrupt(digitalPinToInterrupt(buttonA), melodyA, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonB), melodyB, FALLING);
}

void loop() {

  if (buttonA) {
    //ISR changeMelody is called
  }
  if (buttonFlagA) {
  for(int i = 0; i < sizeof(song) / sizeof(song[0]); i++) // Calculate how many rows are in the array using: sizeof(song) / sizeof(song[0])
    {
    CircuitPlayground.playTone(midi[song[i][0]], song[i][1]);
    Serial.println(midi[song[i][0]]);
    delay(1);
    }
    buttonFlagA = 0;
  }
  
  delay(500); 

  if (buttonB) {
    //ISR changeMelody is called
  }
  if (buttonFlagB) {
  int lengthOfEflat = sizeof(eflat_major) / sizeof(int);
  for(int i = 0; i < lengthOfEflat; i++) 
    {
    int randomIndex = random(lengthOfEflat);  
    int randomDur = random(2,8);
    CircuitPlayground.playTone(midi[eflat_major[randomIndex]], randomDur*100); 
    Serial.println(midi[eflat_major[randomIndex]]);
    delay(1);
    }
    buttonFlagB = 0;
  }
  delay(500); 
}
