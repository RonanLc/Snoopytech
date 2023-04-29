# Worksession 21 - 25/04/2023

## Overview

During this session, I mainly machined the pieces needed in the leg assembly. 

## Machining 

We have started the assembling of the four legs. This assembly requieres many machined elements such as metal rodes, carbon fiber tubes or plexiglass. 
I proceded to cut the metal rodes used for the four axis for each leg.

The length for each rod is :

    knee rod : 25mm (6mm diameter)
    hip rods : 46mm and 76mm (5mm diameter)
    shoulder rod : 35mm

Thus, we have a total of 12 rods that are currently being installed in the motor reducers and knee. 

Furthermore, I continued with the cutting/drilling of the carbon fiber tubes responsible for the hip and shoulder movement. 
This task was easily done with the template built at the [session 10](https://github.com/RonanLc/Snoopytech/blob/main/doc/Rapports/Reports%20-%20Kulbicki/Session-Kulbicki-10.md).

We now have an amount of 7 tubes that are ready to be mounted (3 hip axis + 3 shoudler axis + 1 large shoudler axis).


Finally, I have greased the available motor reducers. 


## Angle computation implementation 

The math study led last week needs some testing to see how accurate it is. 

Therefore, I have written a small program that calculates the position of a leg given the angles of its joints and vice versa.

I have tried to compute the position for the respective angles : 

    phi = 10°
    theta = 45°
    psi = 90°

The output of the function is :

    mx = 6.65 mm
    my = 111.6 mm
    mz = 218 mm
    mz' = 202.32 mm

I have then tried feeding these values in the function calcultating the angles given the position and the output is :

    phi = -10°
    theta = -48°
    psi = 89° 

As seen, the function computes with at least a 3° precision. 
I haven't figured out yet the cause of the negative sign in front of the phi and theta angles. 
I must pursue the testing of this program.

## Next week's session

For next week's final session, I will have to finish mounting the legs.
I must also program a short class allowing to easily control the movement of an entire leg based on a given position to achieve. 
This program will contain portions of the program I have testing during this session.
