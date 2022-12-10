#include "Gyroscope.hpp"

//#define DEBUG           // for debug purpose, uncomment to show prints
#define INTERRUPT_PIN 2 // use pin 2 on Arduino Uno & most boards
#define LED_PIN 13      // (Arduino is 13, Teensy is 11, Teensy++ is 6)

Gyroscope::Gyroscope() {}


/*
The interrupt function.
*/
volatile bool mpuInterrupt = false; // indicates whether MPU interrupt pin has gone high
void dmpDataReady()
{
    mpuInterrupt = true;
}


/*
Gets the gyro ready
*/
void Gyroscope::setup_gyro()
{
// join I2C bus (I2Cdev library doesn't do this automatically)
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    Wire.begin();
    Wire.setClock(400000); // 400kHz I2C clock. Comment this line if having compilation difficulties
#elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
    Fastwire::setup(400, true);
#endif

    // initialize device
    Serial.println(F("Initializing I2C devices..."));
    mpu.initialize();
    pinMode(INTERRUPT_PIN, INPUT);

    // verify connection
    Serial.println(F("Testing device connections..."));
    Serial.println(mpu.testConnection() ? F("MPU6050 connection successful") : F("MPU6050 connection failed"));

    // load and configure the DMP
    Serial.println(F("Initializing DMP..."));
    devStatus = mpu.dmpInitialize();

    // supply your own gyro offsets here, scaled for min sensitivity
    mpu.setXGyroOffset(220);
    mpu.setYGyroOffset(76);
    mpu.setZGyroOffset(-85);
    mpu.setZAccelOffset(1788); // 1688 factory default for my test chip

    if (devStatus == 0)
    {
        // Calibration Time: generate offsets and calibrate our MPU6050
        mpu.CalibrateAccel(6);
        mpu.CalibrateGyro(6);
        mpu.PrintActiveOffsets();
        // turn on the DMP, now that it's ready
        Serial.println(F("Enabling DMP..."));
        mpu.setDMPEnabled(true);

        // enable Arduino interrupt detection
        Serial.print(F("Enabling interrupt detection (Arduino external interrupt "));
        Serial.print(digitalPinToInterrupt(INTERRUPT_PIN));
        Serial.println(F(")..."));
        attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), dmpDataReady, RISING);
        mpuIntStatus = mpu.getIntStatus();

        // set our DMP Ready flag so the main loop() function knows it's okay to use it
        Serial.println(F("DMP ready! Waiting for first interrupt..."));
        dmpReady = true;

        // get expected DMP packet size for later comparison
        packetSize = mpu.dmpGetFIFOPacketSize();
    }
    else
    {
        // ERROR!
        // 1 = initial memory load failed
        // 2 = DMP configuration updates failed
        // (if it's going to break, usually the code will be 1)
        Serial.print(F("DMP Initialization failed (code "));
        Serial.print(devStatus);
        Serial.println(F(")"));
    }
    // configure LED for output
    pinMode(LED_PIN, OUTPUT);
}

/*
Display Euler angles in degrees
*/
void Gyroscope::set_yaw_pitch_roll()
{
    if (!dmpReady) // if programming failed, don't try to do anything
    {
        return;
    }
    if (mpu.dmpGetCurrentFIFOPacket(fifoBuffer))
    {
        mpu.dmpGetQuaternion(&q, fifoBuffer);
        mpu.dmpGetGravity(&gravity, &q);
        mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);

        // // converts Euler angles in degrees
        // ypr[0] *= (180 / M_PI);
        // ypr[1] *= (180 / M_PI);
        // ypr[2] *= (180 / M_PI);

#ifdef DEBUG
        Serial.print("ypr\t");
        Serial.print(ypr[0]);
        Serial.print("\t");
        Serial.print(ypr[1]);
        Serial.print("\t");
        Serial.println(ypr[2]);
#endif
        active();
    }
}

/*
Display real acceleration, adjusted to remove gravity
*/
void Gyroscope::set_real_acceleration()
{

    if (!dmpReady) // if programming failed, don't try to do anything
    {
        return;
    }
    if (mpu.dmpGetCurrentFIFOPacket(fifoBuffer))
    {
        mpu.dmpGetQuaternion(&q, fifoBuffer);
        mpu.dmpGetAccel(&aa, fifoBuffer);
        mpu.dmpGetGravity(&gravity, &q);
        mpu.dmpGetLinearAccel(&aaReal, &aa, &gravity);

#ifdef DEBUG
        Serial.print("areal\t");
        Serial.print(aaReal.x);
        Serial.print("\t");
        Serial.print(aaReal.y);
        Serial.print("\t");
        Serial.println(aaReal.z);

#endif
        active();
    }
}

void Gyroscope::get_yaw_pitch_roll(float container[])
{
    this->set_yaw_pitch_roll();
    for (int i = 0; i < 3; i++)
    {
        container[i] = ypr[i] * 180/M_PI; // converts the Euler angles in degrees
    }
}

void Gyroscope::get_real_acceleration(float container[])
{
    this->set_real_acceleration();
    container[0] = aaReal.x;
    container[1] = aaReal.y;
    container[2] = aaReal.z;
}

/*
Blink LED to indicate activity
*/
void Gyroscope::active()
{
    blinkState = !blinkState;
    digitalWrite(LED_PIN, blinkState);
}
