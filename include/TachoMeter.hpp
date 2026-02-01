// TachoMeter.hpp
#ifndef TachoMeter_hpp
#define TachoMeter_hpp

#include <Arduino.h>
#include <Chrono.h>

template<uint8_t PIN>
class TachoMeter {
public:
    TachoMeter(uint8_t pulsesPerRevolution = 1) : _pulsesPerRevolution(pulsesPerRevolution) {}
    
    void begin() {
        pinMode(PIN, INPUT_PULLUP);
        instance = this;
        attachInterrupt(digitalPinToInterrupt(PIN), isr, FALLING);
    }
    
    
private:
    Chrono _chrono;
    float _rpm = 0.0f;
    uint8_t _pulsesPerRevolution;
    static TachoMeter<PIN>* instance;
    
    static void isr() {
        if(instance) instance->handleInterrupt();
    }
    
    void handleInterrupt() {
        _rpm = (60000.0f / _pulsesPerRevolution) / _chrono.elapsed();
        _chrono.restart();
    }
};

template<uint8_t PIN>
TachoMeter<PIN>* TachoMeter<PIN>::instance = nullptr;

#endif
