/*
 * leveloso.h
 *
 *  Created on: 27/2/2016
 *      Author: Usuario
 */

#ifndef INC_LEVELOSO_H_
#define INC_LEVELOSO_H_

#include <string.h>
#include <allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include "level.h"

class LevelOso : public Level
{
public:
	LevelOso(ActorManager * b,LevelManager *l,int n,int c,int a, int v, int hv, int hr,
			 int rt, int bt, int rtd, int btd);
	~LevelOso();
	 void init();
	 void iniciar();
	 void create();
	 void destroy();
	 static LevelOso* crear_level(ActorManager *actmgr,LevelManager *levmgr, string nombre,int nivel,
	 		                     int c,int a,int v,int hv,int hr, int pos_x,int pos_y,
								 int rt, int bt, int rtd, int btd);
	 static void crear_niveles(int niveles,ActorManager * actmgr,LevelManager * levmgr);
	 void tick();
protected:
	 int comida,agua,veneno,hormigas_verdes,hormigas_rojas;
	 int rana_ticks,bolsa_dinero_ticks; //contadores de trabajo
	 int rana_ticks_fijados,bolsa_dinero_ticks_fijados;//ticks fijados para el nivel
	 int rana_mov_to_dead, bolsa_dinero_mov_to_dead;
	 int ticks_inicializado,ticks_destruido;
	 ALLEGRO_SAMPLE 	* sonido_fin_nivel;
	 ALLEGRO_SAMPLE 	* sonido_game_over;

};



#endif /* INC_LEVELOSO_H_ */
