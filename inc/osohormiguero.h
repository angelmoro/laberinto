/*
 * osohormigero.h
 *
 *  Created on: 30/1/2016
 *      Author: Usuario
 */

#ifndef INC_OSOHORMIGUERO_H_
#define INC_OSOHORMIGUERO_H_


#include <allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "actor.h"
#include "controllableactor.h"
#include "score.h"


class OsoHormiguero : public ControllableActor
{
public:
	OsoHormiguero(ActorManager * b,Score * s,Score * s1);
	~OsoHormiguero(void);

	typedef enum
	{
		DOWN,
		UP,
		LEFT,
		RIGHT,
		ANIQUILACION
	}action_t;

	void do_action(ControllableObject::action_t act, int magnitude);
	void hit(Actor *a, int damage);
	void hit(std::string objeto, int damage);
	static OsoHormiguero * crear_osohormiguero(ActorManager *actmgr,Score *score_tmp,
												Score *score_tmp1);
	int get_puntuacion();



protected:
	ActorManager	* am;
	Score			* sc;
	int 			size;
	ALLEGRO_SAMPLE 	* sonido_comer_hormiga;
	ALLEGRO_SAMPLE 	* sonido_comer_bolsa;
	ALLEGRO_SAMPLE 	* sonido_perdida_vida;
	Score        	* sc_vidas;
	bool			activo;

private:
	void check_salud();
	void aniquilacion();
};




#endif /* INC_OSOHORMIGUERO_H_ */
