/*
 * pixel.h
 *
 *  Created on: 24/2/2016
 *      Author: Usuario
 */

#ifndef INC_PIXEL_H_
#define INC_PIXEL_H_

#include <allegro.h>
#include "actorgraphic.h"

class Pixel : public ActorGraphic
{
	public:
		Pixel(Actor *aowner, ALLEGRO_COLOR col);
		void draw();
		int get_w();
		int get_h();
		protected:
		ALLEGRO_COLOR color;
};



#endif /* INC_PIXEL_H_ */
