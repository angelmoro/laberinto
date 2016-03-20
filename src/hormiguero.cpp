/*
 * hormiguerorojo.cpp
 *
 *  Created on: 7/2/2016
 *      Author: Usuario
 */

#include <allegro5/allegro_native_dialog.h>
#include "mapadebits.h"
#include "hormiguero.h"
#include "actormanager.h"

Hormiguero::Hormiguero(ActorManager * b)
{

}
Hormiguero::~Hormiguero()
{

}
void Hormiguero::move()
{

}
void Hormiguero::hit(Actor *who, int damage)
{
	switch (who->get_team())
	{
		case TEAM_HORMIGAS_ROJAS:
			break;
		case TEAM_HORMIGAS_VERDES:
			break;
		case TEAM_OSO:
			break;
		case TEAM_COMIDA:
			break;
		case TEAM_AGUA:
			break;
		case TEAM_VENENO:
			break;
		case TEAM_HORMIGUERO:
			set_x(Game::rnd(0,Game::gfx_w-get_w()));
            set_y(Game::rnd(0,Game::gfx_h-get_h()));
			break;
		default:
			break;
	}
}

Hormiguero* Hormiguero::crear_hormiguero(ActorManager *actmgr)
{
	  ALLEGRO_BITMAP *bmp;
	  MapaDeBits 	 *bitm;
	  Hormiguero	 *hormiguero_tmp;
	  ALLEGRO_PATH   *path;

	 /*
	 * para crear path relativos y poder distribuir el programa y ejecutarlo
	 * fuera del IDE
	 */

	 path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	 al_remove_path_component(path,-1);
	 al_append_path_component(path, "resources");

	 al_set_path_filename(path, "CasaHormigasVerdes.png");

	 hormiguero_tmp = new Hormiguero(actmgr);

	 bmp = al_load_bitmap(al_path_cstr(path, '/'));
	 if(bmp == NULL)
	 {
		al_show_native_message_box(al_get_current_display(), "Ventana de error",
								   "error fatal", "Error al cargar resource bitmap",
								   NULL, ALLEGRO_MESSAGEBOX_ERROR);
		exit(-1);
	 }
	 // Hacemos que no se vea el color negro en el bitmap de hormiguero
	 al_convert_mask_to_alpha(bmp, al_map_rgb(0,0,0));


	 bitm=new MapaDeBits(hormiguero_tmp, bmp);
	 hormiguero_tmp->set_actor_graphic(bitm);

	 hormiguero_tmp->set_x(Game::rnd(50,Game::gfx_w-hormiguero_tmp->get_w()-50));
	 hormiguero_tmp->set_y(Game::rnd(50,Game::gfx_h-hormiguero_tmp->get_h()-50));
	 hormiguero_tmp->set_is_detected(true);
	 hormiguero_tmp->set_team(TEAM_HORMIGUERO);
	 hormiguero_tmp->set_collision_method(CollisionManager::PP_COLLISION);

	 actmgr->add(hormiguero_tmp);

	 al_destroy_path(path);
	 return hormiguero_tmp;

}
