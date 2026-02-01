// PWMDriver.cpp
#include "PWMDriver.hpp"

PWMDriver::PWMDriver(uint8_t pin, float percentage) : _pin(pin), _percentage(percentage) {}

void PWMDriver::begin(float percentage) {
    pinMode(_pin, OUTPUT);
    analogWriteFrequency(_pin, _pwmFrequency);
    analogWriteResolution(_pwmResolution);
    _maxPwmValue = pow(2, _pwmResolution) - 1;
    setSpeed(_percentage);
}

void PWMDriver::setSpeed(float percentage) {
    _percentage = constrain(percentage, 0.0f, 100.0f);
    _pwm = (_percentage / 100.0f) * _maxPwmValue;
    analogWrite(_pin, _pwm);
}