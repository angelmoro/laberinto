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

CollisionManager::CollisionManager(Game *g)
{
	game = g;
}
void CollisionManager::update()
{
/*
*	printf("comiezo collision manager %d\n",game->actor_manager->num_actors());
*/
/*
*	ostream_iterator<Actor*> outStream(cout, " ");
*
*	copy(game->actor_manager->get_begin_iterator(),game->actor_manager->get_end_iterator() , outStream);
*	cout << endl;
*/

	for (tmp_iter_1=game->actor_manager->get_begin_iterator();
		 tmp_iter_1!=game->actor_manager->get_end_iterator();
		 tmp_iter_1++)
	{
/*
*	 printf("comiezo bucle1\n");
*/
/*
*	 copy(tmp_iter_1,game->actor_manager->get_end_iterator() , outStream);
*	 cout << endl;
*/

		for (tmp_iter_2=tmp_iter_1;
		 tmp_iter_2!=game->actor_manager->get_end_iterator();
		 tmp_iter_2++)
		{
/*
*	 printf("comiezo bucle2\n");
*/
/*
*	 copy(tmp_iter_2,game->actor_manager->get_end_iterator() , outStream);
*		  cout << endl;
*/

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
/*
*	printf("colision team1 %d, team2 %d\n",
*		(*tmp_iter_1)->get_team(),(*tmp_iter_2)->get_team());
*/
					} else {
/*
*	 printf("no hay colision team1 %d, team2 %d\n",
*			(*tmp_iter_1)->get_team(),(*tmp_iter_2)->get_team());
*/
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
*	printf("fin collision manager\n");
*/
}


