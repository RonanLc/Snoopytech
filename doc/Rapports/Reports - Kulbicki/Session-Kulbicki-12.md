# Workession 12 - 07/02/2023 

## Overview 

This session was centered around the printing of the shoulder of the robot and the adjustments brought to it.

## Shoulder render and minor changes

The day before this session I launched the printing of the shoulder. The shoulder is divided in two pieces (top/bottom) and assembled after printing. 
One half takes around 5 hours to print at regular settings (0.4 nozzle + 0.30mm layer), leading to a total 10 hours for an entire shoulder. 
The result of the printing is promising : the piece is sturdy and can withstand high forces on its extrimities (hand force). Furthermore, 
the side bearings fit precisely, so does the motor reducer and the fiber carbon tubes.

However, many issues were encountered after examination :

- the inner wheel of the side bearings were scratching on their slot, restraining them for turning.
- the width of the shoulder was too long, leaving a gap between the motor-reducer and the shoulder's structure.
- the slot for the front bearing holding the leg was too wide, letting the bearing wobble slightly.
- the shoulder was assembled in a risky way : a set of screws were touching the side bearing's inner wheel, possibly damaging it.


The issues are highlighted in red on the following picture :

[photo]


I changed the shoulder whilst taking in consideration these issues. Moreover, I had to find a new way of assembling the shoulder and a way to add the potentiometer
for the hip.

The retaining ring modeled last week was rethought to be screwed in the shoulder without conflicting with the bearing. 

Here is a following image of the retaining ring, and how it is attached to the shoulder :

[photo]

For the potentiometer, I dug it's shape in the shell of the shoulder. The potentiometer's fix piece fits in the hole and will certainly be held by glue to the shoulder's shell. 
The moving part of the potentiomter is mounted in a small 3D printed piece that can be seen on the next image :

[photo]

This part is screwed in the retaining ring responsible for the hip's movement. 

After adding the potentiometer in the shoulder, the {leg + shoulder} assembly appears like this :

[photo]

## Body remodel and new objects

The overhall look of the robot after partial assembly showed that its body was close to being square. 
For aesthetic purpose, we decided to reduce the width of the body from 160mm to 120mm. This last value is slightly higher than the double of the motor-reducer's width.

The following image is the body after reducing its width :
[photo]

With the space left, we needed to figure out a way to fit the ESCs in the body. 
Half of the ESCs (6) will be mounted on top of the Nvidia, whereas the other half will be attached next to the Arduino. 
This leaves space above the Arduino for a possible Base Shield and a GY-521. 

Here is an image of the piece used to mount the ESCs :
[photo]

Here is an image of the ESC beds attached onto the body :
[photo]

## Next week's objective 

For next week's session, I will print again the hsoulder after all the corrections brought. I will also try to cut the body.


