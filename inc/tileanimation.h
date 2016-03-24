/*
 * tileanimation.h
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#ifndef INC_TILEANIMATION_H_
#define INC_TILEANIMATION_H_

#include <string>
#include <list>
#include <tinyxml2.h>

class TileFrame;

class TileAnimation
{
public:
	TileAnimation(tinyxml2::XMLElement * t);
	~TileAnimation();
	void parse();
private:

	std::list<TileFrame*> frames;
	std::list<TileFrame*>::iterator frames_iter;

	tinyxml2::XMLElement * root_tileanimation;
};



#endif /* INC_TILEANIMATION_H_ */
