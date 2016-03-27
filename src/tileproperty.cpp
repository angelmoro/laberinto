/*
 * tileproperty.cpp
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#include "tileproperty.h"

TileProperty::TileProperty(tinyxml2::XMLElement * t)
{
	/*
	 * Valores por defecto
	 */
	name = ""; // The name of the property.
	value = ""; // The value of the property.

	root_tileproperty = t;
	printf("creado tileproperty\n");
}
TileProperty::~TileProperty()
{

}



