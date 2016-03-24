/*
 * tileproperty.h
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#ifndef INC_TILEPROPERTY_H_
#define INC_TILEPROPERTY_H_

#include <string>

using namespace std;

class TileProperty
{
public:
	TileProperty();
	~TileProperty();
private:

	string name; // The name of the property.
	string value; // The value of the property.

};



#endif /* INC_TILEPROPERTY_H_ */
