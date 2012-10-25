/*
 * main.cpp
 *
 *  Created on: Oct 22, 2012
 *      Author: alex
 */

#include "I2CControler.h"
using namespace std;
#include <unistd.h>

int main(int argc, char **argv)
{
	I2CControler i2ccontroller;
	i2ccontroller.init(0x70);
	int arrayGrid[16];
	int i;
	for( i=0; i<16;i++){
		arrayGrid[i] =0b00000000;
	}

	int j;
	while(1){
		arrayGrid[0] = 0b11111111;
		arrayGrid[2] = 0b10011001;
		arrayGrid[4] = 0b10100101;
		arrayGrid[6] = 0b11011011;
		arrayGrid[8] = 0b11011011;
		arrayGrid[10] =0b10100101;
		arrayGrid[12] =0b10011001;
		arrayGrid[14] =0b11111111;
		for(i=1; i<16;i=i+2,j++){
			arrayGrid[i] = arrayGrid[i] <<1;
			arrayGrid[i]= arrayGrid[i] | (1<<j);
		}
		j=0;

		i2ccontroller.translator(arrayGrid);
		sleep(2);
		arrayGrid[0] = 0b11111111;
		arrayGrid[2] = 0b10000001;
		arrayGrid[4] = 0b10111101;
		arrayGrid[6] = 0b10000001;
		arrayGrid[8] = 0b10111101;
		arrayGrid[10] =0b10000001;
		arrayGrid[12] =0b10111101;
		arrayGrid[14] =0b11111111;
		i2ccontroller.translator(arrayGrid);
		sleep(2);
	}

	return(1);
}
