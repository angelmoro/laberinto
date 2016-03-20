/*
 * actorgraphic.cpp
 *
 *  Created on: 2/2/2016
 *      Author: Usuario
 */

#include <allegro.h>
#include "actorgraphic.h"
#include "actor.h"

ActorGraphic::ActorGraphic(Actor *a)
{
	owner=a;
}
ActorGraphic::~ActorGraphic()
{
}
void ActorGraphic::update()
{
}
void ActorGraphic::init()
{
}
void ActorGraphic::draw()
{
}
int ActorGraphic::get_w()
{
	return 0;
}
int ActorGraphic::get_h()
{
	return 0;
}
int ActorGraphic::get_x()
{
	return (int)(owner->get_x());
}
int ActorGraphic::get_y()
{
	return (int)(owner->get_y());
}
int ActorGraphic::get_score()
{
	return (int)(owner->get_score());
}
int ActorGraphic::get_level()
{
	return (int)(owner->get_level());
}
bool ActorGraphic::nivel_activo()
{
	return (bool)(owner->nivel_activo());
}
bool ActorGraphic::last_level()
{
	return (bool)(owner->last_level());
}
int ActorGraphic::get_estado()
{
	return (int)(owner->get_estado());
}
string ActorGraphic::get_nombre_tmp()
{
	return (string)(owner->get_nombre_tmp());
}
list<Marca*>::iterator ActorGraphic::get_begin_iterator()
{
	return (list<Marca*>::iterator)(owner->get_begin_iterator());
}
list<Marca*>::iterator ActorGraphic::get_end_iterator()
{
	return (list<Marca*>::iterator)(owner->get_end_iterator());
}
Mask* ActorGraphic::get_mask()
{
	// es solo para evitar un warnig esta funcion es virtual y tendra implemetacion en los hijos
	return 0;
}
