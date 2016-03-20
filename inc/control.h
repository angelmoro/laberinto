/*
 * control.h
 *
 *  Created on: 30/1/2016
 *      Author: Usuario
 */

#ifndef INC_CONTROL_H_
#define INC_CONTROL_H_

#include <list>
#include <string>
#include "peripheral.h"
#include "controllableobject.h"

class Control
{
	public:
		typedef struct
		{
			ControllableObject::action_t act;
			string name;
			Peripheral *peri;
			Peripheral::component_t comp;
			Peripheral::event_t event;
		}association_t;
		void add_action_name(ControllableObject::action_t act, string str);
		void add_association(association_t asoc);
		void set_actionperipheral(ControllableObject::action_t act,
		Peripheral* peri, Peripheral::component_t comp,
		Peripheral::event_t e);
		void set_owner(ControllableObject*);
		void update();
		string get_name_action(ControllableObject::action_t);
		void reset();
	protected:
		ControllableObject *owner;
		list<association_t> associations;
		list<association_t>::iterator associations_iter;
};



#endif /* INC_CONTROL_H_ */
