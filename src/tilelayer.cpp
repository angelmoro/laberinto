/*
 * tilelayer.cpp
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */


#include "tilelayer.h"
#include "tileproperty.h"
#include "tiledata.h"

TileLayer::TileLayer(tinyxml2::XMLElement * t)
{
	root_tilelayer = t;
	printf("creado tilelayer\n");
	parse();
}
TileLayer::~TileLayer()
{

}
void TileLayer::parse()
{
	tinyxml2::XMLError 			eResult;
	tinyxml2::XMLElement 		* pElement_tmp;
	tinyxml2::XMLElement 		* pListElement;
	const char 					* szAttributeText;
	TileProperty				* tp;

	/*
	 * Se extraen todos los atributos del elemento tileset
	 */
	szAttributeText = NULL;
	szAttributeText = root_tilelayer->Attribute("name");
	if (szAttributeText == NULL) {
		printf("name no encontrado\n");
	}else {
		name = szAttributeText;
		printf("name %s\n",name.c_str());
	}
	eResult = root_tilelayer->QueryFloatAttribute("opacity", &opacity);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error opacity firstgid: %i\n", eResult);
	}else{
		printf("opacity %f\n",opacity);
	}
	eResult = root_tilelayer->QueryIntAttribute("visible", &visible);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando visible: %i\n", eResult);
	}else{
		printf("visible %d\n",visible);
	}
	eResult = root_tilelayer->QueryIntAttribute("offsetx", &offsetx);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando offsetx: %i\n", eResult);
	}else{
		printf("offsetx %d\n",offsetx);
	}
	eResult = root_tilelayer->QueryIntAttribute("offsety", &offsety);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando offsety: %i\n", eResult);
	}else{
		printf("offsety %d\n",offsety);
	}
	/*
	 * Cargamos la lista de properties
	 */
	pElement_tmp = root_tilelayer->FirstChildElement("properties"); //nos saltamos el tag properties
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
	 * Creamos el elemento data si existe
	 */
	pElement_tmp = root_tilelayer->FirstChildElement("data");
	if (pElement_tmp == NULL) {
		printf("no hay ningun elemento tiledata\n");
	} else {
		data = new TileData(pElement_tmp);
	}

}
