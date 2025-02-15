#ifndef MQ7_h
#define MQ7_h

#include "Arduino.h"

class MQ7 {
private:
  uint8_t analogPin;
  float v_in;
  float v_ran;
  float rl;
  float ro = 830.0;
  float min = 0.00;
  float max = 9.99;
  float makeRange(float &ppm);

public:
  float ppm;

  MQ7(uint8_t pin, float v_input, float v_range, float rl_mq = 10000.0);
  float getPPM();
};

#endif