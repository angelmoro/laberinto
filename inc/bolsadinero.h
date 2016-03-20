/*
 * bolsadinero.h
 *
 *  Created on: 25/2/2016
 *      Author: Usuario
 */

#ifndef INC_BOLSADINERO_H_
#define INC_BOLSADINERO_H_

#include "actor.h"

class BolsaDinero : public Actor
{
public:
	BolsaDinero(ActorManager * b,int mov_to_dead);
	~BolsaDinero();
	void move();
	void hit(Actor *a, int damage);
	static BolsaDinero * crear_bolsa_dinero(ActorManager *actmgr,int mov_to_dead);
protected:
	ActorManager * am;
	int movimientos;
};



#endif /* INC_BOLSADINERO_H_ */
