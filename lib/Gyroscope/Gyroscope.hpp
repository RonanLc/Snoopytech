#include "MPU6050_6Axis_MotionApps20.h"

#include "I2Cdev.h"

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#include "Wire.h"
#endif

/*
Gyroscope Class
Contains :
- get_yaw_pitch_roll(container)
- get_real_acceleration(container)

*/
class Gyroscope
{
public:
    Gyroscope(); // sets up the gyro based on default pin 2

    void setup_gyro();            // creates all the objects necesary for the MPU6050 object
    void set_yaw_pitch_roll();    // sets the yaw pitch roll 
    void set_real_acceleration(); // sets the real acceleration

    void get_yaw_pitch_roll(float container[]);    // puts the yaw pitch roll data in the container tab
    void get_real_acceleration(float container[]); // puts the gravity-free acceleration in the container tab

private:
    MPU6050 mpu; // the I2C object used to control the GY-521

    const uint8_t blink_led = 13; // built_in led

    bool blinkState = false;

    // MPU control/status vars
    bool dmpReady = false;  // set true if DMP init was successful
    uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
    uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
    uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
    uint16_t fifoCount;     // count of all bytes currently in FIFO
    uint8_t fifoBuffer[64]; // FIFO storage buffer

    // orientation/motion vars
    Quaternion q;        // [w, x, y, z]         quaternion container
    VectorInt16 aa;      // [x, y, z]            accel sensor measurements
    VectorInt16 aaReal;  // [x, y, z]            gravity-free accel sensor measurements
    VectorInt16 aaWorld; // [x, y, z]            world-frame accel sensor measurements
    VectorFloat gravity; // [x, y, z]            gravity vector
    float euler[3];      // [psi, theta, phi]    Euler angle container
    float ypr[3];        // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector

    // packet structure for InvenSense teapot demo
    uint8_t teapotPacket[14] = {'$', 0x02, 0, 0, 0, 0, 0, 0, 0, 0, 0x00, 0x00, '\r', '\n'};


    void active(); // to indicate the gyro is working
};