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
	/*
	 * Valores por defecto
	 */
	name = ""; // The name of the layer.
	opacity = 1.0; // The opacity of the layer as a value from 0 to 1. Defaults to 1.
	visible = 1; // Whether the layer is shown (1) or hidden (0). Defaults to 1.
	offsetx = 0; // Rendering offset for this layer in pixels. Defaults to 0. (since 0.14)
	offsety = 0; // Rendering offset for this layer in pixels. Defaults to 0. (since 0.14)

	root_tilelayer = t;
	printf("creado tilelayer\n");
	parse();
}
TileLayer::~TileLayer()
{

}
std::vector<int>::iterator TileLayer::get_begin_iterator()
{
	return data->get_begin_iterator();
}
std::vector<int>::iterator TileLayer::get_end_iterator()
{
	return data->get_end_iterator();
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
		printf("Error opacity: %i\n", eResult);
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
int TileLayer::get_offsetx()
{
	return offsetx;
}
int TileLayer::get_offsety()
{
	return offsety;
}
int TileLayer::get_tile_gid(int pos)
{
	return data->get_tile_gid(pos);
}
bool TileLayer::get_visible()
{
	return visible;
}
std::string TileLayer::get_name()
{
	return name;
}
