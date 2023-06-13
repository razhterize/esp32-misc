#include "Arduino.h"
#include "rotary.h"

static uint16_t prevNextCode;
static uint16_t store;

int32_t counter = 0;
int8_t step = 1;

uint8_t dt, clk;

Rotary::Rotary(uint8_t CLK_PIN, uint8_t DT_PIN, bool use_interrupt = false)
{
  clk = CLK_PIN;
  dt = DT_PIN;
  pinMode(dt, INPUT);
  pinMode(clk, INPUT);
}

int8_t Rotary::readRotary()
{
  static int8_t encoder_table[16] = {0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0};
  prevNextCode <<= 2;
  if (digitalRead(dt))
    prevNextCode |= 0x02;
  if (digitalRead(clk))
    prevNextCode |= 0x01;
  prevNextCode &= 0x0f;

  int32_t *p_counter = &counter;

  // If valid store as 16-bit data
  if (encoder_table[prevNextCode])
  {
    store <<= 4;
    store |= prevNextCode;
    if ((store & 0xff) == 0x2b)
    {
      *p_counter -= step;
      return -1;
    }
    if ((store & 0xff) == 0x17)
    {
      *p_counter += step;
      return 1;
    }
  }
  return 0;
}

uint32_t Rotary::getCounter()
{
  return counter;
}

void Rotary::resetCounter()
{
  counter = 0;
}

void Rotary::setCounterStep(uint8_t STEP)
{
  step = STEP;
}