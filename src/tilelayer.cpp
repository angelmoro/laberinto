/*
 * tilelayer.cpp
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */


#include "tilelayer.h"

TileLayer::TileLayer(tinyxml2::XMLElement * t)
{
	root_tilelayer = t;
	printf("creado tilelayer\n");
}
TileLayer::~TileLayer()
{

}

