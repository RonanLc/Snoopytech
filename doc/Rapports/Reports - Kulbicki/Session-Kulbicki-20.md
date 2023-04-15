# **Worksession 20 - 11/04/2023**

## **Overview** 

During this session, my work was focused on the math responsible for the calculation of the knee, hip and shoulder angles.

## **Representation and goals**

### **Coordinate system**

The leg of the robot can be represented in a Cartesian coordinate system $(xyz)$ in which two plans are enough to describ the entire leg. 
The lower leg can be represented in the $(x0z)$ plane, whereas the shoulder is set in the $(z0y)$ plane. 

The following pictures give a simple representation of the leg in its planes :

[photo_patte_basse]
[photo_epaule]

As shown on the pictures, the leg's position in this coordonate system is represented by a vector $(OC)$ whose coordinates are $(M_x,M_y,M_z)$.
The points can be described as so :

    O : the intersection between the shoulder's revolution axis and the hip's revolution axis (projected on the (zOy) plane)
    A : the hip joint
    B : the knee joint
    C : the feet 
    A' : the projection of A on the (zOy) plane
    Mz' : the height of the leg based on the given shoulder inclination

The angles we can act on are :

    phi : angle between the higher leg (AB) and lower leg (BC)
    theta : angle between the reference (shoulder) and the higher leg (AB)
    psi : inclination of the shoulder 

### **Inputs and outputs** 

The only data we can feed to our motor are the angles $(\phi,\theta,\psi)$. 

At the end of this study, we should be able to input the requested position of our leg $(M_x,M_y,M_z)$ and retrieve the angles allowing this position.

## **Higher and lower leg study**

In this study, I won't develop much its progress but rather the theorems and relations allowing to obtain the results. 

[picture_again_leg]

In the first picture shown above, we have a representation of the problem and its different parameters.
The goal is to expose all the relations between the different unknows $(\theta,\psi,M_x,M_z)$. 
The lengths $(AB)$ and $(BC)$ are known as the real length of the robot's leg. 

Using basic trigonometry, we are able to express $M_x$ and $M_z$ as a function of $\theta$ and $\psi$ :

$$  M_z = AB \times sin(\theta) + BC\times sin(\psi - \theta)$$
$$ M_x = BC\times cos(\psi -\theta) - AC\times cos(\theta)$$

These formulas can be useful given that we know the angles but need the position.

Again, using simple trigonometric relations and [Al Kashi's theorem](https://fr.wikipedia.org/wiki/Loi_des_cosinus) on the generalized Pythagoras theorem, 
we are able to express $\theta$ and $\psi$ knowing the position $M_x$ and $M_z$ :

$$\psi = arccos(\dfrac{AB^2 + BC² - {M_x}² - {M_z}²}{2\times AB\times BC })$$

1. Case where Mx is positive (or zero)

$$\theta = \pi - arccos(\dfrac{AB² + AC² - BC²}{2\times AB\times AC}) -arctan(\dfrac{M_z}{M_x}) $$

2. Case where Mx is negative 

$$\theta = arctan(\dfrac{M_z}{M_x})- arccos(\dfrac{AB² + AC² - BC²}{2\times AB\times AC})  $$

with $ AC = \sqrt{M_x² + M_Z²}$.

### **Conditions to respect** 

To allow these formulas to be effective on our leg, we must ensure the follwing conditions are respected :
$$ Mz < AB + BC $$
$$ |Mx| < AB + BC $$
$$ Mz > 0 $$

We must also ensure that the angles $\theta$ and $\psi$ are restricted to the potentiometers limits angles. 

## **Shoulder inclination study**

[picture_shoulder]

The previous picture exposes the problem and all its unknows. 
In this study, the aim is to obtain the relations between the different unknows $(\phi,M_z,M_y,M'_z)$.

Using basic trigonometry, we are able to express $M'_z$ and $M_y$ as functions of $\phi$ :

$$M'_z = M_z \times cos(\phi) - OA' \times sin(\phi)$$
$$M_y = OA' \times cos(\phi) + M_z \times sin(\phi)$$

These formulas can be useful given that we know the angles but need the position.

Again, using simple trigonometric relations and Al Kashi's theorem on the generalized Pythagoras theorem, 
we are able to express $\phi$ knowing the position $M'_z$, $M_y$ (and $M_z$) :

$$\phi = \frac{\pi}{2}  - arccos(\frac{{OA'}² + M_y² + {M'}_z² - M_z²}{2\times OA' \times \sqrt{M_y² + {M'}_z²}}) - arctan(\frac{M_y}{{M'}_z})$$


### **Conditions to respect** 

The formula describing $\phi$ is valid if the following conditions are respected :

$${M'}_z² + M_y² = {OA'}² + M_z²$$ 

- in order for $\phi$ to be negative (below the reference), these two conditions must be respected :
$$M_y < M'_z$$ 
and
$$M_z² > OC² + {OA'}² - \sqrt{2} \times OA' \times OC$$
with $OC=\sqrt{M_y² + {M'}_z²}$.

The <ins>**first condition is crucial**</ins> if we want a precise $M'_z$ and $M_y$ position since it describes how should $M_z$ behave in order for the foot to touch the ground. 

## Tests 

I computed a few tests with the given $(M'_z,M_y,M_x,M_z,AB,BC,OA')$ values and drew some of the results. 
The result are satisfying and allow to express $(\phi,\theta,\psi)$ precisely. 

## Next week's objective 

For next week's session, I will try to implement these formulas in a simple code to test its efficiency.
I will also have to start manufacturing new legs for the robot. 



![IMG-2780](https://user-images.githubusercontent.com/95374519/232210430-b97b0412-1f3c-4b0e-b5b0-d731bdf1b23f.jpg)

![IMG-2779](https://user-images.githubusercontent.com/95374519/232210433-0e095631-6ad1-4aee-b234-3d10236d0cb8.jpg)
