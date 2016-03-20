/*
 * hormiguero.h
 *
 *  Created on: 7/2/2016
 *      Author: Usuario
 */

#ifndef INC_HORMIGUERO_H_
#define INC_HORMIGUERO_H_

#include "actor.h"



class Hormiguero : public Actor
{
public:
	Hormiguero(ActorManager * b);
	~Hormiguero();
	void move();
	void hit(Actor *a, int damage);
	static Hormiguero* crear_hormiguero(ActorManager *actmgr);
protected:
	ActorManager * am;
};




#endif /* INC_HORMIGUERO_H_ */
