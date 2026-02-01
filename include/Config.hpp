// Config.hpp
#ifndef Config_hpp
#define Config_hpp

#include <Arduino.h>
namespace Config {
constexpr uint8_t PWM_RESOLUTION = 12;
constexpr uint32_t PWM_FREQUENCY = 25000;
constexpr uint8_t NUM_TACHO_FANS = 12;
constexpr uint8_t NUM_TACHO_PUMPS = 3;
constexpr uint8_t TACHO_PIN_FANS[NUM_TACHO_FANS] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
constexpr uint8_t TACHO_PIN_PUMPS[NUM_TACHO_PUMPS] = {14, 15, 16};
constexpr uint8_t NUM_FAN_DRIVERS = 1;
constexpr uint8_t NUM_PUMP_DRIVERS = 2;
constexpr uint8_t DRIVER_PIN_FANS[NUM_FAN_DRIVERS] = {17};
constexpr uint8_t DRIVER_PIN_PUMPS[NUM_PUMP_DRIVERS] = {18, 19};

// Tachometer settings
constexpr uint8_t TACHO_PULSES_PER_REV_FAN = 2;
constexpr uint8_t TACHO_PULSES_PER_REV_PUMP = 2;
constexpr uint32_t TACHO_DEBOUNCE_US = 100;         // Microseconds
constexpr uint32_t TACHO_TIMEOUT_US = 500000;      // 0.5 seconds
constexpr float TACHO_US_PER_MINUTE = 60000000.0f;  // For RPM calc

}  // namespace Config
#endif  // Config_hpp