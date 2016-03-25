/*
 * stagemanager.cpp
 *
 *  Created on: 29/1/2016
 *      Author: Usuario
 */

#include <allegro.h>
#include <allegro5/allegro_native_dialog.h>

#include "game.h"
#include "actor.h"
#include "actormanager.h"
#include "stagemanager.h"
#include "allegro.h"

StageManager::StageManager(Game *g, int w, int h,string nombre)
{
//	 ALLEGRO_PATH   *path;
	 char tab2[1024];

	game=g;
	width=w;
	height=h;
	dis = al_create_display(w,h);
//	al_clear_to_color(al_map_rgb(128,128,0));
//	al_clear_to_color(al_map_rgb(178,34,34));


	strncpy(tab2, nombre.c_str(), sizeof(tab2));
	tab2[sizeof(tab2) - 1] = 0;

	al_set_window_title(dis,tab2); // Establecer el título de la ventana

	fondo = NULL;
	 /*
	 * para crear path relativos y poder distribuir el programa y ejecutarlo
	 * fuera del IDE
	 *

	 path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	 al_remove_path_component(path,-1);
	 al_append_path_component(path, "resources");


	 al_set_path_filename(path, "desierto2.png");


	 fondo = al_load_bitmap(al_path_cstr(path, '/'));
	 if(fondo == NULL)
	 {
		al_show_native_message_box(al_get_current_display(), "Ventana de error",
								   "error fatal", "Error al cargar resource bitmap",
								   NULL, ALLEGRO_MESSAGEBOX_ERROR);
		exit(-1);
	 }
	  */
}
StageManager::~StageManager()
{
	al_destroy_display(dis); // Destruir la ventana
}
int StageManager::w()
{
	return width;
}
int StageManager::h()
{
	return height;
}
void StageManager::update()
{
	draw();
}
void StageManager::draw()
{
	Actor *tmp;

/*
 * Lo comento mientras hago pruebas de tiled TBD

	al_clear_to_color(al_map_rgb(0,0,0));


	if (fondo != NULL) al_draw_bitmap(fondo,0,0,0);

	game->actor_manager->rewind();

	while ((tmp=game->actor_manager->next())!=NULL)
	{
		tmp->draw();
	}
*/
	al_flip_display();
}
ALLEGRO_DISPLAY * StageManager::get_display()
{
	return dis;
}

