# **Worksession 7 - 09/12/2022**

## **Overview** 

This session was centered around the definition of a simple class allowing to use the GY-521. It will be used in the controling of the camera mount printed at the last session.

## **The Gyroscope class**

This class is strongly inspired by the example given by the MPU6050 library and uses many of its functions. 
The main purpose of the Gyroscope class is to make a brief class that regroups all the functions and data needed from the MPU6050 library. 
For instance, our robot doesn't need all the data and function used in the example. We want to be able to access the yaw/pitch/roll of the robot and its real acceleration (gravity-free). 

The Gyroscope class has to setup the GY-521, establish the wanted data and allow us to retrieve this data. 


### **Includes** 

To make our Gyroscope class useful we need the functions that calculate the data we want to use : yaw/pitch/roll and the GY's real acceleration.
These functions are found in the ```MPU6050_6Axis_MotionApps20.h``` class and must be called on ```MPU6050``` objects. 

We also need to include the ```Wire.h``` class to control I2C devices and the ```I2Cdev.h``` to specificly control the GY. 

### **Declarations**

The class implements a ```setup_gyro()``` function which is the function called in the setup of our main program to start the GY-521. What it basically does is initializes the I2C clock, links the I2C devices by taking them out of sleep mode, initializes the DMP and configures the gyroscope's offsets.

This class also packs a ```get_yaw_pitch_roll(float *container)``` function which calculates and store the resultats of the GY's yaw/pitc/roll angle (in degrees) in the ```container``` list. 

A similar function for the GY's real acceleration can be found in the class :```get_real_acceleration(float *container)```.

A small function ```active()``` indicates if the GY-521 is in activity (it makes the builtin led blink). 

### **Results** 

We are now able to create a simple gyroscope object with the basic functions needed for the stability of our robot and camera mount. 

### **Issues encountered** 

When first creating the Gyroscope class, I implemented a constructor that allowed the user to input the desired pin on which to use the GY-521. I encountered issues when troubleshooting since only the pins 2 and 3 can be used for the interrupt. The interrupt comes in handy to start the DMP and know when there is available data. 

## **The CameraMount class**

This class is used to control two servos as one single object. 


### **Includes** 

To avoid all conflicts regarding the Timer1 used by the GY-521, we are using the ```ServoTimer2.h``` class. This class allows us to use upto 8 servos with the Uno. 

One of its main differences with the ```Servo.h``` class is that the ```write()``` functions takes a PWM pulse in microseconds in entry. The values of this entry range from ```750 to 2250```.

### **Declarations** 

Thus, the CameraMount class uses two ```ServoTimer2``` objects.

Its functions are fairly simple. For instance, this class implements a ```setup_cm(uint8_t pin_head, uint8_t pin_foot)``` fucntion that attaches both servos on ```pin_head``` and ```pin_foot```. 
It also presents basic movement functions such as ```move(int deg_x, int deg_y)``` which places the camera mount in a specific position. 

### **Results and issues**

The aim is to get the CameraMount object to compensate the gyroscope's inclination. 
I have tried to implement this class in the main program but have encountered an issue. Indeed, when I try to compile the main program, the terminal indicates that an issue can be found in the ```ServoTimer2.h``` class. However, when I try to compile a main program that only includes the ```ServoTimer2.h``` class, no errors are to be found. The error appears when I include the ```ServoTimer2.h```class through the ```CameraMount.hpp``` class.

I will have to deal this mistake during the next session. 


## **Next session objectives**

During the next session, I will tackle the ```ServoTimer2.h``` issue in the ```CamearaMount.hpp``` class.
I will also continu on the body of the robot and saw the carbon tubes to fit them on the body. 
