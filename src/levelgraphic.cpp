/*
 * levelgraphic.cpp
 *
 *  Created on: 27/2/2016
 *      Author: Usuario
 */


#include <stdio.h>
#include <string.h>
#include <allegro.h>

#include "levelgraphic.h"
#include "mask.h"
#include "level.h"

LevelGraphic::LevelGraphic(Actor *aowner, ALLEGRO_BITMAP *b) : ActorGraphic(aowner)
{
	bmp=b;
	mask=new Mask;
	mask->create(bmp);

}
void LevelGraphic::draw()
{
	if (nivel_activo()) {
		al_draw_bitmap(bmp,0,0,0);

		switch (get_estado())
		{
			case INICIALIZADO:
				if (font_transito)
				{
					al_draw_textf(font_transito,al_map_rgb(8,8,138),300 ,270 ,ALLEGRO_ALIGN_CENTRE , "%s: %d","nivel", get_level());
				} else
				{
					printf("error al cargar el font\n");
				}
				break;
			case CREADO:
				if (font)
				{
					al_draw_textf(font,al_map_rgb(8,8,138),get_x() ,get_y() ,ALLEGRO_ALIGN_LEFT , "%s: %d",title.c_str(), get_level());
				} else
				{
					printf("error al cargar el font\n");
				}
				break;
			case DESTRUIDO:
				if (last_level()){
					if (font_transito)
					{
						al_draw_textf(font_transito,al_map_rgb(8,8,138),300 ,270 ,ALLEGRO_ALIGN_CENTRE , "%s","Game over");
					} else
					{
						printf("error al cargar el font\n");
					}
				} else {
					if (font_transito)
					{
						al_draw_textf(font_transito,al_map_rgb(8,8,138),300 ,270 ,ALLEGRO_ALIGN_CENTRE , "%s","Sigue jugando");
					} else
					{
						printf("error al cargar el font\n");
					}
				}
				break;
			default:
				break;

		}

	}
		//	al_draw_text(font, al_map_rgb(255, 0, 255), 50, 50, 0, "Hello World");
}
int LevelGraphic::get_w()
{
	return al_get_bitmap_width(bmp);
}
int LevelGraphic::get_h()
{
	return al_get_bitmap_height(bmp);
}
Mask* LevelGraphic::get_mask()
{
	return mask;
}
void LevelGraphic::set_title(string t)
{
	title = t;
}
void LevelGraphic::set_font(ALLEGRO_FONT * f)
{
	font = f;
}
void LevelGraphic::set_font_transito(ALLEGRO_FONT * f)
{
	font_transito = f;
}

