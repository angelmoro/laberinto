/*
 * tileframe.cpp
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */


#include "tileframe.h"

TileFrame::TileFrame(tinyxml2::XMLElement * t)
{
	root_tileframe = t;
	printf("creado tileframe\n");
	parse();
}
TileFrame::~TileFrame()
{

}

void TileFrame::parse()
{
	tinyxml2::XMLError 		eResult;

	/*
	 * Se extraen todos los atributos del elemento tileframe
	 */
	eResult = root_tileframe->QueryIntAttribute("tileid", &tileid);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando tileid: %i\n", eResult);
	}else{
		printf("tileid %d\n",tileid);
	}
	eResult = root_tileframe->QueryIntAttribute("duration", &duration);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando duration: %i\n", eResult);
	}else{
		printf("duration %d\n",duration);
	}
}
