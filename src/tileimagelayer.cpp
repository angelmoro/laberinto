/*
 * tileimagelayer.cpp
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#include "tileimagelayer.h"
#include "tinyxml2.h"



TileImageLayer::TileImageLayer(tinyxml2::XMLElement * t)
{
	root_tileimagelayer = t;
	printf("creado tileimagelayer\n");
}
TileImageLayer::~TileImageLayer()
{

}


