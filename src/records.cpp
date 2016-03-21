/*
 * records.cpp
 *
 *  Created on: 3/3/2016
 *      Author: Usuario
 */

#include <stdio.h>
#include <iostream>
#include <fstream>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>
#include "records.h"
#include "recordsgraphic.h"
#include "cjsonserializer.h"
#include "marca.h"

using namespace std;

Records::Records(ActorManager * a, int max)
{
	ALLEGRO_PATH   *path;

	max_records = max;
	am = a;
	state = NO_STATE;
	recuperar_records();


	 /*
	 * para crear path relativos y poder distribuir el programa y ejecutarlo
	 * fuera del IDE
	 */

	path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	al_remove_path_component(path,-1);
	al_append_path_component(path, "resources");

	al_set_path_filename(path, "game-menu-click.wav");

	sonido_tecla = al_load_sample(al_path_cstr(path, '/'));
	if(sonido_tecla == NULL)
	{
		al_show_native_message_box(al_get_current_display(), "Ventana de error",
								   "error fatal", "Error al cargar resource sonido",
								   NULL, ALLEGRO_MESSAGEBOX_ERROR);
		exit(-1);
	}

	al_destroy_path(path);

}
Records::~Records()
{
	almacenar_records();
}

void Records::move()
{

}
void Records::hit(Actor *a, int damage)
{

}
void Records::init()
{

}
void Records::add(Marca *m)
{
	marcas.push_back(m);
}
void Records::del(Marca *m)
{
	list<Marca*>::iterator tmp_marcas_iter;
	tmp_marcas_iter=find(marcas.begin(), marcas.end(), m);
	if (tmp_marcas_iter!=marcas.end())
	marcas.erase(tmp_marcas_iter);
}
void Records::rewind()
{
	marcas_iter=marcas.begin();
}
Marca *Records::next()
{
	Marca *tmp_m;
	tmp_m=*marcas_iter;
	if (marcas_iter==marcas.end()) return NULL;
	marcas_iter++;
	return tmp_m;
}
Marca *Records::current()
{
	if (marcas_iter==marcas.end()) return NULL;
	else
		return *marcas_iter;
}

