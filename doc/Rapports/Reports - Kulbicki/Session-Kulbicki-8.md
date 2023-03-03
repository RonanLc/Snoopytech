# Worksession 8 - 14/12/2022

## Overview

This session was centered around the CameraMount class and setting up the WIFI on the Jetson.

## CameraMount Class

During the last session, I encountered issues when implementing the CameraMount class into a brief main program to control two servos as one object. The error stated :

    "boolean does not define a type - did you mean bool" 
    "byte does not define a type - did you mean"

### Error correction

These errors were located in the ```ServoTimer2``` class, which was using 
both ```boolean``` and ```byte``` types. The error comes from the fact that the ```byte``` type (a translation of ```uint_t8```) doesn't exist. The same goes for ```boolean``` (translation of ```bool```).

This error was resolved by defining the ```boolean``` and ```byte``` types before the declaration of the ServoTimer2 class : 

    typedef bool boolean;
    typedef uint8_t byte;

    class ServoTimer2{
        ...
    }

This correction makes ```boolean``` objects behave the same as ```bool``` objects.

### Compilation and test

The main program is now compiling without any complications. We are able to create and use ```CameraMount``` objects. I run a few tests and ordered the servos to move in the opposite direction of the GY-521. 

Here is a [link](https://youtube.com/shorts/DMk4JTNunog?feature=share) to a short video showing this small test. 

The servos correct the angle given by the GY-521 but seem to struggle when the angle approaches the limits (+/-90°). This is due to two phenomenon : the servos don't have a 0°-180° range but more of a 0°-170° range ; when one angle value reaches +/- 90° on the GY-521, the others have a tendency to "jump" from their actual value to +/-180°.

In reality, such angles (+/-90°) shoudln't be reached, unless our robot tips over.


## Jetson 

The Jetson Nanos were given back to us with the WIFI module installed and ready. 

### Network configuration

My first aim was to connect the Jetson Nano to internet through its terminal. 

The following command is a very easy tool that can be used to open a network manager tool with a user interface :

    nmtui connect

From there we are able to connect to any network in range.

To try out the connection, we can enter this command :

    ping google.com

It will show us the response time to the ```google.com``` server. 

### SSH connection

To connect to the Jetson in headless mode we need to use SSH protocole. The next command can be typped in our external computer's terminal to attempt connecting to the Jetson :

    ssh <user>@<jetson_ip_adress>

The Jetson's IP adress can be found by typping the ```ip a``` command in the Jetson terminal and looking at the ```wlan0``` (WIFI interface) line.

Even though we are able to connect to the Jetson Nano using SSH protocol, we get an important lag between entering a command and the response.


### PeopleNet container

At the end of Session 6, I still needed to create and launch the docker image ```PeopleNet```. However, I encountered issues when trying since it relies on an other docker container to run : ```deepstream```. This application is useful when it comes to streaming videos/photos from a camera. 

The deepstream image has a size of 1.8 GB. 
I tried installing this image but it failed since the computer's disk ran out of storage. Unfortunatly, the computer didn't achieve the installation of the image and kept the non-achieved installation files, meaning that the computer's disk is left with an available storage of 200 MB out of 14 GB.

I naively thought that the content I previously installed was downloaded on the external micro-sd card (64 GB) plugged in the Jetson Nano. I learned that configuration files, packages and softwares are, by default, installed directly on the Jetson Nano.

## Next week's session 

For next week's session, I will delete all the programs I previously installed (PeopleNet and Deepstream) and find a way of running them through the micro-sd card. 

