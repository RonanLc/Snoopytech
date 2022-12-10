# **Worksession 6 - 06/12/2022**

## **Overview** 

This session was centered around the production of the body and head of the robot. 

## **Modeling and rework**

### **Body rework**

We estimated the body of our robot too large next to what we need to fit in it. The inside of the body will contain the Uno, the Jetson, the motors and probably the batteries (they might also end up being attached underneath the body). Thus, the highest piece contained in the body is the Jetson (31mm high) followed by the motor (30mm). Furthermore, the closest available spacers in the FabLab are 43mm high, which leaves us with a few extra millimeters to work with. 
Moreover, the width of the body was previously calculated to fit with the maximum dimensions given to us (400mm x 200mm x 300mm). I slighlty reduced the width from 200mm to 160mm to reduce the static moment on the shoulders but didn't go any lower to be sure to fit the Jetson (100mm) and the spacers.

Consequently, I had to slightly rework on the modeling of a few pieces such as the frame for the carbon tubes (pink and vertical), the spacers (yellow), the square (blue) and the plate (pink and horizontal).
The work consisted mainly in moving the holes intented for the attachements of the externel pieces (boards, spacers, camera mount). 
The way the tubes are attached also needed to be rethought since we were told the old fixations might not be easy to produce. Thus, I modeled a simple shape that wraps around the tubes and is attached to the body's frame (pink).

[image fixation tube]

An image of the tube holder.

### **Camera mount**

The support I proposed for a camera mount (see [report 2]()) presents many inconviences : it only rotates around one axis, the effort transmitted by the servo is subject to counter parasite effort due to the incertainty of the 3D printing, the axis on which the servo rotates needs a perfect alignment and the structure takes up too much space making it impossible to fit two onto one frame. On the upperside, this version deals with only one servo. 

I searched for a better model and found a two-axis mount much more compact and with a support big enough to allow us to attach a camera or an ultra-sound sensor. 

[image camera mount]

An image of the new camera mount.

I designed a small piece to allow us to attach an ultra-sound sensor to the camera mount for prototyping purposes. 

### **The new body**

[image new robot model]

An image of the new model for the body.

## **Production of the body**

After preparing all the files (body and camera mount), I headed to the FabLab to cut out in 3mm-thick wood the flat pieces of the robot (frame and plate). I launched a small impression (5g of PLA) of the squares (4 objects) to partially attach the body. Once I got the screws to assemble the body, we got a first overwiew of the body size, shape and weight. 
I tried to insert one of the carbon tubes in the frames to get an idea on the solidity of the structure. The base of the body seems sturdy. 

Furthermore, our teacher handed us a filament spool of PLA since my partner Ronan is equipped with a 3D printer at his home. This means that we are able to launch impressions from home, freeing up more 3D printers for other groups at the FabLab. Thus, he printed out for me the tube holders (4 pieces) and one camera mount (5 pieces). 

The tube's lenght being 500mm, we only need 300mm per tube. I had fright regarding the way to shape and cut the carbon tubes but Mr Juan (the FabLab manager) indicated me that it can be worked the same way as metal. I was indeed able to saw it like metal. Next, I will see if it can be drilled. 

[image of the sawed carbon tube]

An image of the sawed carbon tube. 

[image real body]

An image of the partially produced body and a proud student. 

[image of the camera mount]

An image of the camera mount.

## **The Jetson's manufacturer issues**

Since the Jetson presented disfunctions regarding the WIFI componants, our school was forced to send each Jetosn back to the manufacturer for soldering and reparations. 
Thus, I wasn't able to launch the Docker container PeopleNet. 