/*
 * I2CControler.cpp
 *
 *  Created on: Oct 22, 2012
 *      Author: alex
 */

#include "I2CControler.h"
#include <linux/i2c.h>
#include <string>
#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/ioctl.h>


I2CControler::I2CControler() {
	// TODO Auto-generated constructor stub
}

I2CControler::~I2CControler() {
	// TODO Auto-generated destructor stub
}
using namespace std;
int I2CControler::writeToDevice(int dataAddr,int value){
	int file;
	string filename = "/dev/i2c3";
	int buffer[2];
	if ((file = open(filename.c_str(),O_RDWR)) < 0)
	    return(0);
	if (ioctl(file,I2C_SLAVE,devAddress) < 0)
		return(0);
	buffer[0] = dataAddr;
	buffer[1] = value;
	if (write(file, buffer, 2) != 2)
		return(0);
	close(file);
	return(1);
}

int I2CControler::init(int devAddr){
	devAddress = devAddr;
	writeToDevice(0x21,1);
	writeToDevice(0xE8,1);
	writeToDevice(0x81,1);
	return(1);

}

int I2CControler::translator(int gridArray[16]){
	int dataAddress =0x00;
	int convertedArray[16];
	for(int i=0;i<16;i++){
		//Translate to correct order;
		writeToDevice(dataAddress+i, convertedArray[i]);

	}

	return(1);

}
