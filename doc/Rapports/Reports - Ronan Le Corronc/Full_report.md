# Week 41 - October 14, 2022 - 7h

## **Component change**

During the design of the leg I realized a problem, **the rotary life** of [the potentiometers we had chosen](https://fr.aliexpress.com/item/32996236826.html?spm=a2g0o.detail.1000060.3.2dfd75067cm24G&gps-id=pcDetailBottomMoreThisSeller&scm=1007.13339.291025.0&scm_id=1007.13339.291025.0&scm-url=1007.13339.291025.0&pvid=aa5bbdd6-37f4-4697-8922-a5d47906774f&_t=gps-i). They had a rotary life about **100 cycles** which is not enough. So we chose to start on [new potentiometers](https://fr.aliexpress.com/item/1005002766893077.html?spm=a2g0o.detail.1000014.28.6d93d6c1fPOoi0&gps-id=pcDetailBottomMoreOtherSeller&scm=1007.40050.281175.0&scm_id=1007.40050.281175.0&scm-url=1007.40050.281175.0&pvid=c4eb49e9-017c-42e1-bc5a-36d0b91caa96&_t=gps-id:pcDetailBottomMoreOtherSeller,scm-url:1007.40050.281175.0,pvid:c4eb49e9-017c-42e1-bc5a-36d0b91caa96,tpp_buckets:668%232846%238116%232002&pdp_ext_f=%7B%22sku_id%22%3A%2212000022084500624%22%2C%22sceneId%22%3A%2230050%22%7D&pdp_npi=2%40dis%21EUR%210.42%210.37%21%21%21%21%21%402101f6b416658300092574280e1af7%2112000022084500624%21rec) with a rotary life about **10,000 cycles** which will be much more resistant.

So I updated the list of components available [here](https://github.com/RonanLc/Snoopytech/blob/main/doc/Rapports/Liste%20de%20composants.xlsx).

## **Important and modeling of default components**

After Maximilien created [a common project on Fusion 360](https://myetu3651.autodesk360.com/g/projects/20221014567544581/data/dXJuOmFkc2sud2lwcHJvZDpmcy5mb2xkZXI6Y28uNXprUVZwQ0VTM3VlQ1hmSjdNN09nQQ), I imported and modeled the components we will use like an Arduino Uno, a Nvidia JN30D and others. This will allow us to have accurate references for our modeling.

![Default components](/doc/Rapports/Reports%20-%20Ronan%20Le%20Corronc/assets/Ronan/Default_components.png "Default components")

## **Research on leg transmission**

We were not yet decided on the transmission used for the legs of the robot. So I took the time to break down the possibilities to choose the best one.

![Transmission ideas](/doc/Rapports/Reports%20-%20Ronan%20Le%20Corronc/assets/Ronan/Plan_idees_transmissions_pattes.png "Transmission ideas")

I have therefore determined **3 possible transmissions** :

- **A.** With a connecting rod
- **B.** With a belt
- **C.** With a worm screw

Given the reliability and complexity of these transmissions, we have chosen to use the **B. transmission, with a belt**. It seems to be the most feasible and aesthetic. It will also allow us to use it directly as a gearbox.

## **Leg design**

So I started to think about the precise design of the leg and I chose to make it like the following sketch.

![Leg design](/doc/Rapports/Reports%20-%20Ronan%20Le%20Corronc/assets/Ronan/Plan_leg_idees.png "Led design")

So I started to model the leg but I haven't finished yet because of lack of time.

I modeled the shoulder tube used to rotate the leg. It is made of carbon so I entered its density (1.79g/cm3) in Fusion 360 to estimate the weight at the end.

I also modeled the ball bearing that will connect the leg to the shoulder.

![Leg modeling](/doc/Rapports/Reports%20-%20Ronan%20Le%20Corronc/assets/Ronan/Leg_modeling.png "Leg modeling")

## **Next week**

I will concentrate next week on the modeling of the leg and its assembly with the different components.

My goal is to finish modeling the leg at the end of the next session. For that I still need to design the most solid and light solution of the leg.

Once that is done, I can start modeling the shoulder and then the junction with the rest of the body.

# Week 42 - October 18, 2022 - 17h

I focused this week on the robot leg. I looked at its design, its performance and how can I build something strong and light.

## **Leg schematic**

I realized that most of the existing robots were still designed in a similar way.

![Leg design](/doc/Rapports/Reports%20-%20Ronan%20Le%20Corronc/assets/Ronan/Leg_design.png "Leg design")

They all have a straight thigh and then a curved tibia so I decided to base the leg on that.

The thigh and the shin being generally of the same size, I decided to make the thigh and the shin of 15cm. This will allow us to make the robot go up to 30cm high in case we have to overcome big obstacles. This will also be more than enough to climb the steps.

## **Modeling of the leg**

As indicated in our report, I designed the thigh and the tibia so that they can be cut out of plexiglass. This will allow us to quickly change these parts if there is a problem because they are parts that will undergo strong constraints.

![thigh and tibia modeling](/doc/Rapports/Reports%20-%20Ronan%20Le%20Corronc/assets/Ronan/Thing_and_tibia_modeling.png "thigh and tibia modeling")

I then modeled the knee joint, then the hip joint. I decided to use mainly 3D printing to design the parts that hold the bearings.

![knee joint](/doc/Rapports/Reports%20-%20Ronan%20Le%20Corronc/assets/Ronan/articulation_genou.png "knee joint")

![hip joint](/doc/Rapports/Reports%20-%20Ronan%20Le%20Corronc/assets/Ronan/articulation_hanche.png "hip joint")

The joints are almost finished. I have set up the materials of each part to have an idea of the weight of our future legs.

![leg mass](/doc/Rapports/Reports%20-%20Ronan%20Le%20Corronc/assets/Ronan/Leg_mass.png "Leg mass")

So now we have the look and design that our leg will have, this gives us an idea of the visual that our robot will have and also the weight and capabilities.

![total leg view](/doc/Rapports/Reports%20-%20Ronan%20Le%20Corronc/assets/Ronan/Leg_3D_view.png "total leg view")

## **Next week**

The joints are now almost finished so I'm going to focus on modeling the transmissions and the motorization next week.

The next step will also be to design the shoulder which will contain the motors and the position sensors. Then to focus on the connection with the body. This will allow us to start the complete assembly of the robot and correct the different errors before starting the production.

# Week 43 - October 28, 2022 - 22h

## Shoulder preliminary conception 

The leg was finish so I start working about the motor part and mostly **the shoulder part**. I made a lot of sketching because this part is the **most complex** of the leg build.

The shoulder must fit a lot of part in it :
- The 2 motors of the legs
- The belt of the hip speed reduction
- The 2 potentiometers to check the knee and hip position
- A cable connector to power all the leg part
- The pullet for the shoulder rotation

The difficulty here is to fit every thing in the shoulder. But the shoulder must be very **compact, light and also have a good design.**

## Shoulder modeling

I decided to made the shoulder in **2 part**, one for the top and one for the bottom. These parts will be made with a **3D printer**.

So I start to modeling the part to fix the shoulder on the frame. I decided to made an other tube, around the carbon fiber tube with 2 bearings.

![Shoulder tube](/doc/Rapports/Reports%20-%20Ronan%20Le%20Corronc/assets/Ronan/shoulder_tube.png)

After that I had to modeling someting to fix the 2 motors. I didn't want to fix the motors directly on 3D parts because it's not precise and solid enough.

So i decided to fix the motors on a **plexiglass piece**.

For that I modeled **a gutter** that can accommodate the plexiglass plate. So the 2 3D parts will close on the plexiglass piece.

![Shoulder gutter](/doc/Rapports/Reports%20-%20Ronan%20Le%20Corronc/assets/Ronan/shoulder_gutter_part.png)

The bottom part isn't finish yet but I start a assembly of the shoulder. I had the bottom and the top part, and the 2 bearing.

![First shoulder assembly](/doc/Rapports/Reports%20-%20Ronan%20Le%20Corronc/assets/Ronan/first_shoulder_assembly.png)

## Next week

During the next I'll continue the shoulder part.

Now I need to focus on the motors fixation and the transmission part. When the transmission will be done, I'll fix the shoulder to the rest of the leg.


# Week 46 - November 15, 2022 - 26h

## Receiving and adding 3D parts

We have received some parts that we ordered. This will allow us to start the construction of the robot but first to finalize its 3D design.

We received the 30mm bearings, the belts, the pulleys of belts, a part of the ESC. So we have all these components:

![Components reception](/doc/Rapports/Reports%20-%20Ronan%20Le%20Corronc/assets/Ronan/reception_composants1.png)

*Green: components received / Blue: components waiting / Red: components without information*

So I was able to model some parts like the belt pulley.

![3D pulley](/doc/Rapports/Reports%20-%20Ronan%20Le%20Corronc/assets/Ronan/modelisation_poulie.png)

## Shoulder modeling

I continued the modeling of the shoulder of the robot. I modeled the plexiglass plate that will hold the motors. It will slide between the upper and lower part of the shoulder.

So I could add the motors to the assembly and continue to model the shoulder shells to enclose them.

![Shoulder modeling](/doc/Rapports/Reports%20-%20Ronan%20Le%20Corronc/assets/Ronan/Support_moteur_epaule.png)

## Shoulder and leg assembly

With the motors added, I was able to continue modeling the shoulder and then assemble the leg to the rest of the assembly.

I added links to connect the angular displacement of the legs and the motors. But the reduction is still to be determined.

![Shoulder and leg assembly](/doc/Rapports/Reports%20-%20Ronan%20Le%20Corronc/assets/Ronan/preassemblage_patte_epaule.png)

## Next week

I will focus on the attachment of the leg to the shoulder. The system must be reliable and strong. 

I will also add to the shoulder the mechanism with the potentiometers to measure the position of the legs.

Depending on the progress, we will be able to start building the robot at the end of the session.

# Week 47 - November 25, 2022 - 30h

We received the last components at the beginning of the session so I focused my session on working on the motors.

![Components list](assets/session_5/liste_composants.png)

*Green: components received / Blue: components waiting / Red: components without information*

We now have all the main components to build the robot.

<br>

# Préparations des moteurs

Before starting to use the motors, some preparation has to be done. Here we received connectors with the motors so I decided to solder them to the motors and ESCs to easily connect them.

![Soldered connectors](assets/session_5/connecteur_moteur_esp.png)

Motors and ESCs can therefore be easily connected and disconnected.

![motor and esc](assets/session_5/motor_esc.png)

<br>

## Electric assembly

Thanks to these connectors I could assemble the electrical system for the motors. It is composed of a motor, an esc, and an arduino board and a potentiometer to drive the motor.

the electrical circuit is composed as follows:

![electric assembly](assets/session_5/branchement_electrique.png)

The LiPo battery here has been replaced by a DC voltage generator set to 15V to simulate the connection to a LiPo 4S.

The potentiometer will be used to select the speed of rotation of the motor and its orientation.

<br>

## Motor programming

Many methods exist to control the motor, or to control the esc. Here I use an arduino board and after many tests I discovered that some ESCs can be controlled the same way as a servo motor.

That is to say that it is controlled by PWM. This allows to indicate to the ESC the desired motor speed.

So I tested a very simple program using the arduino library for servo motors.

```ino
#include <servo.h>
```
The program works in a very simple way. It recovers the value that the potentiometer returns (corresponding to its position) and converts it in a proportional way to send it in pwm to the ESC.

```ino
#include <Servo.h>

Servo esc;
int pot;

const int pinPot = A0;
const int pinEsc = 5;

void setup() {
  esc.attach(pinEsc, 1000, 3000);
  Serial.begin(9600);
}

void loop() {
  pot = map(analogRead(pinPot), 0, 1023, 0, 180);
  Serial.println(pot);
  esc.write(pot);
  delay(10);
}
```

And here are the very first turns of the motor of our future robot!

[![first turns of the robot's motor](assets/session_5/First_turns_of_the_robots_motor.gif)](https://youtu.be/H11FsNPKSh8)

During this test I noticed two things. First, the motor doesn't seem to be going at its maximum speed so the pulse durations of the pwm would have to be changed. Second, the PWM is also used to change the direction of rotation of the motor.

The next command allows to choose the orientation of the servo motor normally. It supports an input from 0 to 180.

```ino
esc.write(90);
```

From ``90`` to ``0`` the motor turns in one direction.

*0 is supposed to be the maximum speed of the motor.*

<br>

And from ``90`` to ``180`` the motor turns in the other direction.

*180 being supposed to be the maximum speed of the motor.*

<br>

## Next week

We will start building the robot. The conception is almost finished which will allow to do the first tests of the legs in the next sessions.

The library for the servo motor works well but it is not optimized for brushless motors, at least not for this ESC.

So I'll be interested in the programming of the motor and find codes to exploit 100% the possibilities of the motor. I will also try to drive several motors at the same time.