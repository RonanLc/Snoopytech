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