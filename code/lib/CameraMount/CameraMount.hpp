// we are using the timer2 to avoid all conflicts with timer1
#include "ServoTimer2.h"
#include "Arduino.h"

/*
A class that defines the behaviour of a camera mount.
It uses two servo SG-90.
*/
class CameraMount
{
public:
    CameraMount(uint8_t pin_head, uint8_t pin_foot);

    void setup_cm();

    void move_y(int deg); // x axis
    void move_x(int deg); // y axis
    void move(int deg_x, int deg_y);

    //    void stabilize(int x_aim, int y_aim);     // will use the current state, the aim state gievn by difference with gyro
    void go_to_center();
    int convert(int deg);
    void get_position(int *container);

private:
    ServoTimer2 x;
    ServoTimer2 y;

    uint8_t pin_x;
    uint8_t pin_y;

    // default values for x and y, kind of offsets
    int min_x = 750;
    int mid_x = 1500; // value for which we consider the x at 90°
    int max_x = 2250;

    // int min_y = 750;
    // int mid_y = 1500;
    // int max_y = 2250;

    int current[2]; // containes the mount's current position [x,y] in degrees
    int aim[2];
};