/*
 * agua.h
 *
 *  Created on: 7/2/2016
 *      Author: Usuario
 */

#ifndef INC_AGUA_H_
#define INC_AGUA_H_

#include "actor.h"

class Agua : public Actor
{
public:
	Agua(ActorManager * b);
	~Agua();
	void move();
	void hit(Actor *a, int damage);
	static void crear_agua(ActorManager *actmgr);
protected:
	ActorManager * am;
};



#endif /* INC_AGUA_H_ */
