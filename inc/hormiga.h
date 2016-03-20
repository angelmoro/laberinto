/*
 * hormiga.h
 *
 *  Created on: 29/1/2016
 *      Author: Usuario
 */

#ifndef INC_HORMIGA_H_
#define INC_HORMIGA_H_

#define ANCHO_ICONO 30
#define ALTO_ICONO  30

#include <allegro.h>
#include "actor.h"
#include "hormiguero.h"
#include "score.h"


#define kNoBorn 0
#define kForage 1
#define kGoHome 2
#define kThirsty 3



#define kRedAnt   1
#define kGreenAnt 2
#define MIN_HORMIGAS 3
#define MAX_HORMIGAS 30

class Hormiga : public Actor
{
public:
	Hormiga(ActorManager * b,Hormiguero *h,int t);
	~Hormiga();
	void move();
	void hit(Actor *a, int damage);
	static void crear_hormiga(ActorManager *actmgr, int tipo, Hormiguero * hormiguero_tmp,
								int pos_x=0,int pos_y=0);
	static int num_hormigas_verdes;
	static int num_hormigas_rojas;
protected:
	int				state;
	ActorManager	* am;
	int 			tipo;
	Hormiguero 		*Hm;
	int 			size;
	void Forage(void);
	void GoHome(void);
	void Thirsty(void);

};


#endif /* INC_HORMIGA_H_ */
