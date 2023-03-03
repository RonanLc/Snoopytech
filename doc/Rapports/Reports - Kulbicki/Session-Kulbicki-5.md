# Workseesion 5 - 25/11

This session was centered around the preparation of the 3D printing/cutting of the body and head of the robot. I also took a first approach of the Nvidia JN30D.

 ## **Modeling and printing**

We got advised to rework on the attachement of the tube (hosting the shoulder) to the body's frame. The old solution (a cut in the tube which is used to embed it in the frame) didn't seem a viable solution since the cut would have been difficult to produce, too imprecise and would rely too much on the solidity of the frame.

The new version of the attachement I came up with remplaces the embedding with a cylinder that wraps around the tube and is fixed to the frame with screws.

An image of the new attachement : 

![Capture d’écran 2022-11-26 162520](https://user-images.githubusercontent.com/95374519/204096462-bba5e833-8365-4613-b444-8894f8ae03ac.png)

Unfortunetly, the printers were all occupied and the laser cutter underwent maintenance. 
The files for the printing and cutting remain ready. 

## **JetsonNano - Setup and preview**

My aim through half of this worksession was to get the camera operational on the Jetson Nano and get a preview on the basic AIs the Jetson Nano is capable of running.

I followed NVIDIA's basic course (avaible [here](https://developer.nvidia.com/embedded/learn/jetson-ai-certification-programs#course_outline)) on how to run a docker container. 

### **What is Docker and what is a container ?**

Docker Engine is a tool that enables containerized applications to run on any infrastructure (here Ubuntu).

" Containers and virtual machines have similar resource isolation and allocation benefits, but function differently because containers virtualize the operating system instead of hardware.
Containers are lightweighted : they share the machine’s OS system kernel and therefore do not require an OS per application, driving higher server efficiencies and reducing server and licensing costs." - container definition from Docker's website.

### **Prerequisites** 

Before installing and running any containers on the JN30D, I had to log onto the JN30D.

To do so, I first connected to the JN30D using a usb-c and Putty. I needed to log to the JN30D through a Serial communication (for my computer it is COM7). 

![Capture d’écran 2022-11-26 152504](https://user-images.githubusercontent.com/95374519/204096467-aee673d1-e0c0-4c0b-afe8-5f5ede27c887.png)

To establish a secure connexion for head-less mode, my computer needs to be connected to the JN30D through a SSH protocol. Thus, the JN30D and my computer need to be connected to the same rooter. Due to its lack of Wifi module, the JN30D is connected to internet through Ethernet.

Once I logged in the JN30D with Putty, I was able to retrieve it's IP adress and could move on to setting up a secure (wireless) communication between my computer and the JN30D. 

![Capture d’écran 2022-11-26 154010](https://user-images.githubusercontent.com/95374519/204096460-8ee22cb5-ae00-4c5e-bd6f-e0d0d26b8ffe.png)

After creating a pair of private/pub keys, I needed to send the public key to the JN30D. 
Usually the ```ssh-copy-id``` command is enough, however it doesn't exist of Windows. Instead, I sent it by force using :

    cat ~/.ssh/id_rsa.pub | ssh snoop@192.168.1.190 "cat >> ~/.ssh/authorized_keys"

When it was sent, I was able to connect in head-less mode to the JN30D.

### **Installing Docker**

Docker is normally installed using :

    sudo apt install docker

Surprisingly, it was already installed on the JN30D.

### **Running containers**

I started by creating a folder `nvdli-data` on the JN30D, which will be used to retrieve data from the containers we launch. 

For example, we can run the nvidia container using this command :

    sudo docker run --runtime nvidia -it --rm --network host \
    --volume ~/nvdli-data:/nvdli-nano/data \
    --device /dev/video0 \
    nvcr.io/nvidia/dli/dli-nano-ai:<tag>

The `tag` needs to be specified and can be found on the container's website.

To make it more easy to launch, this command can be sent to a reusable script, such as :

    echo "<previous_command>" > docker_dli_run.sh


To view the preinstalled containers on the JN30D, we need the command :

    sudo docker containers ls 


To see for available containers carring a specific name we need to type :

    docker container search <name_container>

And finally, to add a container, we need to type the command :

    docker container create <image_file>



For example, I was interested in the container [PeopleNet](https://catalog.ngc.nvidia.com/orgs/nvidia/teams/tao/models/peoplenet) which can detect specific objects within an image and return a box around each object. This container can be used for monitoring purpose. 

I have installed this container but haven't launch it yet. 

## Next week's objectives

For next week's worksession, I will try to launch the `PeopleNet` container. I will also print and cut the parts needed for our robot's body and head. 

