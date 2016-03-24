/*
 * tiledata.cpp
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#include "tiledata.h"

TileData::TileData(tinyxml2::XMLElement * t)
{
	root_tiledata = t;
	printf("creado tiledata\n");
	parse();
}
TileData::~TileData()
{

}
void TileData::parse()
{

}
