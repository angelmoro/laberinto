/*
 * sprite.h
 *
 *  Created on: 4/2/2016
 *      Author: Usuario
 */

#ifndef INC_SPRITE_H_
#define INC_SPRITE_H_

#include "allegro.h"
#include "ActorGraphic.h"
#include <vector>
using namespace std;

class Sprite : public ActorGraphic
{
	public:
		Sprite(Actor *aowner);
		void draw(ALLEGRO_BITMAP *bmp);
		void draw();
		void update();
		void init();
		int get_w();
		int get_h();
		int get_x();
		int get_y();
		void add_frame(ALLEGRO_BITMAP *bmp, int cx, int cy, int ticks);

		Mask *get_mask();

	protected:
		typedef struct Frame
		{
			ALLEGRO_BITMAP *bmp;
			int cx;
			int cy;
			int ticks;

			Mask *mask;

		} frame;
		vector<Frame> frames;
		int actual_tick, actual_frame;
};



#endif /* INC_SPRITE_H_ */
