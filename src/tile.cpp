/*
 * tile.cpp
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */


#include "tile.h"
#include "tileproperty.h"
#include "tileanimation.h"
#include "tileobjectgroup.h"
#include "tileimage.h"

Tile::Tile(tinyxml2::XMLElement * t)
{
	root_tile = t;
	printf("creado tile\n");
	parse();
}
Tile::~Tile()
{

}
void Tile::parse()
{
	tinyxml2::XMLError 			eResult;
	tinyxml2::XMLElement 		* pElement_tmp;
	tinyxml2::XMLElement 		* pListElement;
	const char 					* szAttributeText;
	TileProperty				*tp;

	/*
	 * Se extraen todos los atributos del elemento tileset
	 */
	eResult = root_tile->QueryIntAttribute("id", &id);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando id: %i\n", eResult);
	}else{
		printf("id %d\n",id);
	}
	szAttributeText = NULL;
	szAttributeText = root_tile->Attribute("terrain");
	if (szAttributeText == NULL) {
		printf("terrain no encontrado\n");
	}else {
		terrain = szAttributeText;
		printf("terrain %s\n",terrain.c_str());
	}
	eResult = root_tile->QueryIntAttribute("probability", &probability);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando probability: %i\n", eResult);
	}else{
		printf("probability %d\n",probability);
	}
	/*
	 * Cargamos la lista de properties
	 */
	pElement_tmp = root_tile->FirstChildElement("properties"); //nos saltamos el tag properties
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
	/*
	 * Cargamos la imagen si existe
	 */
	pElement_tmp = root_tile->FirstChildElement("image");
	if (pElement_tmp != NULL) {
		image = new TileImage(pElement_tmp);
	}else {
		pListElement = NULL;
		printf("no hay ningun elemento image\n");
	}
	/*
	 * Cargamos la animacion si existe
	 */
	pElement_tmp = root_tile->FirstChildElement("animation");
	if (pElement_tmp != NULL) {
		animation = new TileAnimation(pElement_tmp);
	}else {
		pListElement = NULL;
		printf("no hay ningun elemento animation\n");
	}
	/*
	 * Cargamos el objectgroup si existe
	 */
	pElement_tmp = root_tile->FirstChildElement("objectgroup");
	if (pElement_tmp != NULL) {
		objectgroup = new TileObjectGroup(pElement_tmp);
	}else {
		pListElement = NULL;
		printf("no hay ningun elemento objectgroup\n");
	}
}