void Records::do_action(ControllableObject::action_t act, int magnitude)
{
	list<Marca*>::iterator tmp_marcas_iter;

	al_play_sample(sonido_tecla, 3.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
	if ((act >= ALLEGRO_KEY_A) && (act <= ALLEGRO_KEY_Z )) {
		if (nombre_tmp.length()<9)
			nombre_tmp += al_keycode_to_name(act);
	}

	switch (act)
		{
			case ALLEGRO_KEY_ENTER:
				tmp_marcas_iter = marcas.end();
				tmp_marcas_iter--;
				(*tmp_marcas_iter)->set_nombre(nombre_tmp);
				nombre_tmp = "";
				//Ordenar
				marcas.sort(Marca::compara);
				purgar_records();
				set_estado(VISUALIZANDO);
				break;
			case ALLEGRO_KEY_PAD_ENTER:
				tmp_marcas_iter = marcas.end();
				tmp_marcas_iter--;
				(*tmp_marcas_iter)->set_nombre(nombre_tmp);
				nombre_tmp = "";
				//Ordenar
				marcas.sort(Marca::compara);
				purgar_records();
				set_estado(VISUALIZANDO);
				break;
			case ALLEGRO_KEY_BACKSPACE:
				if (nombre_tmp.size() > 0) nombre_tmp.erase (nombre_tmp.end()-1, nombre_tmp.end());
				break;
			default:
				break;
		}
//printf("%s\n",nombre_tmp.c_str());

}

string Records::get_nombre_tmp()
{
	return nombre_tmp;
}

Records* Records::crear_records(ActorManager *actmgr, string nombre,int pos_x,int pos_y,int m)
{
	  ALLEGRO_BITMAP *bmp;
	  Records		 *records_tmp;
	  RecordsGraphic *rg;
	  ALLEGRO_PATH   *path;
	  ALLEGRO_FONT 	 *font;

	 /*
	 * para crear path relativos y poder distribuir el programa y ejecutarlo
	 * fuera del IDE
	 */

	 path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	 al_remove_path_component(path,-1);
	 al_append_path_component(path, "resources");

	 al_set_path_filename(path, "score-fondo.png");

	 records_tmp = new Records(actmgr,m);

	 bmp = al_load_bitmap(al_path_cstr(path, '/'));
	 if(bmp == NULL)
	 {
		al_show_native_message_box(al_get_current_display(), "Ventana de error",
								   "error fatal", "Error al cargar resource bitmap",
								   NULL, ALLEGRO_MESSAGEBOX_ERROR);
		exit(-1);
	 }
	 rg=new RecordsGraphic(records_tmp, bmp);

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
	 rg->set_font(font);

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
	 rg->set_font_transito(font);

	 rg->set_title(nombre);
	 records_tmp->set_actor_graphic(rg);

	 records_tmp->set_x(pos_x);
	 records_tmp->set_y(pos_y);
	 records_tmp->set_is_detected(true);
	 records_tmp->set_team(TEAM_RECORDS);
	 records_tmp->set_collision_method(CollisionManager::PP_COLLISION);

	 actmgr->add(records_tmp);

	 al_destroy_path(path);
	 return records_tmp;

}
void Records::set_estado(int e)
{
	state = e;
}
int Records::get_estado(void)
{
	return state;
}
list<Marca*>::iterator Records::get_begin_iterator()
{
	return marcas.begin();
}
list<Marca*>::iterator Records::get_end_iterator()
{
	return marcas.end();
}
void Records::almacenar_records()
{
	list<Marca*>::iterator tmp_marcas_iter;
	std::string output;
	ofstream recordsfile;
	ALLEGRO_PATH   *path;
	Json::Value records_json(Json::arrayValue);
	Json::Value marca_tmp;
	Json::Value rec_json(Json::objectValue);
	 /*
	 * para crear path relativos y poder distribuir el programa y ejecutarlo
	 * fuera del IDE
	 */

	path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	al_remove_path_component(path,-1);
	al_append_path_component(path, "resources");

	al_set_path_filename(path, "records.txt");

	recordsfile.open (al_path_cstr(path,ALLEGRO_NATIVE_PATH_SEP),std::ofstream::trunc);

	for (tmp_marcas_iter=get_begin_iterator();
			 tmp_marcas_iter!=get_end_iterator();
			 tmp_marcas_iter++)
	{
		(*tmp_marcas_iter)->Serialize(marca_tmp);
		records_json.append(marca_tmp);
		rec_json["records"] = records_json;
	}
	recordsfile << rec_json;
//	std::cout << "Records serializados\n" << rec_json << "\n\n\n";
	recordsfile.close();
}
void Records::recuperar_records()
{
	list<Marca*>::iterator 	tmp_marcas_iter;
	std::string 			input;
	ifstream 				recordsfile;
	ALLEGRO_PATH   			*path;
	Marca 					*marca_tmp;
	Json::Value 			rec_json;

	 /*
	 * para crear path relativos y poder distribuir el programa y ejecutarlo
	 * fuera del IDE
	 */

	path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	al_remove_path_component(path,-1);
	al_append_path_component(path, "resources");

	al_set_path_filename(path, "records.txt");

	recordsfile.open (al_path_cstr(path,ALLEGRO_NATIVE_PATH_SEP));
	recordsfile >> rec_json;
	for (Json::Value::iterator it = rec_json["records"].begin(); it != rec_json["records"].end(); ++it)
	{
		marca_tmp = new Marca();
		marca_tmp->Deserialize((*it));
		add(marca_tmp);
	}
	recordsfile.close();
}
void Records::purgar_records()
{
	list<Marca*>::iterator 	tmp_marcas_iter;
	int 					i;

	i=0;
	for (tmp_marcas_iter=get_begin_iterator();
				 tmp_marcas_iter!=get_end_iterator();
				 tmp_marcas_iter++)
	{
		i++;
		if (i>max_records) {
			marcas.erase(tmp_marcas_iter,get_end_iterator());
			break;
		}
	}
}
