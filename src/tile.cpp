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

//#define VERBOSE 1


Tile::Tile(tinyxml2::XMLElement * t)
{
	/*
	 * Valores por defecto
	 */
	id = -1; // The local tile ID within its tileset.
	terrain = ""; // Defines the terrain type of each corner of the tile, given as comma-separated indexes in the terrain types array in the order top-left, top-right, bottom-left, bottom-right. Leaving out a value means that corner has no terrain. (optional) (since 0.9)
	probability = 0; // A percentage indicating the probability that this tile is chosen when it competes with others while editing with the terrain tool. (optional) (since 0.9)

	root_tile = t;
#ifdef VERBOSE
	printf("creado tile\n");
#endif
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
#ifdef VERBOSE
		printf("Error cargando id: %i\n", eResult);
#endif
	}else{
#ifdef VERBOSE
		printf("id %d\n",id);
#endif
	}
	szAttributeText = NULL;
	szAttributeText = root_tile->Attribute("terrain");
	if (szAttributeText == NULL) {
#ifdef VERBOSE
		printf("terrain no encontrado\n");
#endif
	}else {
		terrain = szAttributeText;
#ifdef VERBOSE
		printf("terrain %s\n",terrain.c_str());
#endif
	}
	eResult = root_tile->QueryIntAttribute("probability", &probability);
	if (eResult != tinyxml2::XML_SUCCESS)  {
#ifdef VERBOSE
		printf("Error cargando probability: %i\n", eResult);
#endif
	}else{
#ifdef VERBOSE
		printf("probability %d\n",probability);
#endif
	}
	/*
	 * Cargamos la lista de properties
	 */
	pElement_tmp = root_tile->FirstChildElement("properties"); //nos saltamos el tag properties
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
	/*
	 * Cargamos la imagen si existe
	 */
	pElement_tmp = root_tile->FirstChildElement("image");
	if (pElement_tmp != NULL) {
		image = new TileImage(pElement_tmp);
	}else {
		pListElement = NULL;
#ifdef VERBOSE
		printf("no hay ningun elemento image\n");
#endif
	}
	/*
	 * Cargamos la animacion si existe
	 */
	pElement_tmp = root_tile->FirstChildElement("animation");
	if (pElement_tmp != NULL) {
		animation = new TileAnimation(pElement_tmp);
	}else {
		pListElement = NULL;
#ifdef VERBOSE
		printf("no hay ningun elemento animation\n");
#endif
	}
	/*
	 * Cargamos el objectgroup si existe
	 */
	pElement_tmp = root_tile->FirstChildElement("objectgroup");
	if (pElement_tmp != NULL) {
		objectgroup = new TileObjectGroup(pElement_tmp);
	}else {
		pListElement = NULL;
#ifdef VERBOSE
		printf("no hay ningun elemento objectgroup\n");
#endif
	}
}
std::list<TileProperty*>::iterator Tile::get_properties_begin_iterator()
{
	return properties.begin();
}
std::list<TileProperty*>::iterator Tile::get_properties_end_iterator()
{
	return properties.end();
}
int Tile::get_id()
{
	return id;
}


