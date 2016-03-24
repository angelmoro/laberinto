/*
 * tileproperty.cpp
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#include "tileproperty.h"

TileProperty::TileProperty(tinyxml2::XMLElement * t)
{
	root_tileproperty = t;
	printf("creado tileproperty\n");
}
TileProperty::~TileProperty()
{

}



