/*
 * comida.cpp
 *
 *  Created on: 7/2/2016
 *      Author: Usuario
 */

#include <stdio.h>
#include <allegro5/allegro_native_dialog.h>
#include "comida.h"
#include "actormanager.h"
#include "actor.h"
#include "mapadebits.h"
#include "game.h"

Comida::Comida(ActorManager * b)
{
	am = b;
}
Comida::~Comida()
{

}
void Comida::move()
{

}
void Comida::hit(Actor *who, int damage)
{

	switch (who->get_team())
	{
	    case TEAM_OSO:
	    case TEAM_COMIDA:
	    case TEAM_AGUA:
	    case TEAM_VENENO:
	    case TEAM_HORMIGUERO:
		case TEAM_RANA:
		case TEAM_SCORE:
		case TEAM_BOLSA_DINERO:
            set_x(Game::rnd(0,Game::gfx_w-get_w()));
            set_y(Game::rnd(0,Game::gfx_h-get_h()));
			break;
		case TEAM_HORMIGAS_ROJAS:
		case TEAM_HORMIGAS_VERDES:
//			am->del(this);
			break;
		default:
			break;
	}

}

void Comida::crear_comida(ActorManager *actmgr)
{
	  ALLEGRO_BITMAP *bmp;
	  MapaDeBits 	 *bitm;
	  Comida		 *comida_tmp;
	  ALLEGRO_PATH   *path;

	 /*
	 * para crear path relativos y poder distribuir el programa y ejecutarlo
	 * fuera del IDE
	 */

	 path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	 al_remove_path_component(path,-1);
	 al_append_path_component(path, "resources");

	 al_set_path_filename(path, "comida.png");

	 comida_tmp = new Comida(actmgr);

	 bmp = al_load_bitmap(al_path_cstr(path, '/'));

	 if(bmp == NULL)
	 {
		al_show_native_message_box(al_get_current_display(), "Ventana de error",
								   "error fatal", "Error al cargar resource bitmap",
								   NULL, ALLEGRO_MESSAGEBOX_ERROR);
		exit(-1);
	 }
	 // Hacemos que no se vea el color negro en el bitmap de comida
	 al_convert_mask_to_alpha(bmp, al_map_rgb(0,0,0));

	 bitm=new MapaDeBits(comida_tmp, bmp);
	 comida_tmp->set_actor_graphic(bitm);

	 comida_tmp->set_x(Game::rnd(50,Game::gfx_w-comida_tmp->get_w()));
	 comida_tmp->set_y(Game::rnd(0,Game::gfx_h-comida_tmp->get_h()));
	 comida_tmp->set_is_detected(true);
	 comida_tmp->set_team(TEAM_COMIDA);
	 comida_tmp->set_collision_method(CollisionManager::PP_COLLISION);

	 actmgr->add(comida_tmp);

	 al_destroy_path(path);
}

