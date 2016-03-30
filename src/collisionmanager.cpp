/*
 * collisionmanager.cpp
 *
 *  Created on: 6/2/2016
 *      Author: Usuario
 */

#include <stdio.h>
#include <iostream>
#include <iterator>
#include "collisionmanager.h"
#include "actor.h"
#include "mask.h"
#include "tilemap.h"

CollisionManager::CollisionManager(Game *g)
{
	game = g;
	colision_set = NULL;
	meta_layer_activo = NULL;
	mapa_activo = NULL;
}
void CollisionManager::update()
{
	list<Actor*>::iterator 	tmp_iter_1;
	list<Actor*>::iterator 	tmp_iter_2;
	int tile_tmp = -1;

	for (tmp_iter_1=game->actor_manager->get_begin_iterator();
		 tmp_iter_1!=game->actor_manager->get_end_iterator();
		 tmp_iter_1++)
	{

		for (tmp_iter_2=tmp_iter_1;
		 tmp_iter_2!=game->actor_manager->get_end_iterator();
		 tmp_iter_2++)
		{

/*
*	 si uno de los dos es no detectable ignoramos la colision
*/
			if (!((*tmp_iter_1)->get_is_detected()) || !((*tmp_iter_2)->get_is_detected())) continue;
/*
*	 si pertenecen al mismo equipo ignoramos la colision
*/

    		if (((*tmp_iter_1)->get_team()) == ((*tmp_iter_2)->get_team())) continue;

			switch ((*tmp_iter_1)->get_collision_method())
			{
				case PP_COLLISION:

					if (Mask::check_ppcollision((*tmp_iter_1)->get_graph_mask(),
											    (*tmp_iter_2)->get_graph_mask(),
											    (*tmp_iter_1)->get_x(),
											    (*tmp_iter_1)->get_y(),
											    (*tmp_iter_2)->get_x(),
											    (*tmp_iter_2)->get_y()))
					{
						(*tmp_iter_1)->hit(*tmp_iter_2, 0);
						(*tmp_iter_2)->hit(*tmp_iter_1, 0);
					}
					break;
				case BOUNDING_BOX:

					if (Mask::check_bbcollision((*tmp_iter_1)->get_graph_mask(),
											    (*tmp_iter_2)->get_graph_mask(),
											    (*tmp_iter_1)->get_x(),
											    (*tmp_iter_1)->get_y(),
											    (*tmp_iter_2)->get_x(),
											    (*tmp_iter_2)->get_y()))
					{
						(*tmp_iter_1)->hit(*tmp_iter_2, 0);
						(*tmp_iter_2)->hit(*tmp_iter_1, 0);
					}
					break;
				default:
					break;
			}

		}
	}
/*
*	Chequeamos las colisiones de los actores contra los tiles colisionables
*	del mapa activo.
*/

	if ((mapa_activo != NULL) && (meta_layer_activo != NULL) &&	(colision_set != NULL))
	{
//		printf("comenzamos a chequear colisiones en el mapa\n");

		for (tmp_iter_1=game->actor_manager->get_begin_iterator();
			 tmp_iter_1!=game->actor_manager->get_end_iterator();
			 tmp_iter_1++)
		{
			/*
			* si el actor no es detectable saltamos al siguiente
			*/
			if (!((*tmp_iter_1)->get_is_detected())) continue;

			/*
			* obtenemos el tile gid del tile sobre el que esta posicionado
			* el actor, lo hacemos a traves del meta layer del mapa activo
			*/

			tile_tmp = mapa_activo-> get_tile_gid(meta_layer_activo,
											 	 (*tmp_iter_1)->get_x()+((*tmp_iter_1)->get_w())/2,
												 (*tmp_iter_1)->get_y()+((*tmp_iter_1)->get_h())/2);

			if (tile_tmp != -1)
			{
				if( colision_set->count(tile_tmp) != 0)
				{
					/*
					 * El actor esta sobre un tile colisionable
					 */
					/*
					 * TBD ahora asumimos un solo colision set, pero esto se
					 * puede generalizar y manejar n-colision set e indicarlos
					 * en el metodo hit para que los actores tomen acciones distintas
					 * en funcinon de lo que colisionan en el mapa
					 * el metodo hit esta sobrecargado y en este caso el
					 * primer parametro no es un actor es un objeto del mapa
					 */
					(*tmp_iter_1)->hit(0,0);
				}
			}

		}
	}

}
void CollisionManager::activar_colision_set(TileMap *mapa,
											std::string meta_tileset,
											std::string attr_colisionable,
											std::string meta_layer)
{
//	printf("activamos colision set\n");

	colision_set = new std::set<int>;

	mapa->crear_colision_set(meta_tileset,attr_colisionable,colision_set);
	mapa_activo = mapa;
	if (mapa_activo != NULL)
	{
		meta_layer_activo = mapa_activo->get_tilelayer(meta_layer);
	}
}
void CollisionManager::desactivar_colision_set()
{
//	printf("desactivamos colision set\n");

	if (colision_set != NULL) delete colision_set;
	colision_set = NULL;
	meta_layer_activo = NULL;
	mapa_activo = NULL;
}

