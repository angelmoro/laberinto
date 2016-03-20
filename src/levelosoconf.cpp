/*
 * levelosoconf.cpp
 *
 *  Created on: 6/3/2016
 *      Author: Usuario
 */

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>

#include "levelosoconf.h"
#include "cjsonserializer.h"
#include "levelosoconf.h"

LevelOsoConf::LevelOsoConf()
{
	cargar_configuracion();
}
LevelOsoConf::~LevelOsoConf()
{
	//almacenar_configuracion();
}
void LevelOsoConf::set_peso_comida(float p)
{
	peso_comida = p;
}
void LevelOsoConf::set_peso_agua(float p)
{
	peso_agua = p;
}
void LevelOsoConf::set_peso_veneno(float p)
{
	peso_veneno = p;
}
void LevelOsoConf::set_peso_hormigas_verdes(float p)
{
	peso_hormigas_verdes = p;
}
void LevelOsoConf::set_peso_hormigas_rojas(float p)
{
	peso_hormigas_rojas = p;
}
void LevelOsoConf::set_peso_rana_ticks(float p)
{
	peso_rana_ticks = p;
}
void LevelOsoConf::set_peso_bolsa_ticks(float p)
{
	peso_bolsa_ticks = p;
}
void LevelOsoConf::set_peso_rana_to_dead(float p)
{
	peso_rana_to_dead = p;
}
void LevelOsoConf::set_peso_bolsa_to_dead(float p)
{
	peso_bolsa_to_dead = p;
}
void LevelOsoConf::set_r_ticks(int p)
{
	r_ticks = p;
}
void LevelOsoConf::set_b_ticks(int p)
{
	b_ticks = p;
}
void LevelOsoConf::set_r_mov_to_dead(int p)
{
	r_mov_to_dead = p;
}
void LevelOsoConf::set_b_mov_to_dead(int p)
{
	b_mov_to_dead = p;
}
void LevelOsoConf::set_key_pad(bool p)
{
	key_pad = p;
}
float LevelOsoConf::get_peso_comida()
{
	return peso_comida;
}
float LevelOsoConf::get_peso_agua()
{
	return peso_agua;
}
float LevelOsoConf::get_peso_veneno()
{
	return peso_veneno;
}
float LevelOsoConf::get_peso_hormigas_verdes()
{
	return peso_hormigas_verdes;
}
float LevelOsoConf::get_peso_hormigas_rojas()
{
	return peso_hormigas_rojas;
}
float LevelOsoConf::get_peso_rana_ticks()
{
	return peso_rana_ticks;
}
float LevelOsoConf::get_peso_bolsa_ticks()
{
	return peso_bolsa_ticks;
}
float LevelOsoConf::get_peso_rana_to_dead()
{
	return peso_rana_to_dead;
}
float LevelOsoConf::get_peso_bolsa_to_dead()
{
	return peso_bolsa_to_dead;
}
int LevelOsoConf::get_r_ticks()
{
	return r_ticks;
}
int LevelOsoConf::get_b_ticks()
{
	return b_ticks;
}
int LevelOsoConf::get_r_mov_to_dead()
{
	return r_mov_to_dead;
}
int LevelOsoConf::get_b_mov_to_dead()
{
	return b_mov_to_dead;
}
bool LevelOsoConf::get_key_pad()
{
	return key_pad;
}
void LevelOsoConf::cargar_configuracion()
{

	std::string 			input;
	ifstream 				conffile;
	ALLEGRO_PATH   			*path;
	Json::Value 			rec_json;


	 /*
	 * para crear path relativos y poder distribuir el programa y ejecutarlo
	 * fuera del IDE
	 */

	path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	al_remove_path_component(path,-1);
	al_append_path_component(path, "resources");

	al_set_path_filename(path, "levelosoconf.txt");

	conffile.open (al_path_cstr(path,ALLEGRO_NATIVE_PATH_SEP));
	conffile >> rec_json;
//	std::cout << "configuracion a deserializar\n" << rec_json << "\n\n\n";
	this->Deserialize(rec_json);

//	CJsonSerializer::Deserialize( this, input );
/*
	for (Json::Value::iterator it = rec_json["records"].begin(); it != rec_json["records"].end(); ++it)
	{
		marca_tmp = new Marca();
		marca_tmp->Deserialize((*it));
		add(marca_tmp);
	}
*/
	conffile.close();
}
void LevelOsoConf::almacenar_configuracion()
{

	std::string 	output;
	ofstream 		conffile;
	ALLEGRO_PATH   	*path;

	 /*
	 * para crear path relativos y poder distribuir el programa y ejecutarlo
	 * fuera del IDE
	 */

	path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	al_remove_path_component(path,-1);
	al_append_path_component(path, "resources");

	al_set_path_filename(path, "levelosoconf.txt");

	conffile.open (al_path_cstr(path,ALLEGRO_NATIVE_PATH_SEP),std::ofstream::trunc);
	CJsonSerializer::Serialize( this, output);
/*
	for (tmp_marcas_iter=get_begin_iterator();
			 tmp_marcas_iter!=get_end_iterator();
			 tmp_marcas_iter++)
	{
		(*tmp_marcas_iter)->Serialize(marca_tmp);
		records_json.append(marca_tmp);
		rec_json["records"] = records_json;
	}
*/
	conffile << output;
	std::cout << "configuracion serializada\n" << output << "\n\n\n";
	conffile.close();
}
void LevelOsoConf::Serialize( Json::Value& root )
{
   // serialize primitives
   root["jpeso_comida"] = peso_comida;
   root["jpeso_agua"] = peso_agua;
   root["jpeso_veneno"] = peso_veneno;
   root["jpeso_hormigas_verdes"] = peso_hormigas_verdes;
   root["jpeso_hormigas_rojas"] = peso_hormigas_rojas;
   root["jpeso_rana_ticks"] = peso_rana_ticks;
   root["jpeso_bolsa_ticks"] = peso_bolsa_ticks;
   root["jpeso_rana_to_dead"] = peso_rana_to_dead;
   root["jpeso_bolsa_to_dead"] = peso_bolsa_to_dead;
   root["jr_ticks"] = r_ticks;
   root["jb_ticks"] = b_ticks;
   root["jr_mov_to_dead"] = r_mov_to_dead;
   root["jb_mov_to_dead"] = b_mov_to_dead;

   root["jkey_pad"] = key_pad;
}
void LevelOsoConf::Deserialize( Json::Value& root )
{
   // deserialize primitives
	peso_comida = root.get("jpeso_comida",1.0).asFloat();
	peso_agua = root.get("jpeso_agua",1.0).asFloat();
	peso_veneno = root.get("jpeso_veneno",0.3).asFloat();
	peso_hormigas_verdes = root.get("jpeso_hormigas_verdes",1.5).asFloat();
	peso_hormigas_rojas = root.get("jpeso_hormigas_rojas",0.5).asFloat();
	peso_rana_ticks = root.get("jpeso_rana_ticks",100.0).asFloat();
	peso_bolsa_ticks = root.get("jpeso_bolsa_ticks",100.0).asFloat();
	peso_rana_to_dead = root.get("jpeso_rana_to_dead",0.5).asFloat();
	peso_bolsa_to_dead = root.get("jpeso_bolsa_to_dead",0.3).asFloat();
	r_ticks = root.get("jr_ticks",1000).asInt();
	b_ticks = root.get("jb_ticks",2000).asInt();
	r_mov_to_dead = root.get("jr_mov_to_dead",20).asInt();
	b_mov_to_dead = root.get("jb_mov_to_dead",10).asInt();

	key_pad = root.get("jkey_pad",false).asBool();
}

