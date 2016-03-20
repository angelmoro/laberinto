/*
 * marca.h
 *
 *  Created on: 5/3/2016
 *      Author: Usuario
 */

#ifndef INC_MARCA_H_
#define INC_MARCA_H_

#include <string>
#include "ijsonserializable.h"

using namespace std;

class Marca : public IJsonSerializable
{
	public:
		Marca();
		~Marca();
		void set_nombre(string s);
		string get_nombre();
		void set_puntuacion(int p);
		void set_level(int l);
		int get_puntuacion();
		int get_level();
	    virtual void Serialize( Json::Value& root );
	    virtual void Deserialize( Json::Value& root);
	    static bool compara(Marca * m1,Marca * m2);

	protected:
		string nombre;
		int puntuacion;
		int level;

};




#endif /* INC_MARCA_H_ */
