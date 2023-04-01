# Worksession 18 - 28/03/2023

## Overview 

During this session, I worked on the body of the robot. 

## Assembling and machining 

The goal of this session was to implement the new potentiometers in the body of the robot. 
I began by soldering cables to these potentiometers. The smooth metal surface of the potentiometer needs to be scratched in order for the soldering to be effective. 
The potentiometers return proper analogic values and their angle range is about [0°-240°] +- 5°. 

I used super glue to attach the potentiometer return the hip angle and put the hip in motion to see the quality of the gear moving the potentiometer.
This can be seen in the following video :

[video_pot]()

I also glued the key that is plugged in the potentiometer of the shoulder and assembled the {key+potentiometer} in the carbon fiber tube maintening the shoudler.
The result can be seen in the next video :

[video_pot_shoulder]()

The carbon fiber tubes had to be drilled in order to attach the socket of the potentiometer.

To reduce the noise emitted by the motor-reducers, I filled them with synthetic grease. 

Once all the motor-reducers were greased, the potentiometers ready to be installed, I proceded to the assembling of the leg. 
This phase took about two hours due to the amount of requiered pieces. The most time consuming task came from all the screwing needed.

The following picture shows the assembled leg, with its new potentiometers :

[photo_leg]()

I then continued with the dissassembing of the body in order to install the leg and link it to its third motor-reducer (the one aboard the body).
The mounted leg can be seen on the floowing pictures :

[picture]
[picture]

## Short motion tests

The following videos show each joint's motion :

[Knee_motion]()

[Hip_motion]()

[Shoulder_motion]()

As we can see, the knee and the hip joints move freely whereas the shoudler joint struggles
This comes from the belt not being tense enough. 

Furthermore, as seen on the second video, the shoulder structure has been cut and opened by hand near the bearing putting the hip in motion.
It had to be done since I forgot to consider the screw maintening the belt in the bearing while conceiving the shoulder's structure. 
The hole prevents the screw from conflicting with the shoulder shell.

I have resolved this issue by increasing the inner diameter where the screw was conflicting on the shoulder shell 3D file. 

## Next week's objective 

For next week's session, I will attempt to solve the previously mentionned issue.
Once all the issue have been delt with, I will proceed to adjust the offsets for each potentiometer in the ````MotorJoint``` code. 
