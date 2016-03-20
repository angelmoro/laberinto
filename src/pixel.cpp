/*
 * pixel.cpp
 *
 *  Created on: 24/2/2016
 *      Author: Usuario
 */

#include <allegro.h>
#include "pixel.h"

Pixel::Pixel(Actor *aowner, ALLEGRO_COLOR col) : ActorGraphic(aowner)
{
	color=col;
}
void Pixel::draw()
{
	al_put_pixel( get_x(), get_y(), color);
}
int Pixel::get_w()
{
	return 1;
}
int Pixel::get_h()
{
	return 1;
}


