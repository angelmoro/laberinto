/*
 * mapadebits.h
 *
 *  Created on: 3/2/2016
 *      Author: Usuario
 */

#ifndef INC_MAPADEBITS_H_
#define INC_MAPADEBITS_H_

#include "actorgraphic.h"
#include "mask.h"

class MapaDeBits : public ActorGraphic
{
	public:
		MapaDeBits(Actor *aowner, ALLEGRO_BITMAP *b);
		void draw();
		int get_w();
		int get_h();
		Mask * get_mask();
	protected:
		ALLEGRO_BITMAP *bmp;
		Mask *mask;

};


#endif /* INC_MAPADEBITS_H_ */
