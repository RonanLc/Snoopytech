# Worksession 11 - 31/01/2023

## Overview

This session was centered around the modeling of the shoulder of the robot and the remodeling of the body. 

## Body remodel 

The previous model we had conceived for the body of the robot didn't consider the size of the motor-reducer designed by Ronan (55mm high, 55mm wide, 55mm long). 
Furthermore, it didn't take in count a way to attach the {motor+motor-reducer} (responsible for moving the shoulder) to the body. 
We also rethought the way the shoulders (and consequently the legs) should be linked to the body. Instead of having a shoulder that wraps around carbon fiber tubes going across the whole body, the shoulder's extremity should hold the tube partially. This allows us to put the motor-reducers used for the legs on the same axis as the tubes, therefor reducing the moment of forces of the legs on the body. 

The following image represents the element holding the {motor+motor-reducer} used for the shoulder : 


![SUPPORT MOT](https://user-images.githubusercontent.com/95374519/216767870-a51ae1ea-a088-4a2b-9365-f24ef76e1177.png)


This element is anchored in the body. 

The following image represents the object maintening the tubes for the shoulder at the middle of the body :


![ancarge_tube_int](https://user-images.githubusercontent.com/95374519/216767754-dfcaee95-0607-4b59-8871-e3e764082f4f.png)


This element also holds the {motor+motor-reducer} used for the shoulder.

The following element is the new support plate for the body :


![plaque_support](https://user-images.githubusercontent.com/95374519/216767752-2d7530b9-7c36-4b92-a6a1-bf792efd4b7f.png)


All of these elements can be assembled to form the new body of our robot :


![new_body](https://user-images.githubusercontent.com/95374519/216767747-4327f321-04fe-48d3-9319-ed7e90af39bf.png)


## Shoulder shell

The shoulder is a complex piece which purpose is to contain the {motor+motor-reducer} (actuating the legs), all the bearings and gears for the legs. 
To make the assembling easier, the shoulder will be sliced (longwise) into two pieces that will be hold together by two elements : a gear leading in motion the whole shoulder and a small pierced ring. 

The following image represents the entire shoulder :


![coque_epaule](https://user-images.githubusercontent.com/95374519/216767743-c70101b6-2718-497c-89fa-5ade3fa8c5e4.png)


The following image represents the gear leading in motion the shoulder :


![b1_coque](https://user-images.githubusercontent.com/95374519/216767766-c6e037f4-7256-4699-ada3-195dad46543a.png)


The following image represents the retaining ring :


![anneau_maintien](https://user-images.githubusercontent.com/95374519/216767757-5fc61b55-bb17-4f16-aa46-fdcb35ed82e8.png)


The following image represents the assembly of the legs in the shoulder :


![assemablage_eapule](https://user-images.githubusercontent.com/95374519/216767758-c81bbbcf-35ab-427e-abac-25170a195e67.png)


## Body assembly 

With all these previous elements, we are capable of estimating the overhall look of the robot. 
We assembled the leg into the shoulder, the body and the shoudler on the body.

The following image shows a draft of the robot assembly :


![assemblage_corps](https://user-images.githubusercontent.com/95374519/216767761-d70ec4dc-facf-43c9-9613-6cc36c75c8c0.png)



## Next week's objective 

For next week's mission, we will figure out a way to fit the potentiometer into the legs and start printing/testing the effectiveness of the shoulder.




