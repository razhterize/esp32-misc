#include "Arduino.h"
#include "rotary.h"
// Rotary Variables
Rotary encoder(2, 3, false);

void IRAM_ATTR trigger(){
  encoder.readRotary();
}

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  Serial.printf("Rotary value: %d\n", encoder.counter);
}