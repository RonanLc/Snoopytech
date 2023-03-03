# Worksession 14 - 28/02/2023

The objective of this session was to correctly implement the potentiometers in the leg.

## Potentiometer implementation

I begun the session by assembling the robot's leg and by changing the broken belts. 

We tested the state of the potentiometer we were using for the leg and discovered with Mr Masson's help that its circuit was scratched and unusable.
We tried with another potentiometer meant for the hip and it seemed to work fine once included in the leg mecanism.
We suspect that when souldering the first potentiometer to its wires, we burnt the circuit underneath its pins. 
Therefore, this explains the binairy behavior I witnessed last week. 
The solution to making the actual potentiometers work would therefore be to soulder the wires as far away from its pins as possible. This is just an hypothesis.

After inserting the working potentiometer in the knee of the robot, we were able to retrieve proper value for the knee's angle.
The potentiometer's range is ```0° - 300°``` but the knee's functionnal angle range is approximately ```0° - 100°```. 
Angles outside this range would lead to broken belt.

We discussed with Mr Masson about the feasability of the insertion of the actual potentiometers in the joints and we might encounter difficulties linked 
to precise adjustment of the distance between the mobile part and the set part.
Thus, we have ordered another type of potentiometer : 10k OHM potentiometer with hollow shafts. 
This implies we don't have to take them apart to introduce them around the metal rods we're using for the motors.

We will run tests on these new potentiometers and prepare its insertion in our 3D models.


## Modeling 

The modeling of the robot is coming to an end. However, we still need to include properly the new potentiometers mentionned earlier.
These potentiometers must be in every joints (knee, hip, shoulder). 

The way the knee's potentiometer is included was already defined by Ronan. 

The potentiometer responsible for transalting the shoulder's angle is mounted in the tube used to hold the whole shoulder. 
It is inserted in a component (called lock) that is screwed in the tube. Another component (the key) is attached in both the shoulder and the potentiometer.
The key is used to displace the rotation of the shoulder into the potentiometer.

Here is a picture of the lock, the key and its assembly.

[photo_paradis]

The potentiometer responsible for translating the hip's angle is mounted between the hip's retaining bearing and the shoudler's shell.
It consists of two gears (15 teeth, 15mm of diameter) disposed in front of each other. One is combined to the retaining bearing (therefore retrieving the hip angle), while the other one is inserted in the potentiometer. 

Here is a picture of the retaining bearing combined to the gear, a gear "key" and the assembly in the shoulder.

[photo_spur]

These models must now be tested with the new potentiometers and see how reliable they are.

## Motor control class

The [MotorJoint]() simple class allows to control a motor in order to set a specific angle on the potentiometer linked to it. 

The class creates objects retrieving data from the potentiometer and controls the speed of the motor using PID controls.

I haven't implemented the proper PID settings yet.
The studies I have led on the PID constants consists mainly in determining the proportionnal constant. 
Indeed, the integral time constant is unecessary since our system aims to achieve a precise position. 
This means that whatever the integral constant we set, it won't reduce/increase our position error since our system will always (theoretically) achieve the given position.

Therefore, we are just left with the search of the correct proportionnal and derivative constant. 
I haven't had any lessons explaining how to properly determine the derivative constant but I encountered an experimental way of founding it.
This method is called the [Ziegler Nichols method](https://fr.wikipedia.org/wiki/M%C3%A9thode_de_Ziegler-Nichols).

Thus, the PID study is resumed to finding the proportionnal constant. 
I have used the Routh method on the system modeled during the [worksession 10]() to see the limits in terms of proportionnal constant. 
The theoreticall result shows that any positive constant is good enough. 
In reality, I doubt high values aren't going to break the system.

Therefore, I will use the Ziegler Nichols method to find a proportionnal constant suited for our system. 

Since the potentiometer in the knee of the leg returns proper values, I will try ou this class on this joint. 

## Next week's objective 

For next weeks session, I will start the building of the body and test out the MotorJoint class on the knee.
