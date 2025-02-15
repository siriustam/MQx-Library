#include "MQ2.h"

MQ2::MQ2(uint8_t pin, float v_input, float v_range, float rl_mq) {
  analogPin = pin;
  v_in = v_input;
  v_ran = v_range;
  rl = rl_mq;
}

float MQ2::getPPM() {
  float analogValue = analogRead(analogPin);
  float vrl = analogValue * (v_in / v_ran);
  float rs = ((v_in * rl) / vrl) - rl;
  ppm = 110 * pow(rs / ro, -1.53);

  return makeRange(ppm);
}

float MQ2::makeRange(float &ppm) {
  return (ppm < min) ? min : (ppm > max) ? max : ppm;
}
