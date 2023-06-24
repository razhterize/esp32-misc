#include "Arduino.h"
#include "MCP4725.h"
#include "WiFi.h"

MCP4725 dac(0x60);

uint32_t prevMillis = 0;
float v_set, v_current, c_set, c_current;

void setup()
{
  Serial.begin(115200);
  dac.begin();
}

void loop()
{
  for (int x = 0; x < 4096; x++)
  {
    dac.writeDAC(x);
    delay(10);
  }
  for (int x = 4095; x > 0; x--)
  {
    dac.writeDAC(x);
    delay(10);
  }
}