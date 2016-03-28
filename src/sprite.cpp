/*
 * sprite.cpp
 *
 *  Created on: 4/2/2016
 *      Author: Usuario
 */

#include <stdio.h>
#include "allegro.h"
#include "sprite.h"

Sprite::Sprite(Actor *aowner) : ActorGraphic(aowner)
{
	actual_frame=0;
	actual_tick=0;
}
void Sprite::init()
{
	actual_frame=0;
	actual_tick=0;
}
void Sprite::add_frame(ALLEGRO_BITMAP *bmp, int cx, int cy, int ticks)
{
	Frame tmp_frame;
	tmp_frame.bmp=bmp;
	tmp_frame.cx=cx;
	tmp_frame.cy=cy;
	tmp_frame.ticks=ticks;

	// Creacion de la mascara
	tmp_frame.mask=new Mask;
	tmp_frame.mask->create(bmp);

	frames.push_back(tmp_frame);
}
void Sprite::update()
{

}

void Sprite::draw()
{
	if (frames.size()<=1) return;
	if (actual_tick>=frames[actual_frame].ticks)
	{
		actual_tick=0;
		draw(frames[actual_frame].bmp);
		actual_frame++;
		if (actual_frame>=(int)frames.size()) actual_frame=0;
	}
	else
	{
		actual_tick++;
	}
}

void Sprite::draw(ALLEGRO_BITMAP *bmp)
{
	al_draw_bitmap(bmp,get_y(),get_x(),0);
}
int Sprite::get_w()
{
//	printf("ancho = %d\n",al_get_bitmap_width(frames[actual_frame].bmp));
	return al_get_bitmap_width(frames[actual_frame].bmp);
}
int Sprite::get_h()
{
//	printf("alto = %d\n",al_get_bitmap_height(frames[actual_frame].bmp));
	return al_get_bitmap_height(frames[actual_frame].bmp);
}
int Sprite::get_x()
{

	//return owner->get_x()-(frames[actual_frame].cx);
      return owner->get_x();

}
int Sprite::get_y()
{
	//return owner->get_y()-(frames[actual_frame].cy);
	return owner->get_y();
}

Mask *Sprite::get_mask()
{
	return frames[actual_frame].mask;
}
