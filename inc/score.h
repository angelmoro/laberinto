/*
 * score.h
 *
 *  Created on: 12/2/2016
 *      Author: Usuario
 */

#ifndef INC_SCORE_H_
#define INC_SCORE_H_

#include "actor.h"

class Score : public Actor
{
public:
	Score(ActorManager * b);
	~Score();
	void move();
	void suma(int puntos);
	void resta(int puntos);
	int  get_score();
	void hit(Actor *a, int damage);
	static Score* crear_score(ActorManager *actmgr, string nombre,
								int pos_x,int pos_y,bool tipo_vidas);
protected:
	ActorManager * am;
	int  score;
};




#endif /* INC_SCORE_H_ */
