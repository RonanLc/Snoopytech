# Worksession 11 - 31/01/2023

## Overview

This session was centered around the modeling of the shoulder of the robot and the remodeling of the body. 

## Body remodel 

The previous model we had conceived for the body of the robot didn't consider the size of the motor-reducer designed by Ronan (55mm high, 55mm wide, 55mm long). 
Furthermore, it didn't take in count a way to attach the {motor+motor-reducer} (responsible for moving the shoulder) to the body. 
We also rethought the way the shoulders (and consequently the legs) should be linked to the body. Instead of having a shoulder that wraps around carbon fiber tubes going across the whole body, the shoulder's extremity should hold the tube partially. This allows us to put the motor-reducers used for the legs on the same axis as the tubes, therefor reducing the moment of forces of the legs on the body. 

The following image represents the element holding the {motor+motor-reducer} used for the shoulder : 

[image support]

This element is anchored in the body. 

The following image represents the object maintening the tubes for the shoulder at the middle of the body :

[image ancrage]

This element also holds the {motor+motor-reducer} used for the shoulder.

The following element is the new support plate for the body :

[support plaque]

All of these elements can be assembled to form the new body of our robot :

[new body]

## Shoulder shell

The shoulder is a complex piece which purpose is to contain the {motor+motor-reducer} (actuating the legs), all the bearings and gears for the legs. 
To make the assembling easier, the shoulder will be sliced (longwise) into two pieces that will be hold together by two elements : a gear leading in motion the whole shoulder and a small pierced ring. 

The following image represents the entire shoulder :

[shoulder]

The following image represents the gear leading in motion the shoulder :

[b1]

The following image represents the retaining ring :

[anneau maintien]

The following image represents the assembly of the {shoudler shell + gear + retaining ring} :

[assemblage epaule]

The following image represents the assembly of the legs in the shoulder :

[assemblage post epaule]

## Body assembly 

With all these previous elements, we are capable of estimating the overhall look of the robot. 
We assembled the leg into the shoulder, the body and the shoudler on the body.

The following image shows a draft of the robot assembly :

[full robot]


## Next week's objective 

For next week's mission, we will figure out a way to fit the potentiometer into the legs and start printing/testing the effectiveness of the shoulder.


