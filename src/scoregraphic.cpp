/*
 * scoregraphic.cpp
 *
 *  Created on: 12/2/2016
 *      Author: Usuario
 */

#include <stdio.h>
#include <string.h>
#include <allegro.h>

#include "scoregraphic.h"
#include "mask.h"

ScoreGraphic::ScoreGraphic(Actor *aowner, ALLEGRO_BITMAP *b,bool tipo_vidas) : ActorGraphic(aowner)
{
	bmp=b;
	mask=new Mask;
	mask->create(bmp);
	tvidas = tipo_vidas;

}
void ScoreGraphic::draw()
{

//	al_draw_bitmap(bmp,get_x(),get_y(),0);

	if (font)
	{
		al_draw_textf(font,al_map_rgb(8,8,138),get_x() ,get_y() ,ALLEGRO_ALIGN_LEFT , "%s: %d",title.c_str(), get_score());
	} else
	{
		printf("error al cargar el font\n");
	}

}
int ScoreGraphic::get_w()
{
	return al_get_bitmap_width(bmp);
}
int ScoreGraphic::get_h()
{
	return al_get_bitmap_height(bmp);
}
Mask* ScoreGraphic::get_mask()
{
	return mask;
}
void ScoreGraphic::set_title(string t)
{
	title = t;
}
void ScoreGraphic::set_font(ALLEGRO_FONT * f)
{
	font = f;
}
void ScoreGraphic::set_font_transito(ALLEGRO_FONT * f)
{
	font_transito = f;
}



