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
    _percentage = percentage;
    _pwm = map(_percentage, 0, 100, 0, _maxPwmValue);
    analogWrite(_pin, _pwm);
}

void PWMDriver::stop() {
    setSpeed(0);
}

void PWMDriver::on() {
    _on = true;
    stop();
}

void PWMDriver::off() {
    _on = false;
    stop();
}