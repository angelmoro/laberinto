/*
 * peripheral.h
 *
 *  Created on: 30/1/2016
 *      Author: Usuario
 */

#ifndef INC_PERIPHERAL_H_
#define INC_PERIPHERAL_H_

#include <string>
#include <allegro.h>

#define INVALID_STATE -2
#define INVALID_COMPONENT -2

using namespace std;

class Peripheral
{
	public:
		typedef enum event_t
		{
			NO_EVENT,
			ON_PRESS,
			ON_RELEASE,
			ON_PRESSING,
			ON_RELEASSING,
		} event_t;
		typedef int state_t;
		typedef int component_t;
		Peripheral();
		virtual ~Peripheral();
		virtual state_t get_state(component_t comp);
		virtual component_t get_change();
		virtual string get_component_name(component_t comp);
		virtual void reset();
		virtual void evento(ALLEGRO_EVENT);

};



#endif /* INC_PERIPHERAL_H_ */
