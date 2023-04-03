# Worksession 18 - 28/03/2023

## Overview 

During this session, I worked on the body of the robot. 

## Assembling and machining 

The goal of this session was to implement the new potentiometers in the body of the robot. 
I began by soldering cables to these potentiometers. The smooth metal surface of the potentiometer needs to be scratched in order for the soldering to be effective. 
The potentiometers return proper analogic values and their angle range is about [0°-240°] +- 5°. 

I used super glue to attach the potentiometer return the hip angle and put the hip in motion to see the quality of the gear moving the potentiometer.
This can be seen in the following video :

[Link](https://youtube.com/shorts/3UBivNCR2bs?feature=share)

I also glued the key that is plugged in the potentiometer of the shoulder and assembled the {key+potentiometer} in the carbon fiber tube maintening the shoudler.
The result can be seen in the next video :

[Link](https://youtube.com/shorts/v6eRysPjnHw?feature=share)

The carbon fiber tubes had to be drilled in order to attach the socket of the potentiometer.

To reduce the noise emitted by the motor-reducers, I filled them with synthetic grease. 

Once all the motor-reducers were greased, the potentiometers ready to be installed, I proceded to the assembling of the leg. 
This phase took about two hours due to the amount of requiered pieces. The most time consuming task came from all the screwing needed.

The following picture shows the assembled leg, with its new potentiometers :


![IMG_2748](https://user-images.githubusercontent.com/95374519/229298551-f969f0d5-a31c-419e-9af4-661d5702fe18.jpeg)


I then continued with the dissassembing of the body in order to install the leg and link it to its third motor-reducer (the one aboard the body).
The mounted leg can be seen on the floowing pictures :


![unnamed](https://user-images.githubusercontent.com/95374519/229298574-24ccd62c-a3a7-4fdc-9ebe-70ac0e6a0dfc.jpg)

![IMG_2755](https://user-images.githubusercontent.com/95374519/229298581-5a75a940-89dc-4dab-878c-748a0e08575c.jpeg)


## Short motion tests

The following videos show each joint's motion :

[Knee_motion](https://youtu.be/SUaDrIiHGKA)

[Hip_motion](https://youtu.be/5ANu7j0sUI8)

[Shoulder_motion](https://youtu.be/d3nsmIFnhjQ)

As we can see, the knee and the hip joints move freely whereas the shoudler joint struggles
This comes from the belt not being tense enough. 

Furthermore, as seen on the second video, the shoulder structure has been cut and opened by hand near the bearing putting the hip in motion.
It had to be done since I forgot to consider the screw maintening the belt in the bearing while conceiving the shoulder's structure. 
The hole prevents the screw from conflicting with the shoulder shell.

I have resolved this issue by increasing the inner diameter where the screw was conflicting on the shoulder shell 3D file. 

## Next week's objective 

For next week's session, I will attempt to solve the previously mentionned issue.
Once all the issue have been delt with, I will proceed to adjust the offsets for each potentiometer in the ````MotorJoint``` code. 
