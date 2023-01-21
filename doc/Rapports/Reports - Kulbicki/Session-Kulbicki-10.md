# Worksession 10 - 15/01/2023

## Overview 

This report covers the work i lead since the previous one () up until this one. Hence, I will aboard the issues encountered with the Jetson Nano, the study of the correctionnal coefficients for the position of the motors and the building of the robot. 

## Jetson Nano 

Multiples aspects of the Jetson were covered since last session.

### Onboard storage and micro-sd mount

During the last session I managed to free-up 2Gb out of the total 14Gb available on the Jetson. 
With this done, I continued removing unused package such as a duplicate version of Jetpack I had unknowingly installed (version 4.6 and 6Gb) with this line :

    apt depends nvidia-jetpack | awk ‘{print $2}’ | xargs -I {} sudo apt remove -y {} $sudo apt autoremove 

From this point, it was a fresh new start with the Jetson experience and I had to find a way to manage and correctly use the available storage.

To do so, my objective was to mount the 64Gb micro-sd card given to us with the Jetson Nano. 
I followed a list of commands aiming to mount a usb driver as a specific folder on [this](https://askubuntu.com/questions/21321/move-home-folder-to-second-drive) website.<!--  (Thanks to Nino Mulac for the solution) -->
The Jetson Nano apparently only recognizes drivers formatted in ```ext4``` which is troublesome since our micro-sd card is formatted in ```vfat``` (equivalent to ```FAT32```). 
[This](https://phoenixnap.com/kb/linux-format-disk) webpage explains how to format disk partitions using ```ext4``` file systems. After doing so, I was able to mount the micro-sd driver at the current ```/home``` folder. 
The data contained in the previous ```/home``` was obviously copied to the current ```/home``` beforehand. 

We now have a 64Gb partition mounted in the ```/home``` folder.

### Running a Docker container

Installing Docker images represents important amount of storage. Thus, we need to find a way to pull the images and download them on the freshly mounted micro-sd card. 
To do so, we can change the configuration file for Docker ```/etc/docker/daemon.json``` and add the next line at the end of the file :

    "data-root":"/home/docker-data"

```/home/docker-data``` being the folder we intend to download our Docker images in.

After doing so, we just need to reload the Docker daemon :

    sudo apt systemctl daemon-reload docker

A course proposed by Nvidia is available [here](https://developer.nvidia.com/embedded/learn/jetson-ai-certification-programs#course_outline) and acts like an initiation to launching Docker container destined to run AI programs.

The first step was to install the ```nvidia-container-runtime``` package that allows the Docker containers made by Nvidia to run. 

Then, after running the ```docker_run_dli.sh``` script (available on the course) we can open a Jupyter notebook. This notebook is a step-by-step lesson to introduce us to basic image regression and image classification algorithms. 
Unfortunetly, due to the former version of Python (2.7) on the Jetson, many errors occur when trying to use the notebook, making it useless to learn how to use AI on the Jetson.

Having no all-ready made programs for image-regression or image classification available or usable on the Jetson Nano, I started searching how to code my own AI library. Some of the libraries packed with TensorFlow (package downloaded with Jetpack on the Nano) such as ```Keras``` or ```autoKeras``` propose tools for conceiving self-made AI programs.

I will go deeper in this subject for next week's session.

### Camera control

Many tools can be found to control a camera driver under Ubuntu.
I tried out the ```fswebcam``` package to get a first simple approach of the camera.

It can be installed with the command:

    sudo apt install fswebcam

I wrote a small ```bash``` program to test it. This program takes ```jpeg``` picture with a 640x480 resolution every second for 10 seconds, and saves them in the ```/home/Pictures``` directory.


![bash](https://user-images.githubusercontent.com/95374519/213876895-14dd3373-9cb1-48bc-a7d8-7de80ca74cd5.png)


More specific tools such as ```motion``` or ```mjpg-streamer``` can be used to redirect the camera output on a localhost HTML page. These packages are mainly used for surveillance purposes, which is an objective for this project.

## Servo-control system for brushless motors

### Simulation approach

The brushless motors we use receive a PWM signal as an input (through the ESC) and output a specific rotation speed. 
The motor reducer Ronan has desinged allows us to reduce the rotation speed of the motor's axis by ```1/50```. 

The objective for our leg is to be able to change the angle of its joints precisely. This will be assured by potentiometers plugged to the output axis of the motor reducer.
The servo-control study will give us the right parameters to change efficiently the angle of our joints.

I represented the servo-motor system in Scilab with a Xcos diagram :

![xcos](https://user-images.githubusercontent.com/95374519/213876892-11e2c715-afd4-4bf1-8180-d5ccfe869bff.png)

Here is a list of the parameters used in the diagram :

    E (rad) : is the entry of the system. Values from [0-2*pi].
    K : converts the difference between entry and output into an order for the ESC. Value=1/4.
    Km (rps/rad) : static gain of the motor.
    Tm (s) : mechanical time constant of the motor.
    N : the motor-reduction coefficient. Value=1/50.

In this representation of the system, we start by removing the output angle ```S``` from the desired input ```E```. 
The resulting angle is converted by ```K``` into a rotation speed for the ESC. 
The ESC order is corrected by the PID block, which parameters will be studied later. 
The motor is represented by a simple first order system since the electrical time constant ```Te``` is negligible in front of the mechanical time constant ```Tm```. 
In our case, our motor transfert function is represented by a signel time constant ```Tm``` and a static gain ```Km```. 
The speed is then reduced by the motor-reducer.
The following block integrates the ouptut speed, allowing us to retrieve the position of the motor-reducer's axis. 
From there, we plug the output angle in the differentiator, subtracting the output from the input. 

The known parameters are :

    E : desired angle
    K=1/4
    N=1/50;

The unknown parameters are : 

    Km
    Tm

Therefore, to have an approximation of the system, we need to determine the mechanical time constant and the static gain. 
To approach the mechanical time constant, the idea is to reproduce a cue answer of the brushless motor to a specific entry. From there, we can see the responsiveness of the motor, and deduce its time constant. 
As for the static gain, we simply need to divided the output speed (rps) by the value of the ESC's order (rad). This is simple due to the fact that by default, an ESC is programmed to control a brushless motor's speed linearly. Meaning that the output speed is proportional ot the input.

### Conception 

To retrieve the motor's speed, I'll be using a Hall sensor since the brushless's rotor is composed of several magnets (14 poles). 
The signal sent by the sensor's ```AO pin``` chnages states from ```HIGH``` to ```LOW``` each time it detects a new pole. Hence, by counting the number of poles detected in a specific time period, we can approximate the speed of the brushless motor.

My teacher Mr Masson and I assembled a simple model for the speed detection. 

The program used to calculate the speed is the [following](https://github.com/RonanLc/Snoopytech/blob/main/code/test/rpm_brushless.ino). 

The program ask the motor to stay at 0 rps for 5 seconds and then asks it to turn at 90 rps. 

The curve below shows the evolution of the motor speed over time.
The y-axis is the speed (rps) and the x-axis is the time (miliseconds).


![ri1](https://user-images.githubusercontent.com/95374519/213876867-20671fbc-90dd-4e08-ba33-9355da78e807.png)



The results aren't very satisfying due the small time period I chose for the speed calculation. It calculates the speed every 200ms, which leaves the motor plenty of time to change speed from one period to another. 
Hence, Ronan tried the same program with a smaller time period (50ms).

The results are much more satisfying and we can retrieve more informations out of the curve. 

![ri2](https://user-images.githubusercontent.com/95374519/213876869-c837d9a3-8d26-4305-8f9f-777b537d6568.png)

For next week's session, I will start the study of the correctional coefficient, using the parameters of the motor that we'll be able to deduce from this previous plot.

## Modeling 

Finally, I reworked on the 3D model of the frame of the body on which the camera mount attach. I created a hole allowing the cables from the camera mount to go through. 

Furthermore, Ronan begun building a leg for our oral presentation. To do so, I was charged with the cutting a small piece of the carbon fiber tube. 
The tube needed precise holes and openings at specific places. 
I started by drawing the holes and distance between them on sticky tap and put it on the tube to use as a mark to drill the holes. 
This technic proved to be imprecise and useless. 

To ease the work of the cutting, I 3D printed a template of the tube (with the holes) slightly wider than the tube.
This piece will allow us to drill through the tubes precisely. 


![tube](https://user-images.githubusercontent.com/95374519/213876873-8a58e534-baca-4acf-a9e0-3be3027dd04a.png)

