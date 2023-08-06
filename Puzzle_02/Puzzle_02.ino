// Global Variables are defined here
int longBlink = 1500;
int shortBlink = 500;
int timeBetweenBlinks = 300;
int spaceBetweenLetters = 1000;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  delay(2000);                      // pause before start of code?
  //1st dot for H; H = ....
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(shortBlink);                      // time on for dots
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(timeBetweenBlinks);               // time light off in between blinks
  //2nd dot for H
  digitalWrite(LED_BUILTIN, HIGH);
  delay(shortBlink);
  digitalWrite(LED_BUILTIN, LOW);
  delay(timeBetweenBlinks);
  //3rd dot for H
  digitalWrite(LED_BUILTIN, HIGH);
  delay(shortBlink);
  digitalWrite(LED_BUILTIN, LOW);
  delay(timeBetweenBlinks);
  //4th dot for H
  digitalWrite(LED_BUILTIN, HIGH);
  delay(shortBlink);
  digitalWrite(LED_BUILTIN, LOW);
  delay(spaceBetweenLetters);       // space between letters
  
  //dot for E; E = .
  digitalWrite(LED_BUILTIN, HIGH);
  delay(shortBlink);
  digitalWrite(LED_BUILTIN, LOW);
  delay(spaceBetweenLetters);

  //1st dot for L1; L = .-..
  digitalWrite(LED_BUILTIN, HIGH);
  delay(shortBlink);
  digitalWrite(LED_BUILTIN, LOW);
  delay(timeBetweenBlinks);
  //dash for L1
  digitalWrite(LED_BUILTIN, HIGH);
  delay(longBlink);                      // time on for dashes
  digitalWrite(LED_BUILTIN, LOW);
  delay(timeBetweenBlinks);
  //2nd dot for L1
  digitalWrite(LED_BUILTIN, HIGH);
  delay(shortBlink);
  digitalWrite(LED_BUILTIN, LOW);
  delay(timeBetweenBlinks);
  //3rd dot for L1
  digitalWrite(LED_BUILTIN, HIGH);
  delay(shortBlink);
  digitalWrite(LED_BUILTIN, LOW);
  delay(spaceBetweenLetters);

  //dot for L2
  digitalWrite(LED_BUILTIN, HIGH);
  delay(shortBlink);
  digitalWrite(LED_BUILTIN, LOW);
  delay(timeBetweenBlinks);
  //dash for L2
  digitalWrite(LED_BUILTIN, HIGH);
  delay(longBlink);
  digitalWrite(LED_BUILTIN, LOW);
  delay(timeBetweenBlinks);
  //2nd dot for L2
  digitalWrite(LED_BUILTIN, HIGH);
  delay(shortBlink);
  digitalWrite(LED_BUILTIN, LOW);
  delay(timeBetweenBlinks);
  //3rd dot for L2
  digitalWrite(LED_BUILTIN, HIGH);
  delay(shortBlink);
  digitalWrite(LED_BUILTIN, LOW);
  delay(spaceBetweenLetters);

  //1st dash for O; O = ---
  digitalWrite(LED_BUILTIN, HIGH);
  delay(longBlink);
  digitalWrite(LED_BUILTIN, LOW);
  delay(timeBetweenBlinks);
  //2nd dash for O
  digitalWrite(LED_BUILTIN, HIGH);
  delay(longBlink);
  digitalWrite(LED_BUILTIN, LOW);
  delay(timeBetweenBlinks);
  //3rd dash for O
  digitalWrite(LED_BUILTIN, HIGH);
  delay(longBlink);
  digitalWrite(LED_BUILTIN, LOW);
 
  // end code with delay(2seconds = 2000 in Arduino);
  delay(2000);

}
