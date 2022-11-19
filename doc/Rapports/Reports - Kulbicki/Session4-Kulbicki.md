# Worksession 4 - 15/11

This worksession was centered around the gyro sensor GY-521 and reajustments of the body of our robot. 

## **GY-521, gyro sensor**

### **Description**

The GY-521 sensor features a 3-axis gyroscope, a 3-axis accelerometer, a digital motion processor (DMP) and a temperature sensor. The DMP is used to process algorithms directly on the board. 

The GY-521 pin layout presents itself like this:

    VCC : 5V (recommended)
    GND
    SCL and SDA : Serial Clock/Data Line
    XCL and XDA : The sensor can act as the master of another sensor
    AD0 : changes the I2C adress of the board (LOW for 0x68; HIGH for 0x69)
    INT : interrupt digital output

The GY-521 uses an I2C Serial data bus to retrieve the raw sensor values. 

Most of the tutorials I found about this sensor don't use the DMP to process the raw values, given by the sensors, to stable position data. 

We want to be able to know rather precisely the yaw, pitch and roll of our robot. These informations can't be directly deduced from the raw data the GY-521 produces.

### **The I2Cdev and MPU6050 libraries**

To overcome the inaccuracy of the raw data, a github user (Jeff Rowberg) published a library allowing to retrieve stable and usable data from the GY-521. 

The code he wrote uses two libraries : [I2CDev](https://github.com/jrowberg/i2cdevlib/tree/master/Arduino/I2Cdev) and [MPU6050](https://github.com/jrowberg/i2cdevlib/tree/master/Arduino/MPU6050).

The I2CDev library basically provides a more intuitive interface of the I2C devices and reduces the memory requirement when multiple I2C devices are used. 

The MPU6050 class provides a full coverage of the GY-521 functionalities and convenient functions to access specific informations about the sensor. 
It uses the on-board DMP to lighten calculations.

### **Test**

I ran a few tests using the examples given with these libraries and the results are intersting. The code from the sketch [MPU6050_DMP6]() returns the yaw, pitch and roll of the sensor (in degrees); the acceleration can be given gravity-free or not. 

Initial condition :

![IMG_2100](https://user-images.githubusercontent.com/95374519/202851304-9c7775ee-f5f1-4270-90ee-5951ae7b5909.jpg)

Output : 

![Capture d’écran 2022-11-19 130050](https://user-images.githubusercontent.com/95374519/202851163-7997a3f1-e536-4d92-9c96-bd1a9986d14f.png)


90° roll rotation :

![IMG_2101](https://user-images.githubusercontent.com/95374519/202851306-81b7165a-b39e-46d8-9bbf-c7ecc2c91bdd.jpg)

Output :

![Capture d’écran 2022-11-19 130132](https://user-images.githubusercontent.com/95374519/202851395-5d904215-9968-4b21-be04-c910323e7bc4.png)

The fact that the code is modular makes it easy to access the wanted informations. 

Although the code is very interesting, the sketch and imports take up 16000 bytes of the Uno's memory (around 50%). I will content myself with this code for the moment, but might seek to extract only the necessary code (access to rotation details and acceleration).

## **Modeling ajustments**

### **Spacers**

The non-printed / non-cut parts such as the spacers have a set size that the printed / cut pieces need to adapt to. I modeled the body using fictional spacers which hight I set to 86mm. The closest spacers available in the FabLab have a height of 85mm. Thus, I reajusted some parts to conform to the real spacers. 

### **Jetson Nano and Uno**

Holes had to be added to the body to receive the Jetson and the Uno. An additional hole was pierced in the vertical side of the body to allow connections to the Jetson during the prototyping.
Both cards have been added to the body, using 7mm spacers (available in the FabLab).
