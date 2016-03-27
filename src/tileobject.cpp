/*
 * tileobject.cpp
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */


#include "tileobject.h"
#include "tileproperty.h"
#include "tileimage.h"

TileObject::TileObject(tinyxml2::XMLElement * t)
{
	/*
	 * Valores por defecto
	 */
	id = -1; // Unique ID of the object. Each object that is placed on a map gets a unique id. Even if an object was deleted, no object gets the same ID. Can not be changed in Tiled Qt. (since Tiled 0.11)
	name = ""; // The name of the object. An arbitrary string.
	type = ""; // The type of the object. An arbitrary string.
	x = 0; // The x coordinate of the object in pixels.
	y = 0; // The y coordinate of the object in pixels.
	width = 0; // The width of the object in pixels (defaults to 0).
	height = 0; // The height of the object in pixels (defaults to 0).
	rotation = 0; // The rotation of the object in degrees clockwise (defaults to 0). (since 0.10)
	gid = -1; // An reference to a tile (optional).
	visible = 1; // Whether the object is shown (1) or hidden (0). Defaults to 1. (since 0.9)

	root_tileobject = t;
	printf("creado tileobject\n");
	parse();
}
TileObject::~TileObject()
{

}

void TileObject::parse()
{
	tinyxml2::XMLError 			eResult;
	tinyxml2::XMLElement 		* pElement_tmp;
	tinyxml2::XMLElement 		* pListElement;
	const char 					* szAttributeText;
	TileProperty				*tp;

	/*
	 * Se extraen todos los atributos del elemento tileset
	 */
	eResult = root_tileobject->QueryIntAttribute("id", &id);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando id: %i\n", eResult);
	}else{
		printf("id %d\n",id);
	}
	szAttributeText = NULL;
	szAttributeText = root_tileobject->Attribute("name");
	if (szAttributeText == NULL) {
		printf("name no encontrado\n");
	}else {
		name = szAttributeText;
		printf("name %s\n",name.c_str());
	}
	szAttributeText = NULL;
	szAttributeText = root_tileobject->Attribute("type");
	if (szAttributeText == NULL) {
		printf("type no encontrado\n");
	}else {
		type = szAttributeText;
		printf("type %s\n",type.c_str());
	}
	eResult = root_tileobject->QueryIntAttribute("x", &x);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando x: %i\n", eResult);
	}else{
		printf("x %d\n",x);
	}
	eResult = root_tileobject->QueryIntAttribute("y", &y);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando y: %i\n", eResult);
	}else{
		printf("y %d\n",y);
	}
	eResult = root_tileobject->QueryIntAttribute("width", &width);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando width: %i\n", eResult);
	}else{
		printf("width %d\n",width);
	}
	eResult = root_tileobject->QueryIntAttribute("height", &height);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando height: %i\n", eResult);
	}else{
		printf("height %d\n",height);
	}
	eResult = root_tileobject->QueryIntAttribute("rotation", &rotation);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando rotation: %i\n", eResult);
	}else{
		printf("rotation %d\n",rotation);
	}
	eResult = root_tileobject->QueryIntAttribute("gid", &gid);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando gid: %i\n", eResult);
	}else{
		printf("gid %d\n",gid);
	}
	eResult = root_tileobject->QueryIntAttribute("visible", &visible);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando visible: %i\n", eResult);
	}else{
		printf("visible %d\n",visible);
	}


	/*
	 * Cargamos la lista de properties
	 */
	pElement_tmp = root_tileobject->FirstChildElement("properties"); //nos saltamos el tag properties
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
	pElement_tmp = root_tileobject->FirstChildElement("image");
	if (pElement_tmp != NULL) {
		image = new TileImage(pElement_tmp);
	}else {
		pListElement = NULL;
		printf("no hay ningun elemento image\n");
	}
}
