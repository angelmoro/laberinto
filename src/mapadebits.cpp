/*
 * mapadebits.cpp
 *
 *  Created on: 3/2/2016
 *      Author: Usuario
 */

#include "allegro.h"
#include "mapadebits.h"
#include "mask.h"

MapaDeBits::MapaDeBits(Actor *aowner, ALLEGRO_BITMAP *b) : ActorGraphic(aowner)
{
	bmp=b;
	mask=new Mask;
	mask->create(bmp);
}
void MapaDeBits::draw()
{
	al_draw_bitmap(bmp,get_x(),get_y(),0);
}
int MapaDeBits::get_w()
{
	return al_get_bitmap_width(bmp);
}
int MapaDeBits::get_h()
{
	return al_get_bitmap_height(bmp);
}
Mask* MapaDeBits::get_mask()
{
	return mask;
}

