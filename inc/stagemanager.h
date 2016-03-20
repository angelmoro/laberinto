/*
 * stagemanager.h
 *
 *  Created on: 29/1/2016
 *      Author: Usuario
 */

#ifndef INC_STAGEMANAGER_H_
#define INC_STAGEMANAGER_H_

#include <allegro.h>
#include <stdio.h>
#include <string>


using namespace std;
class Game;

class StageManager
{
	public:
		StageManager(Game *g, int w, int h, string nombre);
		~StageManager();
		int w();
		int h();
		void update();
		void draw();
		ALLEGRO_DISPLAY * get_display();
	protected:
		Game *game;
		ALLEGRO_DISPLAY *dis;
		int width, height;
		ALLEGRO_BITMAP * fondo;
};




#endif /* INC_STAGEMANAGER_H_ */
