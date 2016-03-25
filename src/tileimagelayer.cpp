/*
 * tileimagelayer.cpp
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#include "tileimagelayer.h"
#include "tileproperty.h"
#include "tileimage.h"



TileImageLayer::TileImageLayer(tinyxml2::XMLElement * t)
{
/*
 * Establecemos valores por defecto
 */
	offsetx = 0;
	offsety = 0;
	opacity = 1;
	visible = 1; // la version de tiled que estoy usando no genera el atributo "visible"	TBD

	root_tileimagelayer = t;
	printf("creado tileimagelayer\n");
	parse();
}
TileImageLayer::~TileImageLayer()
{

}
void TileImageLayer::draw()
{
	if (visible) image->draw(offsetx,offsety,opacity);
}
void TileImageLayer::parse()
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
	szAttributeText = root_tileimagelayer->Attribute("name");
	if (szAttributeText == NULL) {
		printf("name no encontrado\n");
	}else {
		name = szAttributeText;
		printf("name %s\n",name.c_str());
	}
	eResult = root_tileimagelayer->QueryIntAttribute("offsetx", &offsetx);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando offsetx: %i\n", eResult);
	}else{
		printf("offsetx %d\n",offsetx);
	}
	eResult = root_tileimagelayer->QueryIntAttribute("offsety", &offsety);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando offsety: %i\n", eResult);
	}else{
		printf("offsety %d\n",offsety);
	}
	eResult = root_tileimagelayer->QueryFloatAttribute("opacity", &opacity);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando opacity: %i\n", eResult);
	}else{
		printf("opacity %f\n",opacity);
	}
	eResult = root_tileimagelayer->QueryIntAttribute("visible", &visible);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando visible: %i\n", eResult);
	}else{
		printf("visible %d\n",visible);
	}

	/*
	 * Cargamos la lista de properties
	 */
	pElement_tmp = root_tileimagelayer->FirstChildElement("properties"); //nos saltamos el tag properties
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
	pElement_tmp = root_tileimagelayer->FirstChildElement("image");
	if (pElement_tmp != NULL) {
		image = new TileImage(pElement_tmp);
	}else {
		pListElement = NULL;
		printf("no hay ningun elemento image\n");
	}
}


