/*
 * I2CControler.h
 *
 *  Created on: Oct 22, 2012
 *      Author: alex
 */

#ifndef I2CCONTROLER_H_
#define I2CCONTROLER_H_

class I2CControler {
public:
	I2CControler();
	virtual ~I2CControler();

	int init();
	int translator(int gridArray[16]);
};


#endif /* I2CCONTROLER_H_ */
