# Worksession 9 -16/12/2022

## Overview

This session was centered around the Jetson Nano and its storage disk management. 

## Jetson Nano - disk usage issue

Last week, I encountered an issue when trying to download a docker image ```deepstream```. The installation had failed since the storage had reached its limit of 14 GB.

This error underlined a major issue on the computer : the computer had no more storage available, meaning that even simple commands such as ```ls``` couldn't be executed if they returned too much text (since the standard output is considered as a file in which we write).

I seeked for a way to free-up some space by removing the files I had just downloaded (```deepstream``` and ```peoplenet```). 

### Removing ```deepstream``` package 

I first tried removing the ```deepstream``` package with the following command :

    sudo apt remove deepstream 

Unfortunatly, this command rejected the error :

    The following packages have unmet dependencies : 
    (list of packages)
    Try : apt --fix-broken install 

The packages this error mentionnes are apart of one of the ```deepstream``` libraries and are considered to be in a broken dependency. 
This means that the ```deepstream``` package can't be removed since it presents a corrupted dependancy. 

Two solutions can be found to resolve this kind of error :
1. fixing the broken dependancy (or repository) by installing the missing packages (non-useful since we want to free-up some space)
2. removing the broken packages

I then tried removing the broken packages with the command :

    sudo dpkg -r (package name)

This command rejected the same error as previously, but the real hassle is I can't remove any of the broken packages since they all depend of one another. 

For example, if I try to remove the package ```A``` it will show me an error saying that it can't be removed since this package depends on the package ```B``` which is also broken. So I try to remove the package ```B``` but it returns the same error, saying it can't be removed since it depends from the broken package ```A```. 

This situation appears as a dead-end and nothing can be uninstalled out of the ```deepstream``` package. 

### Formating the Jetson

Restarting from scratch seemed like the only option to free-up the disk's space from the Jetson.
So I searched for a way to formate the Jetson and possibly upload a new disk image able to run Ubuntu on the Jetson Nano will all the software needed to do AI (TensorFlow, Cuda, PyTorch...). 

For the formating, I found a small (3 MB) ```python3``` program meant to restore an Ubuntu distribution to its factory setting : [Resetter](https://github.com/gaining/Resetter/releases/).

When I launched the application, it crashed and unexpectedly stopped.

For the uploading side, I found a version of [Ubuntu](https://github.com/Qengineering/Jetson-Nano-Ubuntu-20-image) supported by the Jetson Nano. This distribution comes with two versions : one loaded with the software to run AI and one wthout. 

I created a bootable usb key loaded an image file of the Ubuntu distribution without the extra software. 

When I powered on the Jetson with the bootbale usb, it didn't go in the booting menu. I will have to try booting the Jetson in the booting menu in the next session.

### Solution 

I went back to the specific ```deepstream``` package and found a command that removes by force the corrupted dependancy :

    sudo dpkg --remove --force-remove-reinstreq package_name 

This command succeded without any issues. So, I did this for each corrupted package.

Once all the broken files were removed, I proceded to uninstall the remaining ````deepstream``` package.

Finally, these commands allowed to free-up to 2 GB of space on the disk.

## Miscellaneous

A short command can be used to erase the cache of the ```apt``` directory :

    sudo apt clean

It can free-up a bit of space to allow executing small commands.

## Next week's session 

For next week's session, I will attempt to restore to factory settings the Jetson. 

