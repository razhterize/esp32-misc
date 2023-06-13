#include <Arduino.h>

class Rotary
{
public:
  Rotary(uint8_t CLK_PIN, uint8_t DT_PIN, bool use_interrupt);
  int8_t readRotary();
  uint32_t getCounter();
  void resetCounter();
  void setCounterStep(uint8_t STEP);
  int32_t counter;
};