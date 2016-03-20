/*
 * game.h
 *
 *  Created on: 29/1/2016
 *      Author: Usuario
 */

#ifndef INC_GAME_H_
#define INC_GAME_H_

#include <string>
#include <allegro.h>
#include "actormanager.h"
#include "controlmanager.h"
#include "collisionmanager.h"
#include "levelmanager.h"

using namespace std;

class ActorManager;
class StageManager;
class CollisionManager;
class LevelManager;


class Game
{
	public:
		Game();
		virtual ~Game();
		ActorManager *actor_manager;
		StageManager *stage_manager;
		ControlManager *control_manager;
		CollisionManager *collision_manager;
		LevelManager	*level_manager;
		virtual void init(void);
		virtual void main();
		void set_name(string name);
		void set_ancho(int an);
		void set_alto(int al);
		string get_name();
		static int rnd(int rb,int ra);
		static int gfx_w,gfx_h;

	protected:
		string name;
		void update();

		int colors;
		ALLEGRO_EVENT_QUEUE *event_queue;
		ALLEGRO_EVENT event;
		ALLEGRO_TIMER *timer;
	private:
		int  tick;
		void start();
		void shutdown(string message="Gracias por jugar");
		virtual void create_actormanager();
		virtual void create_stagemanager();
		virtual void create_controlmanager();
		virtual void create_collisionmanager();
		virtual void create_levelmanager();
};



#endif /* INC_GAME_H_ */
