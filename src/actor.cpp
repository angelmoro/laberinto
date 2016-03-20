/*
 * actor.cpp
 *
 *  Created on: 28/1/2016
 *      Author: Usuario
 */

#include "allegro.h"
#include "actor.h"
#include "mask.h"

Actor::Actor()
{
	agraph=NULL;
	team = NO_TEAM;
	is_invisible = FALSE;
}
Actor::~Actor()
{
	if (agraph) delete agraph;
}
void Actor::draw()
{
	if (!is_invisible)	agraph->draw();
}
void Actor::update()
{
	agraph->update();
	move();
}

void Actor::init()
{
	agraph->init();
}

void Actor::move()
{
}

void Actor::set_x(int pos_x)
{
	x=pos_x;
}
void Actor::set_y(int pos_y)
{
	y=pos_y;
}

int Actor::get_score()
{
	return 0;
}
int Actor::get_level()
{
	return 0;
}
bool Actor::last_level()
{
	return FALSE;
}
int Actor::get_estado()
{
	return 0;
}
void Actor::set_estado(int e)
{

}
bool Actor::nivel_activo()
{
	return FALSE;
}
string Actor::get_nombre_tmp()
{
	return "";
}
list<Marca*>::iterator Actor::get_begin_iterator()
{

}
list<Marca*>::iterator Actor::get_end_iterator()
{

}
void Actor::set_actor_graphic(ActorGraphic *ag)
{
	agraph=ag;
}
int Actor::get_x()
{
	return x;
}
int Actor::get_y()
{
	return y;
}

int Actor::get_w()
{
	return agraph->get_w();
}
int Actor::get_h()
{
	return agraph->get_h();
}
int Actor::get_graph_x()
{
	return agraph->get_x();
}
int Actor::get_graph_y()
{
	return agraph->get_y();
}

Mask* Actor::get_graph_mask()
{
	return agraph->get_mask();
}
void Actor::set_is_detected(bool tf)
{
	is_detectable = tf;
}
bool Actor::get_is_detected()
{
	return is_detectable;
}
void Actor::set_power(int pow)
{
	power = pow;
}
int Actor::get_power()
{
	return power;
}
void Actor::set_collision_method(CollisionManager::collision_method_t cm)
{
	collision_method = cm;
}
CollisionManager::collision_method_t Actor::get_collision_method()
{
	return collision_method;
}
void Actor::set_team(int tm)
{
	team = tm;
}
int Actor::get_team()
{
	return team;
}
void Actor::hit(Actor *who, int damage)
{

}
void Actor::add(Marca * m)
{

}

void Actor::set_invisible(bool i)
{
	is_invisible = i;
}
bool Actor::get_invisible()
{
	return is_invisible;
}

