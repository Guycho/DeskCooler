// PWMDriver.hpp
#ifndef PWMDriver_hpp
#define PWMDriver_hpp

#include <Arduino.h>

class PWMDriver {
   public:
    PWMDriver(uint8_t pin, float percentage = 0.0f);
    void begin(float percentage);
    void setSpeed(float percentage);
    void stop();
    void on();
    void off();

   private:
    uint8_t _pin;
    uint16_t _pwmFrequency = 25000;
    float _percentage = 0.0f;
    uint16_t _pwm = 0;
    uint16_t _maxPwmValue;
    uint8_t _pwmResolution = 10;
    bool _on = false;
};

#endif  // PWMDriver_hpp