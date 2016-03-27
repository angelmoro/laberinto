/*
 * tileproperty.h
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#ifndef INC_TILEPROPERTY_H_
#define INC_TILEPROPERTY_H_

#include <string>
#include <tinyxml2.h>


class TileProperty
{
public:
	TileProperty(tinyxml2::XMLElement * t);
	~TileProperty();
	void parse();
private:

	std::string name; // The name of the property.
	std::string value; // The value of the property.
	tinyxml2::XMLElement * root_tileproperty;
};



#endif /* INC_TILEPROPERTY_H_ */
