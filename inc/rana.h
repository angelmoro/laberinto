/*
 * rana.h
 *
 *  Created on: 12/2/2016
 *      Author: Usuario
 */

#ifndef INC_RANA_H_
#define INC_RANA_H_

#include <allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "actor.h"
#include "rana.h"

class Rana : public Actor
{
public:
	Rana(ActorManager * b,int move_to_dead);
	~Rana();
	void move();
	void hit(Actor *a, int damage);
    static void inicializar_sonido(void);
    static void crear_rana(ActorManager *actmgr,int move_to_dead);
protected:
	ActorManager * am;
	int size;
	int saltos;
    static ALLEGRO_SAMPLE *sonido_rana;
	ALLEGRO_SAMPLE_ID sample_id;
};




#endif /* INC_RANA_H_ */
