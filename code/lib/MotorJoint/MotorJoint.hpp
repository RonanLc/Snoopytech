// ServoTimer2 implementation 
#ifndef SERVO_IMPLEMENTATION
#define SERVO_IMPLEMENTATION
#include <Servo.h>
#endif

// Arduino implementation
#ifndef ARDUINO_IMPLEMENTATION
#define ARDUINO_IMPLEMENTATION
#include <Arduino.h>
#endif

/*
A class that defines the behaviour of a motor paired to a potentiometer.
It uses a servo (to drive the brushless motor) and a potentiometer.
*/
class MotorJoint
{
public :
    MotorJoint(int pin_esc, uint16_t pin_pot, uint16_t min_joint, uint16_t max_joint);

    void setup_mj();

    long get_angle();
    int get_speed();

    bool set_angle(const uint16_t setAngle);
    void set_speed(uint16_t setSpeed);
    void reset_speed();

    void calculateErrors(uint16_t setAgnle, uint16_t currentAgnle);
    void reset_pid_errors();

    long minMax(long value, long min_value, long max_value);



private :
    int _pin_esc;
    Servo esc_mot;
    uint16_t _pot_mot;


    // motor's extrem speed in rps
    const uint16_t _acw_max_speed = 0; // Anti-clockwise direction
    const uint16_t _null_speed = 90; // Null speed
    const uint16_t _cw_max_speed = 180; // Clockwise direction

    // potentiometer's extrem angles in °
    const uint16_t _min_angle_pot = 0;
    const uint16_t _max_angle_pot = 300;

    // usable range for the joint, in °
    uint16_t _min_joint;
    uint16_t _max_joint;

    uint16_t _current_angle;
    uint16_t _current_speed;

    // pid correctional constants
    const float _kp = 0.75; // proportional constant 
    //const uint16_t _ki = 0.11; // integral constant in seconds 
    const float _kd = 0.33; // derivative constant in seconds 

    // pid errors
    int _error=0;
    int _error_sum=0;
    int _error_delta=0;
    int _previous_error=0;
    
};