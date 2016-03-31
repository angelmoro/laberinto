/*
 * tileimagelayer.cpp
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#include "tileimagelayer.h"
#include "tileproperty.h"
#include "tileimage.h"

//#define VERBOSE 1

TileImageLayer::TileImageLayer(tinyxml2::XMLElement * t)
{
/*
 * Establecemos valores por defecto
 */
	name = ""; // The name of the image layer.
	offsetx = 0 ; // Rendering offset of the image layer in pixels. Defaults to 0. (since 0.15)
	offsety = 0; // Rendering offset of the image layer in pixels. Defaults to 0. (since 0.15)
	opacity = 1.0; // The opacity of the layer as a value from 0 to 1. Defaults to 1.
	visible = 1; // Whether the layer is shown (1) or hidden (0). Defaults to 1.

	root_tileimagelayer = t;
#ifdef VERBOSE
	printf("creado tileimagelayer\n");
#endif
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
#ifdef VERBOSE
		printf("name no encontrado\n");
#endif
	}else {
		name = szAttributeText;
#ifdef VERBOSE
		printf("name %s\n",name.c_str());
#endif
	}
	eResult = root_tileimagelayer->QueryIntAttribute("offsetx", &offsetx);
	if (eResult != tinyxml2::XML_SUCCESS)  {
#ifdef VERBOSE
		printf("Error cargando offsetx: %i\n", eResult);
#endif
	}else{
#ifdef VERBOSE
		printf("offsetx %d\n",offsetx);
#endif
	}
	eResult = root_tileimagelayer->QueryIntAttribute("offsety", &offsety);
	if (eResult != tinyxml2::XML_SUCCESS)  {
#ifdef VERBOSE
		printf("Error cargando offsety: %i\n", eResult);
#endif
	}else{
#ifdef VERBOSE
		printf("offsety %d\n",offsety);
#endif
	}
	eResult = root_tileimagelayer->QueryFloatAttribute("opacity", &opacity);
	if (eResult != tinyxml2::XML_SUCCESS)  {
#ifdef VERBOSE
		printf("Error cargando opacity: %i\n", eResult);
#endif
	}else{
#ifdef VERBOSE
		printf("opacity %f\n",opacity);
#endif
	}
	eResult = root_tileimagelayer->QueryIntAttribute("visible", &visible);
	if (eResult != tinyxml2::XML_SUCCESS)  {
#ifdef VERBOSE
		printf("Error cargando visible: %i\n", eResult);
#endif
	}else{
#ifdef VERBOSE
		printf("visible %d\n",visible);
#endif
	}

	/*
	 * Cargamos la lista de properties
	 */
	pElement_tmp = root_tileimagelayer->FirstChildElement("properties"); //nos saltamos el tag properties
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
	pElement_tmp = root_tileimagelayer->FirstChildElement("image");
	if (pElement_tmp != NULL) {
		image = new TileImage(pElement_tmp);
	}else {
		pListElement = NULL;
#ifdef VERBOSE
		printf("no hay ningun elemento image\n");
#endif
	}
}


