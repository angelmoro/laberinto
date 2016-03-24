/*
 * tileimage.cpp
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#include "tileimage.h"

TileImage::TileImage(tinyxml2::XMLElement * t)
{
	root_tileimage = t;
	printf("creado tileimage\n");
	parse();
}
TileImage::~TileImage()
{

}
void TileImage::draw()
{

}
void TileImage::parse()
{

}
