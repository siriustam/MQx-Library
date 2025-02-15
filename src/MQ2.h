#ifndef MQ2_h
#define MQ2_h

#include "Arduino.h"

class MQ2 {
private:
  uint8_t analogPin;
  float v_in;
  float v_ran;
  float rl;
  float ro = 830.0;
  float min = 0.0;
  float max = 9999.0;
  float makeRange(float &ppm);

public:
  float ppm;

  MQ2(uint8_t pin, float v_input, float v_range, float rl_mq = 1000.0);
  float getPPM();
};

#endif