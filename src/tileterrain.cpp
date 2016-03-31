/*
 * tileterrain.cpp
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#include "tileterrain.h"
#include "tileproperty.h"

//#define VERBOSE 1

TileTerrain::TileTerrain(tinyxml2::XMLElement * t)
{
	/*
	 * Valores por defecto
	 */
	name = ""; // The name of the terrain type.
	tile = -1; // The local tile-id of the tile that represents the terrain visually

	root_tileterrain = t;
#ifdef VERBOSE
	printf("creado tileterrain\n");
#endif
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
#ifdef VERBOSE
		printf("name no encontrado\n");
#endif
	}else {
		name = szAttributeText;
#ifdef VERBOSE
		printf("name %s\n",name.c_str());
#endif
	}

	eResult = root_tileterrain->QueryIntAttribute("tile", &tile);
	if (eResult != tinyxml2::XML_SUCCESS)  {
#ifdef VERBOSE
		printf("Error cargando tile: %i\n", eResult);
#endif
	}else{
#ifdef VERBOSE
		printf("tile %d\n",tile);
#endif
	}

	/*
	 * Cargamos la lista de properties
	 */
	pElement_tmp = root_tileterrain->FirstChildElement("properties"); //nos saltamos el tag properties
	if (pElement_tmp != NULL) {
		pListElement = pElement_tmp->FirstChildElement("property");
	}else {
		pListElement = NULL;
#ifdef VERBOSE
		printf("no hay ningun elemento properties\n");
#endif
	}
#ifdef VERBOSE
	if (pListElement == NULL) {printf("no hay ningun elemento property\n");}
#endif
	while (pListElement != NULL)
	{
		tp = new TileProperty(pListElement);
		properties.push_back(tp);
		pListElement = pListElement->NextSiblingElement("property");
	}
}

