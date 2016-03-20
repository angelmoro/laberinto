/*
 * levelosoconf.h
 *
 *  Created on: 6/3/2016
 *      Author: Usuario
 */

#ifndef INC_LEVELOSOCONF_H_
#define INC_LEVELOSOCONF_H_

#include <string>
#include "ijsonserializable.h"

using namespace std;

class LevelOsoConf : public IJsonSerializable
{
public:
	LevelOsoConf();
	~LevelOsoConf();
	void set_peso_comida(float p);
	void set_peso_agua(float p);
	void set_peso_veneno(float p);
	void set_peso_hormigas_verdes(float p);
	void set_peso_hormigas_rojas(float p);
	void set_peso_rana_ticks(float p);
	void set_peso_bolsa_ticks(float p);
	void set_peso_rana_to_dead(float p);
	void set_peso_bolsa_to_dead(float p);
	void set_r_ticks(int p);
	void set_b_ticks(int p);
	void set_r_mov_to_dead(int p);
	void set_b_mov_to_dead(int p);
	void set_key_pad(bool p);
	float get_peso_comida();
	float get_peso_agua();
	float get_peso_veneno();
	float get_peso_hormigas_verdes();
	float get_peso_hormigas_rojas();
	float get_peso_rana_ticks();
	float get_peso_bolsa_ticks();
	float get_peso_rana_to_dead();
	float get_peso_bolsa_to_dead();
	int get_r_ticks();
	int get_b_ticks();
	int get_r_mov_to_dead();
	int get_b_mov_to_dead();
	bool get_key_pad();
	void cargar_configuracion();
	void almacenar_configuracion();
    virtual void Serialize( Json::Value& root );
    virtual void Deserialize( Json::Value& root);

private:
	float peso_comida;
	float peso_agua;
	float peso_veneno;
	float peso_hormigas_verdes;
	float peso_hormigas_rojas;

	float peso_rana_ticks;
	float peso_bolsa_ticks;
	float peso_rana_to_dead;
	float peso_bolsa_to_dead;

	/*
	 * fijamos los ticks base para la rana y la bolsa de dinero, con esto se fija
	 * el tiempo cada cuanto aparecen 70 ticks es un segundo. El ritmo de ticks podría
	 * variar en game.
	 */
	int r_ticks;
	int b_ticks;
	/*
	 * Fijamos los saltos antes de desaparecer, esto depende de el nunero de veces que
	 * se actualiza el estado de los actores. Este ritmo tambien esta en game
	 */
	int r_mov_to_dead;
	int b_mov_to_dead;

	/*
	 * Si queremos usar el keypad para controlar al oso
	 */
	bool key_pad;

};


#endif /* INC_LEVELOSOCONF_H_ */
