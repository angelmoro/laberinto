/*
 * comida.h
 *
 *  Created on: 7/2/2016
 *      Author: Usuario
 */

#ifndef INC_COMIDA_H_
#define INC_COMIDA_H_

#include "actor.h"

class Comida : public Actor
{
public:
	Comida(ActorManager * b);
	~Comida();
	void move();
	void hit(Actor *a, int damage);
	static void crear_comida(ActorManager *actmgr);
protected:
	ActorManager * am;
};




#endif /* INC_COMIDA_H_ */
