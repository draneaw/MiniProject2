MiniProject2
============
This project is to check the functionality of the 8x8 LED Bi-color display using the Beagle Bone. It simply initializes the LED Matrix and then writes two led sequences to the display in the different colors to allow the checking of its functionality.

I2CController
=============
I2CController controls the writing to the LED Display. In an older version the code is written to open the device using ioctl and file operations. There is pecularities with the way the bone can access the I2C devices in the code and the repository containing the myI2Cget file has a bug in it that prevents it from running on my Beagle. I could not spare the time to figure out what was wrong. The Miniproject 4 repository uses the new 8x8 LED Matrix code from Dr. Yoder and is the natural extension of this project using the Matrix code in place of the system calls. 