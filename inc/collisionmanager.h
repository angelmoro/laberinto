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
class ColisionSet;

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
		void registrar_mapa(TileMap *mapa,
							std::string meta_tileset,
							std::string attr_colisionable,
							std::string meta_layer);
		void desregistrar_mapa();
		void add_colision_set(std::string nombre_colision_set);
		void del_colision_set(std::string nombre_colision_set);
	protected:
		Game *game;
	private:
		list<ColisionSet*> 				colision_sets;
		list<ColisionSet*>::iterator 	colision_sets_iter;

		TileLayer 						* meta_layer_activo;
		TileMap 						* mapa_activo;
		std::string 					attr_col;
		std::string 					meta_tileset_activo;
};



#endif /* INC_COLLISIONMANAGER_H_ */
