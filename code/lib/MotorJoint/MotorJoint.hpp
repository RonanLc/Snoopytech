// ServoTimer2 implementation 
#ifndef SERVO2_IMPLEMENTATION
#define SERVO2_IMPLEMENTATION
#include "ServoTimer2.h"
#endif

// Arduino implementation
#ifndef ARDUINO_IMPLEMENTATION
#define ARDUINO_IMPLEMENTATION
#include "Arduino.h"
#endif

/*
A class that defines the behaviour of a motor paired to a potentiometer.
It uses a servo (to drive the brushless motor) and a potentiometer.
*/
class MotorJoint
{
public :
    MotorJoint(uint8_t pin_esc, uint8_t pin_pot);

    void setup_mj();

    long get_angle();

    bool set_angle(const uint8_t setAngle);
    void set_speed(uint8_t setSpeed);
    void reset_speed();

    void calculateErrors(const uint8_t setAgnle, uint8_t currentAgnle);
    void reset_pid_errors();

    long minMax(long value, long min_value, long max_value);



private :
    uint8_t _pin_esc;
    ServoTimer2 esc_mot;
    uint8_t _pot_mot;


    // motor's extrem speed in rps
    const uint8_t _acw_max_speed = 0; // Anti-clockwise direction
    const uint8_t _null_speed = 90; // Null speed
    const uint8_t _cw_max_speed = 180; // Clockwise direction

    // potentiometer's extrem angles in °
    const uint8_t _min_angle_pot = 0;
    const uint8_t _max_angle_pot = 245;

    uint8_t _current_angle;
    uint8_t _current_speed;

    // pid correctional constants
    const uint8_t _kp = 1; // proportional constant 
    const uint8_t _ki = 0.11; // integral constant in seconds 
    const uint8_t _kd = 1; // derivative constant in seconds 

    // pid errors
    int _error=0;
    int _error_sum=0;
    int _error_delta=0;
    int _previous_error=0;
    
};