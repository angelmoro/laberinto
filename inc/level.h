/*
 * level.h
 *
 *  Created on: 26/2/2016
 *      Author: Usuario
 */

#ifndef INC_LEVEL_H_
#define INC_LEVEL_H_

#include <string>
#include "actor.h"
#include "actormanager.h"
#include "levelmanager.h"
#include "controllableobject.h"


#define NO_ESTADO    0
#define INICIALIZADO 1
#define CREADO		 2
#define DESTRUIDO	 3


class Level : public Actor
{
public:
	/*
	typedef enum estado_t
		{
			NO_ESTADO,
			INICIALIZADO,
			CREADO,
			DESTRUIDO,
		} estado_t;
		*/
	Level(ActorManager * a,LevelManager * l,int n);
	~Level();
	void move();
	void hit(Actor *a, int damage);
	virtual void init();
	virtual void iniciar();
	virtual void create();
	virtual void destroy();
	virtual void tick();
	int get_level();
	bool nivel_activo();
	void set_activo(bool a);
	void set_estado(int e);
	int get_estado();
	bool last_level();
	void set_last_level(bool b);

protected:
	ActorManager * am;
	LevelManager * le;
	int num_nivel;
	bool activo;
	int estado;
	bool ultimo_nivel;
	string nombre_tmp;
};






#endif /* INC_LEVEL_H_ */
