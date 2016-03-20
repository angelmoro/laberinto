/*
 * bolsadinero.cpp
 *
 *  Created on: 25/2/2016
 *      Author: Usuario
 */

#include <allegro5/allegro_native_dialog.h>
#include "bolsadinero.h"
#include "actormanager.h"
#include "mapadebits.h"
#include "actor.h"

BolsaDinero::BolsaDinero(ActorManager * b,int move_to_dead)
{
	am = b;
	movimientos = move_to_dead;
}
BolsaDinero::~BolsaDinero()
{

}
void BolsaDinero::move()
{
	movimientos = movimientos -1;
	if (movimientos < 0) am->del(this);
}
void BolsaDinero::hit(Actor *who, int damage)
{
	switch (who->get_team())
	{
	    case TEAM_OSO:
	    	am->del(this);
	    	break;
	    case TEAM_COMIDA:
	    case TEAM_AGUA:
	    case TEAM_VENENO:
	    case TEAM_HORMIGAS_ROJAS:
		case TEAM_HORMIGAS_VERDES:
		case TEAM_RANA:
		case TEAM_SCORE:
		case TEAM_BOLSA_DINERO:
		case TEAM_HORMIGUERO:
			set_x(Game::rnd(0,Game::gfx_w-get_w()));
            set_y(Game::rnd(0,Game::gfx_h-get_h()));
		  	break;

		default:
			break;
	}

}

BolsaDinero * BolsaDinero::crear_bolsa_dinero(ActorManager *actmgr,int mov_to_dead)
{
	  ALLEGRO_BITMAP *bmp;
	  MapaDeBits 	 *bitm;
	  BolsaDinero	 *bolsa_dinero_tmp;
	  ALLEGRO_PATH   *path;

	 /*
	 * para crear path relativos y poder distribuir el programa y ejecutarlo
	 * fuera del IDE
	 */

	 path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	 al_remove_path_component(path,-1);
	 al_append_path_component(path, "resources");

	 al_set_path_filename(path, "bolsa-dinero.png");

	 bolsa_dinero_tmp = new BolsaDinero(actmgr,mov_to_dead);
	 bmp = al_load_bitmap(al_path_cstr(path, '/'));
	 if(bmp == NULL)
	 {
		al_show_native_message_box(al_get_current_display(), "Ventana de error",
								   "error fatal", "Error al cargar resource bitmap",
								   NULL, ALLEGRO_MESSAGEBOX_ERROR);
		exit(-1);
	 }
	 // Hacemos que no se vea el color negro en el bitmap de rana
	 al_convert_mask_to_alpha(bmp, al_map_rgb(0,0,0));


	 bitm=new MapaDeBits(bolsa_dinero_tmp, bmp);
	 bolsa_dinero_tmp->set_actor_graphic(bitm);

	 bolsa_dinero_tmp->set_x(Game::rnd(0,Game::gfx_w-bolsa_dinero_tmp->get_w()));
	 bolsa_dinero_tmp->set_y(Game::rnd(50,Game::gfx_h-bolsa_dinero_tmp->get_h()));
	 bolsa_dinero_tmp->set_is_detected(true);
	 bolsa_dinero_tmp->set_team(TEAM_BOLSA_DINERO);
	 bolsa_dinero_tmp->set_collision_method(CollisionManager::PP_COLLISION);

	 actmgr->add(bolsa_dinero_tmp);

	 al_destroy_path(path);

	 return bolsa_dinero_tmp;

}



