/*
 * score.cpp
 *
 *  Created on: 12/2/2016
 *      Author: Usuario
 */

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>
#include "score.h"
#include "actormanager.h"
#include "actor.h"
#include "game.h"
#include "scoregraphic.h"
#include "mapadebits.h"


Score::Score(ActorManager * b)
{
	am = b;
	score = 0;
}
Score::~Score()
{

}
void Score::suma(int puntos)
{
	score = score + puntos;
}
void Score::resta(int puntos)
{
	score = score - puntos;
}
int Score::get_score()
{
	return score;
}
void Score::move()
{

}

void Score::hit(Actor *who, int damage)
{

	switch (who->get_team())
	{
	    case TEAM_OSO:
	    case TEAM_COMIDA:
	    case TEAM_AGUA:
	    case TEAM_VENENO:
	    case TEAM_HORMIGUERO:
		case TEAM_HORMIGAS_ROJAS:
		case TEAM_HORMIGAS_VERDES:
		case TEAM_RANA:
		default:
			break;
	}

}

Score* Score::crear_score(ActorManager *actmgr, string nombre,int pos_x,int pos_y,bool tipo_vidas)
{
	  ALLEGRO_BITMAP *bmp;
	  Score			 *score_tmp;
	  ScoreGraphic   *sg;
	  ALLEGRO_PATH   *path;
	  ALLEGRO_FONT 	*font;

	 /*
	 * para crear path relativos y poder distribuir el programa y ejecutarlo
	 * fuera del IDE
	 */

	 path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	 al_remove_path_component(path,-1);
	 al_append_path_component(path, "resources");

	 al_set_path_filename(path, "score-fondo.png");

	 score_tmp = new Score(actmgr);

	 bmp = al_load_bitmap(al_path_cstr(path, '/'));
	 if(bmp == NULL)
	 {
		al_show_native_message_box(al_get_current_display(), "Ventana de error",
								   "error fatal", "Error al cargar resource bitmap",
								   NULL, ALLEGRO_MESSAGEBOX_ERROR);
		exit(-1);
	 }
	 sg=new ScoreGraphic(score_tmp, bmp,tipo_vidas);

	 al_set_path_filename(path, "comic.ttf");

	 font = NULL;
	 font = al_load_ttf_font(al_path_cstr(path, '/'),20,0);

	 if(font == NULL)
	 {
		al_show_native_message_box(al_get_current_display(), "Ventana de error",
								   "error fatal", "Error al cargar el font",
								   NULL, ALLEGRO_MESSAGEBOX_ERROR);
		exit(-1);
	 }
	 sg->set_font(font);

	 al_set_path_filename(path, "comic.ttf");

	 font = NULL;
	 font = al_load_ttf_font(al_path_cstr(path, '/'),50,0);

	 if(font == NULL)
	 {
		al_show_native_message_box(al_get_current_display(), "Ventana de error",
								   "error fatal", "Error al cargar el font",
								   NULL, ALLEGRO_MESSAGEBOX_ERROR);
		exit(-1);
	 }
	 sg->set_font_transito(font);

	 sg->set_title(nombre);
	 score_tmp->set_actor_graphic(sg);

	 score_tmp->set_x(pos_x);
	 score_tmp->set_y(pos_y);
	 score_tmp->set_is_detected(true);
	 score_tmp->set_team(TEAM_SCORE);
	 score_tmp->set_collision_method(CollisionManager::PP_COLLISION);

	 actmgr->add(score_tmp);

	 al_destroy_path(path);
	 return score_tmp;

}
