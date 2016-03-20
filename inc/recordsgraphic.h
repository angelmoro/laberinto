/*
 * recordsgraphic.h
 *
 *  Created on: 4/3/2016
 *      Author: Usuario
 */

#ifndef INC_RECORDSGRAPHIC_H_
#define INC_RECORDSGRAPHIC_H_

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "actorgraphic.h"
#include "mask.h"

class RecordsGraphic : public ActorGraphic
{
	public:
		RecordsGraphic(Actor *aowner, ALLEGRO_BITMAP *b);
		void draw();
		int get_w();
		int get_h();
		Mask * get_mask();
		void set_title(string t);
		void set_font(ALLEGRO_FONT * f);
		void set_font_transito(ALLEGRO_FONT * f);
	protected:
		ALLEGRO_BITMAP 	*bmp;
		Mask 			*mask;
		ALLEGRO_FONT 	*font;
		ALLEGRO_FONT 	*font_transito;
		string 			title;





};



#endif /* INC_RECORDSGRAPHIC_H_ */
