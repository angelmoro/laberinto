/*
 * actor.h
 *
 *  Created on: 28/1/2016
 *      Author: Usuario
 */

#ifndef INC_ACTOR_H_
#define INC_ACTOR_H_

#include <allegro.h>
#include <string.h>
#include "game.h"
#include "actorgraphic.h"
#include "collisionmanager.h"
#include "marca.h"


/*
 * definimos los equipos a los que perteneceran los actores
 */

#define NO_TEAM					-1
#define TEAM_HORMIGAS_ROJAS  	 0
#define TEAM_HORMIGAS_VERDES 	 1
#define TEAM_OSO 				 2
#define TEAM_COMIDA 			 3
#define TEAM_VENENO 			 4
#define TEAM_AGUA 				 5
#define TEAM_HORMIGUERO			 6
#define TEAM_RANA			     7
#define TEAM_SCORE               8
#define TEAM_SEMILLA			 9
#define TEAM_BOLSA_DINERO		10
#define TEAM_LEVEL				11
#define TEAM_RECORDS			12

/*
 * Direccion del actor
 */

#define SIN_MOVIMIENTO	0
#define IZQUIERDA		1
#define DERECHA			2
#define ARRIBA			3
#define ABAJO			4

/*
 * ultimo movimiento registrado
 */

#define EJE_X	0
#define EJE_Y	1

class ActorGraphic;

class Actor
{
	public:
		Actor();
		virtual ~Actor();
		virtual void draw();
		virtual void update();
		virtual void move();
		virtual void init();
		virtual int get_w();
		virtual int get_h();
		virtual int get_score();
		virtual int get_level();
		virtual bool nivel_activo();
		virtual bool last_level();
		virtual int get_estado();
		virtual void set_estado(int e);
		virtual string get_nombre_tmp();
		virtual void add(Marca* m);
		virtual list<Marca*>::iterator get_begin_iterator();
		virtual list<Marca*>::iterator get_end_iterator();

		void set_x(int pos_x);
		void set_y(int pos_y);

		void set_actor_graphic(ActorGraphic *ag);
		int get_x();
		int get_y();
		//TBD los dos siguientes metodos no los utiliza nadie
		// y creo que no valen para nada. Son equivalentes a
		// get_x() y get_y() dando vueltas a traves de actorgraphic

		//int get_graph_x();
		//int get_graph_y();


		Mask *get_graph_mask();
		void set_is_detected(bool tf);
		bool get_is_detected();
		void set_power(int pow);
		int get_power();
		void set_collision_method(CollisionManager::collision_method_t cm);
		CollisionManager::collision_method_t get_collision_method();
		virtual void hit(Actor *who, int damage);
		virtual void hit(std::string objeto, int damage);
		void set_team(int tm);
		int get_team();
		void set_invisible(bool i);
		bool get_invisible();
		void deshacer_posicion();

	protected:
		int x, y;
		int direccion_x,direccion_y;
		int ultimo_movimiento;
		ActorGraphic *agraph;
		char * name;
		int power;
		int team;
		bool is_detectable;
		bool is_invisible;
		CollisionManager::collision_method_t collision_method;

};

#endif /* INC_ACTOR_H_ */
