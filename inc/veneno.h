/*
 * veneno.h
 *
 *  Created on: 7/2/2016
 *      Author: Usuario
 */

#ifndef INC_VENENO_H_
#define INC_VENENO_H_

#include "actor.h"

class Veneno : public Actor
{
public:
	Veneno(ActorManager * b);
	~Veneno();
	void move();
	void hit(Actor *a, int damage);
	static void crear_veneno(ActorManager *actmgr);
protected:
	ActorManager * am;
};



#endif /* INC_VENENO_H_ */
