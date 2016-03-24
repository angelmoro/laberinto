/*
 * tileanimation.h
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#ifndef INC_TILEANIMATION_H_
#define INC_TILEANIMATION_H_

#include <string>

class TileFrame;

class TileAnimation
{
public:
	TileAnimation();
	~TileAnimation();
private:

   TileFrame *frame;

};



#endif /* INC_TILEANIMATION_H_ */
