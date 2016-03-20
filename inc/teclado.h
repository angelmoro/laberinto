/*
 * teclado.h
 *
 *  Created on: 31/1/2016
 *      Author: Usuario
 */

#ifndef INC_TECLADO_H_
#define INC_TECLADO_H_

#include <allegro.h>
#include "peripheral.h"



typedef struct
{
 int evento_sin_consumir;
 ALLEGRO_EVENT evento;
} ultimo_evento_t;



/*
 * definimos los estados de la tecla
 */

#define KEY_PRESS   0
#define KEY_RELEASE 1



class Teclado : public Peripheral
{
	public:
		Teclado();
		virtual ~Teclado();
		state_t get_state(component_t comp);
		component_t get_change();
		string get_component_name(component_t comp);
		void reset();
		void evento(ALLEGRO_EVENT e);

	protected:
		//int old_state[ALLEGRO_KEY_MAX];
		ultimo_evento_t ue[ALLEGRO_KEY_MAX];

};



#endif /* INC_TECLADO_H_ */
