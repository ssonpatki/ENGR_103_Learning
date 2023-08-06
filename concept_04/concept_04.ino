
int pitchSequence[] = {60, 62, 64, 65, 67, 69, 71, 72};
int arrayLength = sizeof(pitchSequence)/sizeof(int);

void setup() {
  // put your setup code here, to run once:
  while(!Serial);
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < arrayLength; i++) {
    Serial.println(pitchSequence[i]);
    delay(1000);
  }
  for (int i = arrayLength - 1; i >= 0; i--) {
    Serial.println(pitchSequence[i]);
    
    delay(1000);
  }
  for (int i = 0; i < 10; i++) {
    int randomNumber = random(0, arrayLength - 1);
    Serial.println(pitchSequence[randomNumber]);
    delay(200);
  }
  delay(500);
}
