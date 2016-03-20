/*
 * rana.cpp
 *
 *  Created on: 12/2/2016
 *      Author: Usuario
 */


#include <stdio.h>
#include <allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include "game.h"
#include "actormanager.h"
#include "rana.h"
#include "mapadebits.h"
#include "sprite.h"

ALLEGRO_SAMPLE *Rana::sonido_rana;


Rana::Rana(ActorManager * b,int mov_to_dead)
{
	am = b;
	size = 30; //tamaño en pixels del movimiento
    saltos = mov_to_dead;

    if (!al_play_sample(Rana::sonido_rana, 4.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,&sample_id))
    	{
    			al_show_native_message_box(al_get_current_display(), "Ventana de error",
    									   "error fatal", "Error al play sonido rana",
    									   NULL, ALLEGRO_MESSAGEBOX_ERROR);
    			exit(-1);
    	}

}
Rana::~Rana()
{
	al_stop_sample(&sample_id);
//	al_stop_samples();
}
void Rana::inicializar_sonido()
{
	 ALLEGRO_PATH   *path;

	 /*
	 * para crear path relativos y poder distribuir el programa y ejecutarlo
	 * fuera del IDE
	 */

	 path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	 al_remove_path_component(path,-1);
	 al_append_path_component(path, "resources");

	 al_set_path_filename(path, "tree-frog.wav");
//	 printf("path = %s\n",al_path_cstr(path, '/'));
	 Rana::sonido_rana = al_load_sample(al_path_cstr(path, '/'));
	 if(Rana::sonido_rana == NULL)
	 {
		al_show_native_message_box(al_get_current_display(), "Ventana de error",
								   "error fatal", "Error al cargar resource sonido",
								   NULL, ALLEGRO_MESSAGEBOX_ERROR);
		exit(-1);
	 }
	 al_destroy_path(path);


}

void Rana::move()
{
	 int rowMove;
	 int colMove;
	 int newRow;
	 int newCol;


	 rowMove=Game::rnd(0,2)-1;
	 colMove=Game::rnd(0,2)-1;
	 newRow=y+rowMove*size;
	 newCol=x+colMove*size;

	 if (newRow<0) newRow = 0;
	 if (newCol<0) newCol = 0;
	 if (newRow>Game::gfx_h-get_h()) newRow = Game::gfx_h-get_h();
	 if (newCol>Game::gfx_w-get_w()) newCol = Game::gfx_w-get_w();

	 y=newRow;
	 x=newCol;
	 saltos = saltos -1;
	 if (saltos < 0) am->del(this);
}





void Rana::hit(Actor *who, int damage)
{

	switch (who->get_team())
	{
		case TEAM_HORMIGAS_ROJAS:
			break;
		case TEAM_HORMIGAS_VERDES:
			break;
		case TEAM_OSO:
			am->del(this);
			break;
		case TEAM_COMIDA:
			break;
		case TEAM_AGUA:
			break;
		case TEAM_VENENO:
			am->del(this);
			break;
		case TEAM_HORMIGUERO:
			break;
		case TEAM_RANA:
			break;
		case TEAM_BOLSA_DINERO:
			break;
		default:
			break;
	}

}

void Rana::crear_rana(ActorManager *actmgr,int mov_to_dead)
{
	  ALLEGRO_BITMAP *bmp1,*bmp2,*bmp3;
	  Sprite     	*sp;
	  Rana			*rana_tmp;
	  ALLEGRO_PATH   *path;

	 /*
	 * para crear path relativos y poder distribuir el programa y ejecutarlo
	 * fuera del IDE
	 */

	 path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	 al_remove_path_component(path,-1);
	 al_append_path_component(path, "resources");

     rana_tmp = new Rana(actmgr,mov_to_dead);

     al_set_path_filename(path, "rana1.png");
 //    printf("path = %s\n",al_path_cstr(path, '/'));
	 bmp1 = al_load_bitmap(al_path_cstr(path, '/'));
	 if(bmp1 == NULL)
	 {
		al_show_native_message_box(al_get_current_display(), "Ventana de error",
								   "error fatal", "Error al cargar resource bitmap",
								   NULL, ALLEGRO_MESSAGEBOX_ERROR);
		exit(-1);
	 }
	 // Hacemos que no se vea el color negro en el bitmap de rana
	 al_convert_mask_to_alpha(bmp1, al_map_rgb(0,0,0));

	 al_set_path_filename(path, "rana2.png");
//	 printf("path = %s\n",al_path_cstr(path, '/'));
	 bmp2 = al_load_bitmap(al_path_cstr(path, '/'));
	 if(bmp2 == NULL)
	 {
		al_show_native_message_box(al_get_current_display(), "Ventana de error",
								   "error fatal", "Error al cargar resource bitmap",
								   NULL, ALLEGRO_MESSAGEBOX_ERROR);
		exit(-1);
	 }
	 // Hacemos que no se vea el color negro en el bitmap de rana
	 al_convert_mask_to_alpha(bmp2, al_map_rgb(0,0,0));

	 al_set_path_filename(path, "rana3.png");
//	 printf("path = %s\n",al_path_cstr(path, '/'));
	 bmp3 = al_load_bitmap(al_path_cstr(path, '/'));
	 if(bmp3 == NULL)
	 {
		al_show_native_message_box(al_get_current_display(), "Ventana de error",
								   "error fatal", "Error al cargar resource bitmap",
								   NULL, ALLEGRO_MESSAGEBOX_ERROR);
		exit(-1);
	 }
	 // Hacemos que no se vea el color negro en el bitmap de rana
	 al_convert_mask_to_alpha(bmp3, al_map_rgb(0,0,0));

	 sp=new Sprite(rana_tmp);
	 sp->add_frame(bmp1, al_get_bitmap_width(bmp1)/2, al_get_bitmap_height(bmp1)/2, 0);
	 sp->add_frame(bmp2, al_get_bitmap_width(bmp2)/2, al_get_bitmap_height(bmp2)/2, 0);
	 sp->add_frame(bmp3, al_get_bitmap_width(bmp3)/2, al_get_bitmap_height(bmp3)/2, 0);

	 rana_tmp->set_actor_graphic(sp);

	 rana_tmp->set_x(Game::rnd(0,Game::gfx_w-rana_tmp->get_w()));
	 rana_tmp->set_y(Game::rnd(50,Game::gfx_h-rana_tmp->get_h()));

	 rana_tmp->set_is_detected(true);
	 rana_tmp->set_team(TEAM_RANA);
	 rana_tmp->set_collision_method(CollisionManager::PP_COLLISION);

	 actmgr->add(rana_tmp);

	 al_destroy_path(path);
}

