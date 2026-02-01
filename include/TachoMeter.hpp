// TachoMeter.hpp
#ifndef TachoMeter_hpp
#define TachoMeter_hpp

#include <Arduino.h>
#include "Config.hpp"

template<uint8_t PIN>
class TachoMeter {
public:
    TachoMeter(uint8_t pulsesPerRevolution = Config::TACHO_PULSES_PER_REV_FAN) 
        : _pulsesPerRevolution(pulsesPerRevolution) {}
    
    ~TachoMeter() {
        detachInterrupt(digitalPinToInterrupt(PIN));
        if (instance == this) instance = nullptr;
    }
    
    void begin() {
        pinMode(PIN, INPUT_PULLUP);
        instance = this;
        attachInterrupt(digitalPinToInterrupt(PIN), isr, FALLING);
        _lastPulseTime = micros();
    }
    
    float getRPM() const {
        uint32_t elapsed = micros() - _lastPulseTime;
        if (elapsed > 2000000) {  // 2 second timeout
            return 0.0f;
        }
        return _rpm;
    }
    
private:
    uint8_t _pulsesPerRevolution;
    volatile float _rpm = 0.0f;
    volatile uint32_t _lastPulseTime = 0;
    
    static TachoMeter<PIN>* instance;
    
    static void isr() {
        if (instance) instance->handleInterrupt();
    }
    
    void handleInterrupt() {
        uint32_t now = micros();
        uint32_t elapsed = now - _lastPulseTime;
        
        if (elapsed > 1000) {  // Debounce: ignore pulses < 1ms apart
            _rpm = (60000000.0f / _pulsesPerRevolution) / elapsed;
            _lastPulseTime = now;
        }
    }
};

template<uint8_t PIN>
TachoMeter<PIN>* TachoMeter<PIN>::instance = nullptr;

#endif