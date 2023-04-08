# Worksession 19 - 04/04/2023

## Overview 

This session was centered around resolving the issues mentionned last week and setting the offsets and limits of each potentiometer.

## Manufacturing

The shoulder shell of the robot's leg had to be changed since the screw maintening the belt in the hip was conflicting with the previous shell.
Once the shell was switched, I put the hip in motion and no conflicts could be noticed. 
I also put the other joints in motion to know if they were operational for the motor servo class ```MotorJoint```.


## Servo parameters

Before applying the [```MotorJoint```]() code on the leg to precisely drive it, parameters have to be set for each joint.
These parameters gather :

    The minimum angle the joint can reach.
    The maximum angle the joint can reach.
    The virtual 0° angle, used has a reference in the kinectic study lead by Ronan.
    The direction to go from the minimum angle to the maximum. Takes the value -1 if the motor has to turn anticlockwise to go from min to max. Takes the value 1 otherwise. 

For each parameter, the motor must be put in motion and by changing the rotation speed we are able to determinate which position for the joint corresponds to which parameter. Obvisouly, the parameters for each leg will depend on its assembly.

I collected all this data and here are the results :

    Knee joint : [min,max]=[26-178]°; ref=170°; direction d=-1.
    Hip joint : [min,max]=[60,160]°; ref=145°; d=-1.
    Shoulder joint : [min,max]=[11,164]°; ref=100°; d=1.

After plugging in these values in the [main]() program, I tested the servo driving class on each joint with the PID correctionnal values (kp=0.75, kd=0.33). 

At first, I tried getting each joint to go from one angle to another slowly. They all succeed without any rebounds or rough movement.
Then, I applied a small resistance (500g) on each joint as it was in motion. Most of the belts ripped off as the motor's speed quickly approached its maximum. 
I didn't forsee this behaviour and thus didn't expect the belt from rippig. 

I will have to change the belts and continue the testing and figure out why belts ripped.

