/*
 * controlmanager.h
 *
 *  Created on: 30/1/2016
 *      Author: Usuario
 */

#ifndef INC_CONTROLMANAGER_H_
#define INC_CONTROLMANAGER_H_

#include <vector>
#include "control.h"
#include "peripheral.h"
#define MAXPERIPHERALS 5

class ControlManager
{
	public:
		ControlManager();
		~ControlManager();
		typedef struct
		{
			Peripheral *p;
			Peripheral::component_t comp;
		}change_t;
		change_t get_change();
		int add_control(Control *ctrl);
		int add_peripheral(Peripheral *periph);
		Control *get_control(int number);
		Peripheral *get_peripheral(int number);
		void update();
	protected:
		vector<Control*> controls;
		vector<Control*>::iterator controls_iter;
		vector<Peripheral*> peripherals;
		vector<Peripheral*>::iterator peripherals_iter;
		int old_state[MAXPERIPHERALS];


};



#endif /* INC_CONTROLMANAGER_H_ */
