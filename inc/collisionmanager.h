/*
 * collisionmanager.h
 *
 *  Created on: 6/2/2016
 *      Author: Usuario
 */

#ifndef INC_COLLISIONMANAGER_H_
#define INC_COLLISIONMANAGER_H_

#include <list>
#include <set>
#include <string>
#include "actormanager.h"
#include "game.h"
#include "mask.h"

class TileMap;
class TileLayer;

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
		void activar_colision_set(TileMap *mapa,
								   std::string meta_tileset,
								   std::string attr_colisionable,
								   std::string meta_layer);
		void desactivar_colision_set();
	protected:
		Game *game;
	private:

		std::set<int> 			* colision_set;
		TileLayer 				* meta_layer_activo;
		TileMap 				* mapa_activo;
};



#endif /* INC_COLLISIONMANAGER_H_ */
