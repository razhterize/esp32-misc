#include "Arduino.h"

int prevNextCode;
int store;
int counter = 0;

int dt = 5, clk = 21;

int readRotary();

IRAM_ATTR void isr()
{
  counter += readRotary();
}

void setup()
{
  Serial.begin(115200);
  pinMode(dt, INPUT);
  pinMode(clk, INPUT);
  // attachInterrupt(dt, isr, RISING);
  attachInterrupt(clk, isr, RISING);
}

void loop()
{
}
int readRotary()
{
  static int8_t encoder_table[16] = {0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0};
  prevNextCode <<= 2;
  if (digitalRead(dt))
    prevNextCode |= 0x02;
  if (digitalRead(clk))
    prevNextCode |= 0x01;
  prevNextCode &= 0x0f;

  // If valid store as 16-bit data
  if (encoder_table[prevNextCode])
  {
    store <<= 4;
    store |= prevNextCode;
    if ((store & 0xff) == 0x2b)
    {
      return -1;
    }
    if ((store & 0xff) == 0x17)
    {
      return 1;
    }
  }
  return 0;
}