/*
 * marca.cpp
 *
 *  Created on: 5/3/2016
 *      Author: Usuario
 */

#include "marca.h"

Marca::Marca()
{
	puntuacion = 0;
	nombre = "";
}
Marca::~Marca()
{

}
void Marca::set_nombre(string s)
{
	nombre = s;
}
string Marca::get_nombre()
{
	return nombre;
}
void Marca::set_puntuacion(int p)
{
	puntuacion = p;
}
int Marca::get_puntuacion()
{
	return puntuacion;
}
void Marca::set_level(int l)
{
	level = l;
}
int Marca::get_level()
{
	return level;
}
void Marca::Serialize( Json::Value& root )
{
   // serialize primitives
   root["jnombre"] = nombre;
   root["jpuntuacion"] = puntuacion;
   root["jlevel"] = level;
}
void Marca::Deserialize( Json::Value& root )
{
   // deserialize primitives
	nombre = root.get("jnombre", "").asString();
	puntuacion = root.get("jpuntuacion",0).asInt();
	level = root.get("jlevel",0).asInt();
}
bool Marca::compara(Marca * m1,Marca * m2)
{
	if (m1->level != m2->level) {
		return (m1->level > m2->level);
	} else {
		return (m1->puntuacion > m2->puntuacion);
	}
}

