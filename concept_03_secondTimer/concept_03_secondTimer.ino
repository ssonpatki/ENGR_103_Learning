//Use AsyncDelay to create a timer

#include <AsyncDelay.h>

AsyncDelay delay_1s;

int count = 0;

void setup(void)
{
  Serial.begin(9600);
  while(!Serial); // Pause program till serial monitor opens
  Serial.println("Starting timers");

  // Start counting
  delay_1s.start(1000, AsyncDelay::MILLIS); // .start is used to set the period of the timer and to start it - MILLIS = milliseconds
}

void loop(void)
{
  if (delay_1s.isExpired()) { //checks to see if the timer has expired
    Serial.println(++count);
    delay_1s.repeat(); // Count from when the delay expired, not now; .repeat rests the timer to run again
  }
}

/* Notes: (++) Arithmetic Increment Operator:
"Pre"-increment: Serial.println(++count); starts counter at 1
"Post"-increment: Serial.println(count++); starts counter at 0
*/
