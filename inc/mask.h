/*
 * mask.h
 *
 *  Created on: 6/2/2016
 *      Author: Usuario
 */

#ifndef INC_MASK_H_
#define INC_MASK_H_

#include <allegro.h>
using namespace std;
//#ifndef MASK
//#define MASK

class Mask;

class Mask
{
	public:
		Mask();
		~Mask();
		static int check_ppcollision(Mask *m1, Mask *m2, int x1, int y1, int x2,
		int y2);
		static int check_bbcollision(Mask *m1, Mask *m2, int x1, int y1, int x2,
		int y2);
		void create(ALLEGRO_BITMAP *bmp);
		int get_bb_height() { return bb_height; }
		int get_bb_width() { return bb_width; }
		int get_max_chunk() { return max_chunk; }
		int get_num_y() { return num_y; }
		unsigned long int get_sp_mask(int i, int j) { return sp_mask[i][j]; }
	protected:
		int bb_height;
		int bb_width;
		int max_chunk;
		int num_y;
		unsigned long int **sp_mask;
};



#endif /* INC_MASK_H_ */
