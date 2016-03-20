/*
 * scoregraphic.h
 *
 *  Created on: 12/2/2016
 *      Author: Usuario
 */

#ifndef INC_SCOREGRAPHIC_H_
#define INC_SCOREGRAPHIC_H_

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "actorgraphic.h"
#include "mask.h"

class ScoreGraphic : public ActorGraphic
{
	public:
		ScoreGraphic(Actor *aowner, ALLEGRO_BITMAP *b,bool tipo_vidas);
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
		bool			tvidas;

};




#endif /* INC_SCOREGRAPHIC_H_ */
