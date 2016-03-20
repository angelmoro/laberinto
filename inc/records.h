/*
 * records.h
 *
 *  Created on: 3/3/2016
 *      Author: Usuario
 */

#ifndef INC_RECORDS_H_
#define INC_RECORDS_H_

#include <string.h>
#include <allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include "actor.h"
#include "actormanager.h"
#include "controllableobject.h"
#include "controllableactor.h"
#include "marca.h"

#define NO_STATE 		0
#define CAPTURANDO 		1
#define VISUALIZANDO 	2
#define FINAL			3

class Records : public ControllableActor
{
	public:
		Records(ActorManager * a,int max);
		~Records();
		void move();
		void hit(Actor *a, int damage);
		virtual void init();
		void add(Marca *m);
		void del(Marca *m);
		void rewind();
		Marca *next();
		Marca *current();
		void do_action(ControllableObject::action_t act, int magnitude);
		string get_nombre_tmp();
		static Records* crear_records(ActorManager *actmgr, string nombre,
										int pos_x,int pos_y, int m);
		void set_estado(int e);
		int get_estado(void);
		void almacenar_records();
		void recuperar_records();
		void purgar_records();

		list<Marca*>::iterator get_begin_iterator();
		list<Marca*>::iterator get_end_iterator();

	protected:
		ActorManager * 	am;
		int 			max_records;
		list<Marca*>	marcas;
		list<Marca*>::iterator marcas_iter;
		string 			nombre_tmp;
		int				state;
		ALLEGRO_SAMPLE 	* sonido_tecla;
};



#endif /* INC_RECORDS_H_ */
