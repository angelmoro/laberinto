/*
 * recordsgraphic.cpp
 *
 *  Created on: 4/3/2016
 *      Author: Usuario
 */


#include <stdio.h>
#include <string.h>
#include <allegro.h>

#include "recordsgraphic.h"
#include "mask.h"
#include "records.h"

RecordsGraphic::RecordsGraphic(Actor *aowner, ALLEGRO_BITMAP *b) : ActorGraphic(aowner)
{
	bmp=b;
	mask=new Mask;
	mask->create(bmp);

}
void RecordsGraphic::draw()
{



	string nom;
	list<Marca*>::iterator tmp_marca_iter;
	int p,i,l;
// para dibujar un fondo
//	al_draw_bitmap(bmp,get_x(),get_y(),0);

	switch (get_estado()) {

		case NO_STATE:
			break;
		case CAPTURANDO:

			if (font)
			{
				al_draw_textf(font,al_map_rgb(8,8,138),get_x() ,get_y() ,ALLEGRO_ALIGN_LEFT , "%s","Nombre:");
				nom = get_nombre_tmp();
				al_draw_textf(font,al_map_rgb(8,8,138),get_x()+90 ,get_y() ,ALLEGRO_ALIGN_LEFT , "%s",nom.c_str());
			} else
			{
				printf("error al cargar el font\n");
			}
			break;
		case VISUALIZANDO:

			al_draw_textf(font,al_map_rgb(8,8,138),get_x()-70 ,get_y() ,ALLEGRO_ALIGN_LEFT , "nombre                puntuacion      nivel");
			i = 40;
			for (tmp_marca_iter=get_begin_iterator();
				 tmp_marca_iter!=get_end_iterator();
				 tmp_marca_iter++)
			{
				nom = (*tmp_marca_iter)->get_nombre();
				p = (*tmp_marca_iter)->get_puntuacion();
				l = (*tmp_marca_iter)->get_level();

				if (font)
				{
					al_draw_textf(font,al_map_rgb(8,8,138),get_x()-70 ,get_y()+i ,ALLEGRO_ALIGN_LEFT , "%s",nom.c_str());
					al_draw_textf(font,al_map_rgb(8,8,138),get_x()+130 ,get_y()+i ,ALLEGRO_ALIGN_LEFT , "%d",p);
					al_draw_textf(font,al_map_rgb(8,8,138),get_x()+260 ,get_y()+i ,ALLEGRO_ALIGN_LEFT , "%d",l);
				} else
				{
					printf("error al cargar el font\n");
				}
				i = i + 20;
			}
			break;
		default:
			break;
	}
}
int RecordsGraphic::get_w()
{
	return al_get_bitmap_width(bmp);
}
int RecordsGraphic::get_h()
{
	return al_get_bitmap_height(bmp);
}
Mask* RecordsGraphic::get_mask()
{
	return mask;
}
void RecordsGraphic::set_title(string t)
{
	title = t;
}
void RecordsGraphic::set_font(ALLEGRO_FONT * f)
{
	font = f;
}
void RecordsGraphic::set_font_transito(ALLEGRO_FONT * f)
{
	font_transito = f;
}





