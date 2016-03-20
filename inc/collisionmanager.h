/*
 * collisionmanager.h
 *
 *  Created on: 6/2/2016
 *      Author: Usuario
 */

#ifndef INC_COLLISIONMANAGER_H_
#define INC_COLLISIONMANAGER_H_

#include <list>
#include "actormanager.h"
#include "game.h"
#include "mask.h"

class CollisionManager
{
	public:
		CollisionManager(Game *g);
		typedef enum
		{
			BOUNDING_BOX,
			PP_COLLISION
		}collision_method_t;
		void update();
	protected:
		Game *game;
	private:
		list<Actor*>::iterator tmp_iter_1;
		list<Actor*>::iterator tmp_iter_2;
};



#endif /* INC_COLLISIONMANAGER_H_ */
