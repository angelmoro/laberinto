/*
 * tileterrain.cpp
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#include "tileterrain.h"
#include "tileproperty.h"

TileTerrain::TileTerrain(tinyxml2::XMLElement * t)
{
	root_tileterrain = t;
	printf("creado tileterrain\n");
	parse();
}
TileTerrain::~TileTerrain()
{

}
void TileTerrain::parse()
{
	tinyxml2::XMLError 			eResult;
	tinyxml2::XMLElement 		* pElement_tmp;
	tinyxml2::XMLElement 		* pListElement;
	const char 					* szAttributeText;
	TileProperty				*tp;

	/*
	 * Se extraen todos los atributos del elemento tileset
	 */

	szAttributeText = NULL;
	szAttributeText = root_tileterrain->Attribute("name");
	if (szAttributeText == NULL) {
		printf("name no encontrado\n");
	}else {
		name = szAttributeText;
		printf("name %s\n",name.c_str());
	}

	eResult = root_tileterrain->QueryIntAttribute("tile", &tile);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando tile: %i\n", eResult);
	}else{
		printf("tile %d\n",tile);
	}

	/*
	 * Cargamos la lista de properties
	 */
	pElement_tmp = root_tileterrain->FirstChildElement("properties"); //nos saltamos el tag properties
	if (pElement_tmp != NULL) {
		pListElement = pElement_tmp->FirstChildElement("property");
	}else {
		pListElement = NULL;
		printf("no hay ningun elemento properties\n");
	}
	if (pListElement == NULL) {printf("no hay ningun elemento property\n");}
	while (pListElement != NULL)
	{
		tp = new TileProperty(pListElement);
		properties.push_back(tp);
		pListElement = pListElement->NextSiblingElement("property");
	}
}

