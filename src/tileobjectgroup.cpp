/*
 * tileobjectgroup.cpp
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#include "tileobjectgroup.h"
#include "tileproperty.h"
#include "tileobject.h"

TileObjectGroup::TileObjectGroup(tinyxml2::XMLElement * t)
{
	/*
	 * Valores por defecto
	 */
	name = ""; // The name of the object group.
	color = 0; // The color used to display the objects in this group.

	opacity = 1; // The opacity of the layer as a value from 0 to 1. Defaults to 1.
	visible = 1; // Whether the layer is shown (1) or hidden (0). Defaults to 1.
	offsetx = 0; // Rendering offset for this object group in pixels. Defaults to 0. (since 0.14)
	offsety = 0; // Rendering offset for this object group in pixels. Defaults to 0. (since 0.14)
	draworder = "topdown"; // Whether the objects are drawn according to the order of appearance ("index") or sorted by their y-coordinate ("topdown"). Defaults to "topdown".

	root_tileobjectgroup = t;
	printf("creado tileobjectgroup\n");
	parse();
}
TileObjectGroup::~TileObjectGroup()
{

}

void TileObjectGroup::parse()
{
	tinyxml2::XMLError 			eResult;
	tinyxml2::XMLElement 		* pElement_tmp;
	tinyxml2::XMLElement 		* pListElement;
	const char 					* szAttributeText;
	TileProperty				*tp;
	TileObject					*to;

	/*
	 * Se extraen todos los atributos del elemento tileset
	 */
	szAttributeText = NULL;
	szAttributeText = root_tileobjectgroup->Attribute("name");
	if (szAttributeText == NULL) {
		printf("name no encontrado\n");
	}else {
		name = szAttributeText;
		printf("name %s\n",name.c_str());
	}
	eResult = root_tileobjectgroup->QueryIntAttribute("color", &color);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando color: %i\n", eResult);
	}else{
		printf("color %d\n",color);
	}
	eResult = root_tileobjectgroup->QueryIntAttribute("opacity", &opacity);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando opacity: %i\n", eResult);
	}else{
		printf("opacity %d\n",opacity);
	}
	eResult = root_tileobjectgroup->QueryIntAttribute("visible", &visible);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando visible: %i\n", eResult);
	}else{
		printf("visible %d\n",visible);
	}
	eResult = root_tileobjectgroup->QueryIntAttribute("offsetx", &offsetx);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando offsetx: %i\n", eResult);
	}else{
		printf("offsetx %d\n",offsetx);
	}
	eResult = root_tileobjectgroup->QueryIntAttribute("offsety", &offsety);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando offsety: %i\n", eResult);
	}else{
		printf("offsety %d\n",offsety);
	}
	szAttributeText = NULL;
	szAttributeText = root_tileobjectgroup->Attribute("draworder");
	if (szAttributeText == NULL) {
		printf("draworder no encontrado\n");
	}else {
		draworder = szAttributeText;
		printf("draworder %s\n",draworder.c_str());
	}
	/*
	 * Cargamos la lista de properties
	 */
	pElement_tmp = root_tileobjectgroup->FirstChildElement("properties"); //nos saltamos el tag properties
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
	 * Cargamos la lista de objetos
	 */
	pElement_tmp = root_tileobjectgroup->FirstChildElement("object"); //nos saltamos el tag properties
	if (pElement_tmp != NULL) {
		pListElement = pElement_tmp->FirstChildElement("object");
	}else {
		pListElement = NULL;
		printf("no hay ningun elemento properties\n");
	}
	pListElement = root_tileobjectgroup->FirstChildElement("object");
	if (pListElement == NULL) {printf("no hay ningun elemento object\n");}
	while (pListElement != NULL)
	{
		to = new TileObject(pListElement);
		objects.push_back(to);
		pListElement = pListElement->NextSiblingElement("object");
	}
}

