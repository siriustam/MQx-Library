#include "MQ7.h"

MQ7::MQ7(uint8_t pin, float v_input, float v_range, float rl_mq) {
  analogPin = pin;
  v_in = v_input;
  v_ran = v_range;
  rl = rl_mq;
}

float MQ7::getPPM() {
  float analogValue = analogRead(analogPin);
  float vrl = analogValue * (v_in / v_ran);
  float rs = ((v_in * rl) / vrl) - rl;
  ppm = (100 * pow(rs / ro, -1.53)) / 25.0;

  return makeRange(ppm);
}

float MQ7::makeRange(float &ppm) {
  return (ppm < min) ? min : (ppm > max) ? max : ppm;
}
