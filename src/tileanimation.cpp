/*
 * tileanimation.cpp
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#include "tileanimation.h"
#include "tileframe.h"

//#define VERBOSE 1

TileAnimation::TileAnimation(tinyxml2::XMLElement * t)
{
	root_tileanimation = t;
#ifdef VERBOSE
	printf("creado tileanimation\n");
#endif
	parse();
}
TileAnimation::~TileAnimation()
{

}

void TileAnimation::parse()
{
	tinyxml2::XMLElement 		* pListElement;
	TileFrame					*tf;
	/*
	 * Cargamos la lista de frames
	 */

	pListElement = root_tileanimation->FirstChildElement("frame");
#ifdef VERBOSE
	if (pListElement == NULL) {printf("no hay ningun elemento frame\n");}
#endif
	while (pListElement != NULL)
	{
		tf = new TileFrame(pListElement);
		frames.push_back(tf);
		pListElement = pListElement->NextSiblingElement("frame");
	}
}
