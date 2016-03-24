/*
 * tileanimation.cpp
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#include "tileanimation.h"
#include "tileframe.h"

TileAnimation::TileAnimation(tinyxml2::XMLElement * t)
{
	root_tileanimation = t;
	printf("creado tileanimation\n");
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
	if (pListElement == NULL) {printf("no hay ningun elemento frame\n");}
	while (pListElement != NULL)
	{
		tf = new TileFrame(pListElement);
		frames.push_back(tf);
		pListElement = pListElement->NextSiblingElement("frame");
	}
}
