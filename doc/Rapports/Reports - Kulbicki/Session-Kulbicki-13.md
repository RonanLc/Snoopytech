# Worksession 13 - 14/02

## Overview 

This session was centered around the building of one leg of our robot. 

## Machining 

The objective of this session was to obtain a functionnal leg before the end of the session.
Since the leg is composed of many objects requiring attention and time, my teammate Ronan and I divided the machining tasks of the leg.
We had already prepared many pieces before the session started :
- two sets of motor-reducer
- two shoulder shells 
- a test version of the carbon fiber tube for the hip
- a full leg (knee + hip)

I proceded to cut the metal rods used to rotate the knee and the hip. The rod for the knee mesures 75mm long whereas the one for the hip is 45mm.
There is also a second rod mounted in the knee which needed to be cut. This rod mesures 20mm long and has a notch at one of its extremities.
The notch was time-consuming to make since its a matter of details that make it useful. Mr Masson taught me how to do so using a metal file and patience.

Furthermore, I printed out the retainaing bearing I designed last week (for the movement of the hip) and the shell for the potentiometer of the hip. 
I then assembled one of Ronan's motor-reducer while the printing was going and pursued to soulder the potentiometer to wires long enough to be able to 
connect it from the knee to the body.

Finally, I had to prepare the belts for the knee and hip. 

After mounting all the pieces together, we are left with a leg that weighs around 650g (imprecise because not all the screws and bolts were mounted).


![montage](https://user-images.githubusercontent.com/95374519/219867816-c7f015f7-cc79-4072-a4b9-64fe11087ee6.jpeg)


![hip belt](https://user-images.githubusercontent.com/95374519/219867812-9e0765dc-e2b8-423d-89c5-8e60b7af3166.jpeg)


## Mobility and weight test

First and foremost, I tried retrieving the values returned by the potentiometer in both the knee and hip but none of them returned precise data. 
Indeed, both act in a binairy way where their values are [0,700,1023] and the change of value doesn't occur when a joint is moving.
This led me to think that the contact between the rotating part and the still part isn't done properly. I tried adjusting the distance between these two parts so that the metal end on the rotating part barely touches the still part but the values don't follow. I don't know if the length of the wire (30cm) is possibly responsible 
for the loss of data or not. I will conduct tests around it to learn more about it.

Moreover, I was only able to influence the speed of the motor and not the angles of the knee and hip. 
The test I led on the leg was mainly to see if the belts were tense enough to make the joints move. 

I wasn't able to capture a video of the leg being functionnal but I was able to make both the knee and hip move at the same time.
Unfortunetly, both belts broke at their extremities since that's where they are screwed in their respective bearings. 


![knee belt](https://user-images.githubusercontent.com/95374519/219867815-746d071b-560f-4d77-bf1a-f3e9a661cd45.jpeg)

As for the weight tests, I mainly wanted to know if the leg is able to carry its own weigth (650g). It appears that the hip manages to hold up the shoulder with ease
whereas the knee struggles. This is due to the belt not being tense enough. Ronan tried correcting this issue by modeling a small device capable of adjusting the
tension of the cable. However, he modeled a device to tense the belt close to the hip joint. I suggest moving the device down towards the knee joint to increase the tesnion.


![tendeur](https://user-images.githubusercontent.com/95374519/219867806-95511a4d-af96-4748-948e-9d6508eee574.jpeg)


Regarding the tension of the hip belt, it is mainly due to the structure of the shoulder shell. Indeed, the circled print on the following image tenses the belt when the shoulder is assembled.


![sheel](https://user-images.githubusercontent.com/95374519/219867819-1ad6ac3f-3333-4e28-90eb-b01dff7968c0.png)


## Next week's objective 

For next week's session, the issues mentionned bellow will have to be resolved in order to start building the entire body. 

Issue recap :
- change the position of the tension device for the knee
- change the position of the shell's attributes allowing to tense the belt
- find new potentiometers (without a rotating axe)
- figure out a way to attach the belts efficently to the joints
