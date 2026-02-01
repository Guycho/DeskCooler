// PWMDriver.hpp
#ifndef PWMDriver_hpp
#define PWMDriver_hpp

#include <Arduino.h>
#include "Config.hpp"
class PWMDriver {
   public:
    PWMDriver(uint8_t pin, float percentage = 0.0f);
    void begin(float percentage);
    void setSpeed(float percentage);

   private:
    uint8_t _pin;
    uint16_t _pwmFrequency = Config::PWM_FREQUENCY;
    float _percentage = 0.0f;
    uint16_t _pwm = 0;
    uint16_t _maxPwmValue;
    uint8_t _pwmResolution = Config::PWM_RESOLUTION;
    bool _on = false;
};

#endif  // PWMDriver_hpp