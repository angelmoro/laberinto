/*
 * levelmanager.h
 *
 *  Created on: 26/2/2016
 *      Author: Usuario
 */

#ifndef INC_LEVELMANAGER_H_
#define INC_LEVELMANAGER_H_

#include <algorithm>
#include <list>
using namespace std;

class Level;
class Game;

class LevelManager
{
	public:
		LevelManager(Game *g);
		~LevelManager();
		void add(Level *l);
		void del(Level *l);
		void rewind();
		Level *next();
		Level *current();
		void update();
		int num_levels();
		void tick();

		list<Level*>::iterator get_begin_iterator();
		list<Level*>::iterator get_end_iterator();

	protected:
		Game *game;
		list<Level*> levels;
		list<Level*>::iterator levels_iter;

//		list<Actor*> to_del;
//		list<Actor*> to_create;
//		void add_all_to_create();
//		void del_all_to_del();

};




#endif /* INC_LEVELMANAGER_H_ */
