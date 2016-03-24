/*
 * tileobjectgroup.cpp
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#include "tileobjectgroup.h"

TileObjectGroup::TileObjectGroup(tinyxml2::XMLElement * t)
{
	root_tileobjectgroup = t;
	printf("creado tileobjectgroup\n");
}
TileObjectGroup::~TileObjectGroup()
{

}



