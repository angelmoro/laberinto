/*
 * actorgraphic.h
 *
 *  Created on: 2/2/2016
 *      Author: Usuario
 */

#ifndef INC_ACTORGRAPHIC_H_
#define INC_ACTORGRAPHIC_H_

#include <allegro.h>
#include <string.h>
#include "actor.h"
#include "marca.h"

class Actor;

class ActorGraphic
{
	public:
		ActorGraphic(Actor *a);
		virtual ~ActorGraphic();
		virtual void init();
		virtual void update();
		virtual void draw();
		virtual int get_w();
		virtual int get_h();
		virtual int get_x();
		virtual int get_y();
		virtual int get_score();
		virtual int get_level();
		virtual bool nivel_activo();
		virtual bool last_level();
		virtual int get_estado();
		virtual Mask* get_mask();
		virtual string get_nombre_tmp();
		virtual list<Marca*>::iterator get_begin_iterator();
		virtual list<Marca*>::iterator get_end_iterator();
	protected:
		Actor *owner;
};



#endif /* INC_ACTORGRAPHIC_H_ */
