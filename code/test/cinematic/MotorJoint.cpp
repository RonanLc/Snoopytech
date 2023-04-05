#include "MotorJoint.hpp"

/*
Constructor for motor-controlled joint. 
Takes a given ESC pin for the motor control and a pin for the potentiometer influenced by this same motor.
*/
MotorJoint::MotorJoint(uint8_t pin_esc, uint8_t pin_pot, uint16_t min_joint, uint16_t max_joint){
    _pin_esc=pin_esc;
    _pot_mot=pin_pot;
    _min_joint=min_joint;
    _max_joint=max_joint;
};

void MotorJoint::setup_mj(){
    esc_mot.attach(_pin_esc);
};

/*
Returns the current angle of the potentiometer (long).
No parameters.
*/
long MotorJoint::get_angle()
{
    return map(analogRead(_pot_mot),0,1023,_min_angle_pot,_max_angle_pot);
};

/*
Sets all PIDs constants to 0.
No parameters.
*/
void MotorJoint::reset_pid_errors(){
    _error=0;
    _error_sum=0;
    _error_delta=0;
    _previous_error=0;
};

/*
Calculates the normal, integral and derivative errors.
Parameters : setAngle; currentAngle. 
*/
void MotorJoint::calculateErrors(const uint8_t setAngle, uint8_t currentAngle){
    _error=setAngle-currentAngle;
    _error_sum+=_error;
    _error_sum=minMax(_error_sum,-100/_ki,100/_ki); // arbritary floor values
    _error_delta=_error-_previous_error;
    _previous_error=_error;
};

/*
Sets the motor speed (in rps). 
[0-90] => anti-clockwise.
[90-180] => clockwise.
90 => 0 rps.
*/
void MotorJoint::set_speed(uint8_t setSpeed){
    esc_mot.write(setSpeed);
    _current_speed=esc_mot.read();
};

/*
Sets the motor speed to 0 rps.
*/
void MotorJoint::reset_speed(){
    set_speed(_null_speed);
};

/*
Sets an angle as a setpoint.
Determines the motor's speed based on the current angles errors, using PID constants.
Returns TRUE if success.
*/
bool MotorJoint::set_angle(const uint8_t setAngle){
    if ((setAngle > _min_angle_pot)&&(setAngle < _max_angle_pot)){
        _current_angle=get_angle();

        calculateErrors(setAngle,_current_angle);

        long new_speed = _null_speed + (_kp * _error) + (_ki * _error_sum) + (_kd * _error_delta);

        new_speed=minMax(new_speed,_acw_max_speed,_cw_max_speed); // bounds the value 

        set_speed(new_speed);

        return 1;
    }

    return 0;
};

/*
Bounds a value between a minimum value and maximum value.
*/
long MotorJoint::minMax(long value, long min_value, long max_value){
    if (value > max_value){
        value = max_value;
    }
    else if (value < min_value){
        value = min_value;
    }
    return value; 
};