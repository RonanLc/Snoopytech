# Workession 12 - 07/02/2023 

## Overview 

This session was centered around the printing of the shoulder of the robot and the adjustments brought to it.

## Shoulder render and minor changes

The day before this session I launched the printing of the shoulder. The shoulder is divided in two pieces (top/bottom) and assembled after printing. 
One half takes around 5 hours to print at regular settings (0.4 nozzle + 0.30mm layer), leading to a total 10 hours for an entire shoulder. 
The result of the printing is promising : the piece is sturdy and can withstand high forces on its extrimities (hand force). Furthermore, 
the side bearings fit precisely, so does the motor reducer and the fiber carbon tubes.

However, many issues were encountered after examination :

- the inner wheel of the side bearings were scratching on their slot, restraining them for turning. (blue)
- the width of the shoulder was too long, leaving a gap between the motor-reducer and the shoulder's structure. (orange)
- the slot for the front bearing holding the leg was too wide, letting the bearing wobble slightly. (green)
- the shoulder was assembled in a risky way : a set of screws were touching the side bearing's inner wheel, possibly damaging it. (pink)


The issues are highlighted in red on the following picture :


![shoudler_issues](https://user-images.githubusercontent.com/95374519/218253841-2cb01c9f-4597-41ee-8d6e-1fa0efaa3def.png)


I changed the shoulder whilst taking in consideration these issues. Moreover, I had to find a new way of assembling the shoulder and a way to add the potentiometer
for the hip.

The retaining ring modeled last week was rethought to be screwed in the shoulder without conflicting with the bearing. 

Here is a following image of the retaining ring, and how it is attached to the shoulder :


![retaining_ring](https://user-images.githubusercontent.com/95374519/218253870-56f2e05c-eed2-4ca8-af8f-c9654d2f4008.png)


For the potentiometer, I dug it's shape in the shell of the shoulder. The potentiometer's fix piece fits in the hole and will certainly be held by glue to the shoulder's shell. 


![pot_fix](https://user-images.githubusercontent.com/95374519/218253858-1e68aae2-7666-4e84-a84a-229a3bf0fa69.png)


The moving part of the potentiomter is mounted in a small 3D printed piece that can be seen on the next image :


![pot_mobile](https://user-images.githubusercontent.com/95374519/218253865-913355bd-bac5-4468-91bf-a455f20da1e9.png)


This part is screwed in the retaining ring responsible for the hip's movement. 

After adding the potentiometer in the shoulder, the {leg + shoulder} assembly appears like this :


![new_leg](https://user-images.githubusercontent.com/95374519/218253855-89ed929a-0eea-43c8-b33c-2edc4a28ebde.png)


## Body remodel and new objects

The overhall look of the robot after partial assembly showed that its body was close to being square. 
For aesthetic purpose, we decided to reduce the width of the body from 160mm to 120mm. This last value is slightly higher than the double of the motor-reducer's width.

The following image is the body after reducing its width :

![new_body](https://user-images.githubusercontent.com/95374519/218253850-3da2034b-8681-4616-a31d-d2b3bd8e2bb0.png)

With the space left, we needed to figure out a way to fit the ESCs in the body. 
Half of the ESCs (6) will be mounted on top of the Nvidia, whereas the other half will be attached next to the Arduino. 
This leaves space above the Arduino for a possible Base Shield and a GY-521. 

Here is an image of the piece used to mount the ESCs :


![mit_esc](https://user-images.githubusercontent.com/95374519/218253848-ed48f398-fb4d-43c3-99de-1f863c8a0c82.png)


Here is an image of the ESC beds attached onto the body :


![body_avce_lit](https://user-images.githubusercontent.com/95374519/218253843-a4a0498b-7a10-4a91-96b0-6bc934861c1c.png)


## Next week's objective 

For next week's session, I will print again the hsoulder after all the corrections brought. I will also try to cut the body.










