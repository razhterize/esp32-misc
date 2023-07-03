#include "Arduino.h"
#include "MCP4725.h"

MCP4725 dac(0x60);

uint16_t value;

void setup(){
  Serial.begin(115200);
  pinMode(17, INPUT_PULLDOWN);
  pinMode(16, INPUT_PULLDOWN);
  dac.begin();
}

void loop(){
  if (digitalRead(16)){
    if (value < 4095){
      value++;
      delay(10);
    };
  }
  if (digitalRead(17)){
    if (value > 0){
      value--;
      delay(10);
    };
  }
  dac.writeDAC(value);
  Serial.printf("DAC Value: %d\n", value);
}
