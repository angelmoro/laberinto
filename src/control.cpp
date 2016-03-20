/*
 * control.cpp
 *
 *  Created on: 30/1/2016
 *      Author: Usuario
 */

#include <allegro.h>
#include "peripheral.h"
#include "control.h"
#include <stdio.h>
#include "osohormiguero.h"
#include "teclado.h"

void Control::add_action_name(ControllableObject::action_t act, string str)
{
	association_t asoc;
	asoc.act = act;
	asoc.name= str;
	asoc.peri= NULL;
	asoc.comp= -1;
	associations.push_back(asoc);
}
void Control::set_actionperipheral(ControllableObject::action_t act,
									Peripheral* peri,
									Peripheral::component_t comp,
									Peripheral::event_t e)
{
	for (associations_iter=associations.begin();
		associations_iter!=associations.end();
		associations_iter++)
	{
		if (associations_iter->act == act)
		{
			associations_iter->peri=peri;
			associations_iter->comp=comp;
			associations_iter->event=e;
			return;
		}
	}
}
void Control::add_association(Control::association_t assoc)
{
	associations.push_back(assoc);
}
void Control::set_owner(ControllableObject* co)
{
	owner=co;
}
void Control::update()
{
	int do_action_order;
	Peripheral::state_t tmp_state;

	for (associations_iter=associations.begin();
		associations_iter!=associations.end();
		associations_iter++)
	{

		tmp_state=associations_iter->peri->get_state(associations_iter->comp);
		do_action_order=false;

		switch(associations_iter->event)
		{
			case Peripheral::ON_PRESS:
//			case Peripheral::ON_PRESSING:
				if (tmp_state == KEY_PRESS) do_action_order=true;
				break;
			case Peripheral::ON_RELEASE:
//			case Peripheral::ON_RELEASSING:
				if (tmp_state == KEY_RELEASE) do_action_order=true;
				break;
			default:
				break;
		}


		if (do_action_order)
		{
		//creo que el tmp_state no es lo adecuado a pasar en el segundo parametro
		// pongo un 1 a capon, creo que haria falta otro parametro que viniera del
		//periferico concreto para reflejar la intensidad
			if (owner != NULL)
				owner->do_action(associations_iter->act, 1);
		}

	}
}
string Control::get_name_action(ControllableObject::action_t act)
{
	for (associations_iter=associations.begin();
		associations_iter!=associations.end();
		associations_iter++)
	{
		if (associations_iter->act == act)
		{
			return associations_iter->name;
		}
	}
	return "";
}

