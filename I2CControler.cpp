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
#include <iostream>
#include <sstream>
#include <cstdlib>

I2CControler::I2CControler() {
	// TODO Auto-generated constructor stub
}

I2CControler::~I2CControler() {
	// TODO Auto-generated destructor stub
}
using namespace std;

int I2CControler::init(){
	stringstream functionCall;

	functionCall <<"i2cset -y 3 0x70 0x21";
	system(functionCall.str().c_str());
	functionCall.str("");
	functionCall <<"i2cset -y 3 0x70 0xE8";
	system(functionCall.str().c_str());
	functionCall.str("");
	functionCall <<"i2cset -y 3 0x70 0x81";	
	system(functionCall.str().c_str());
	return(1);
}

int I2CControler::translator(int gridArray[16]){
	int dataAddress =0x00;
	stringstream functionCall;

	for(int i=0;i<16;i++){
		//Translate to correct order;
		//writeToDevice(dataAddress+i, gridArray[i]);
		functionCall <<"i2cset -y 3 0x70 " << dataAddress+i << " " << gridArray[i];

		cout << functionCall.str() << endl;
		system(functionCall.str().c_str());
		functionCall.str("");
	}

	return(1);

}
