# Worksession 15 - 07/03/2023

## Overview

During this session, my work was focused around the testing of the position control of the knee.

## Code and test complication

The code I wrote during the last session encountered issues while compiling. 
The reason being that the ```ServoTimer2``` library which is used in the ```CameraMount``` class conflicted with the ```Servo``` library used in the ```MotorJoint``` class. 
The conflict underlines that a specific portion of code is used in each library and declares the same objects with the same names (```'servo'``` type ```struct```).
I rearranged the ```CameraMount``` class with the ```Servo``` library to erase the conflict.

Once uploaded, the ```MotorJoint``` class allows us to simply control the angular position of the knee.

However, the PID constants I set (kp=1; ki=0.11; kd=1) were too rough and made the joint turn with to much speed, causing it to oscillate in a instable way.
This resulted by breaking the leg, the knee and the belts.

Fortunetly enough, I am still able to use the broken knee to determinate the PID constants. 
The fact that the knee is damaged allows me to insert the screws maintening the belt in the knee without screwing them.
This means that whenever the knee approachs a border angle (angle mechanically impossible to reach), the screws maintenting the belt pop out of their socket, without damaging the belt nor other componants.
Thus, I will keep this 'scrapy' configuration to try out my PID constants since it will prevent extra damage.

## PD settings

The research of the PD settings (Integral constant being useless) can be done with the ```Ziegler-Nichols Method```. 
I am using this method since we lack too many informations about the motor and can't get a hand on a datasheet.

For the first step of the experiment, I need to set the derivative constant to 0 and the proportionnal constant to an abritrary value (kp=1). 
The next step is to turn make the motor move and observe its behavior. 
The first two steps must be repeted and the proportionnal constant must be increased at each repetition. 

The aim is to obtain a ```kp``` for which the motor oscillates as much as possible whilst being stable (no issues). 

The following list relates the different kp constants and their results : 

    kp=1 => the motor slightly overflows (<5°) but remains stable.
    kp=1.5 => the motor overflows (>15°) but remains stable.
    kp=2 => the motor overflows (>30°) and oscillates in a stable way.
    kp=2.5 => the motor oscillates longly but remains stable.
    kp=2.7 => the motor oscillates but the rotation speed increases leading to an unstable system. 
    kp=3 => the motor oscillates and overflows too much and breaks. The system is unstable.

The value that seems to fit the condition for the Ziegler-Nichols method (highest stable oscllations) is ```kp=2.5```. 
This value is called 'critical kp' or ```ku```. 
The proportionnal constant we should therefore use for the knee is ```kp=0.8*ku=2```. 
The derivative constant is given by ```kd=tu/8``` where ```tu``` is the period of the oscillations when ```kp=ku=2.5```.

I used Excel to plot the graph of the position values fo the potentiometer and to visualize the time period.

Here is the excel graph of the motor's position : 

[excel_graph]

The abscissa of the plot is the number of value read in the serial monitor.
On the plot, the two red marks are used to determinate the time period of an oscillation.
The first mark's coordinates are ```(205,193)``` whereas the second mark's coordinates are ```(288,200)```. 
Therefore, we can approximate the amount of values per period by about ```N=288-205=83```. 

I then need to determine the amount of bits the monitor prints per second.
The code communicates with the ```Serial monitor``` at a rate of 9600 bits/second.
The code prints three values : two blank strings (2 * 3-bits) and the position value (long 32-bit).
Therefore, the codes prints 38-bits worth of data per second, which, with the current Baud rate, translates about 9600/38 = 252 value per second.

We can read on the plot that a period contains around ```83``` values, thus represents about ```0.33 seconds```. 

With this reasoning, we can approximate the ```oscillation time period``` to about ```tu=0.33 seconds```.

Finally, the proper derivative value is ```kd=tu/8=0.041 s^-1```. 

I have tried implementing these values in the code of the motor but on the first test the potentiometer inside the knee was displaced and now returns 
extrem values when the motor turns (the potentiomter goes from 200° to 0° when the knee is moved by 1°).

The new potentiometers will hopefully be more reliable than the actual ones we are dealing with. 

## Miscelleanous 

The following video shows the first servo test (kp=1;kd=0) :
[Lien 1](https://youtube.com/shorts/CIPsLTu-o4s?feature=share)

The following video shows another servo test (kp=2.5;kd=0) :
[Lien 2](https://youtube.com/shorts/CIPsLTu-o4s?feature=share)
The following video shows another servo test (kp=3;kd=0) :
[Lien 3](https://youtube.com/shorts/zfZmmV3m1gE?feature=share)

## Next week's objective 

For next week's session, I will start building the body and preparing of the components for the robot's body. I will also pursue the servo tests.