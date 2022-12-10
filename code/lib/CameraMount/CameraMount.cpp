#include "CameraMount.hpp"

CameraMount::CameraMount(uint8_t pin_head, uint8_t pin_foot)
{
    this->pin_x = pin_head;
    this->pin_y = pin_foot;
};

/*
Sets up both servo, a x and a foot
*/
void CameraMount::setup_cm()
{
    x.attach(this->pin_x);
    y.attach(this->pin_y);
    this->current[0] = x.read();
    this->current[1] = y.read();

    this->go_to_center();
};

/*
Converts an angle in degrees to a PWN in microseconds (750 to 2250).
The angle must be restrained to [-90;90]°.
-90° = 750 and +90°=2250.
*/
int CameraMount::convert(int deg)
{
    if (deg < -90)
    {
        return min_x;
    }
    if (deg > 90)
    {
        return max_x;
    }
    return map(deg, -90, 90, min_x, max_x);
};

/*
Moves the x axis by an deg angle.
The angle must be restrained to [-90;90]°.
*/
void CameraMount::move_x(int deg)
{
    int pwm_pulse = convert(deg);
    x.write(pwm_pulse);
    this->current[0] = pwm_pulse;
};

/*
Moves the y axis by an deg angle.
The angle must be restrained to [-90;90]°.
*/
void CameraMount::move_y(int deg)
{
    int pwm_pulse = convert(deg);
    y.write(pwm_pulse);
    this->current[1] = pwm_pulse;
};

/*
Controls movement of both x and y axis.
*/
void CameraMount::move(int deg_x, int deg_y)
{
    move_x(deg_x);
    move_y(deg_y);
};

/*
Sends the camera to center state
*/
void CameraMount::go_to_center()
{
    move_x(0);
    move_y(0);
};
