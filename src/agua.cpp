/*
 * agua.cpp
 *
 *  Created on: 7/2/2016
 *      Author: Usuario
 */

#include <allegro5/allegro_native_dialog.h>
#include "agua.h"
#include "actormanager.h"
#include "mapadebits.h"
#include "actor.h"

Agua::Agua(ActorManager * b)
{
	am = b;
}
Agua::~Agua()
{

}
void Agua::move()
{

}
void Agua::hit(Actor *who, int damage)
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
	//		am->del(this);
			break;
		default:
			break;
	}

}

void Agua::crear_agua(ActorManager *actmgr)
{
	  ALLEGRO_BITMAP *bmp;
	  MapaDeBits 	 *bitm;
	  Agua			 *agua_tmp;
	  ALLEGRO_PATH   *path;

	 /*
	 * para crear path relativos y poder distribuir el programa y ejecutarlo
	 * fuera del IDE
	 */

	 path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	 al_remove_path_component(path,-1);
	 al_append_path_component(path, "resources");

	 al_set_path_filename(path, "agua.png");

	 agua_tmp = new Agua(actmgr);
	 bmp = al_load_bitmap(al_path_cstr(path, '/'));
	 if(bmp == NULL)
	 {
		al_show_native_message_box(al_get_current_display(), "Ventana de error",
								   "error fatal", "Error al cargar resource bitmap",
								   NULL, ALLEGRO_MESSAGEBOX_ERROR);
		exit(-1);
	 }
	 // Hacemos que no se vea el color negro en el bitmap de agua
	 al_convert_mask_to_alpha(bmp, al_map_rgb(0,0,0));

	 bitm=new MapaDeBits(agua_tmp, bmp);
	 agua_tmp->set_actor_graphic(bitm);

	 agua_tmp->set_x(Game::rnd(50,Game::gfx_w-agua_tmp->get_w()));
	 agua_tmp->set_y(Game::rnd(0,Game::gfx_h-agua_tmp->get_h()));
	 agua_tmp->set_is_detected(true);
	 agua_tmp->set_team(TEAM_AGUA);
	 agua_tmp->set_collision_method(CollisionManager::PP_COLLISION);

	 actmgr->add(agua_tmp);

	 al_destroy_path(path);

}
