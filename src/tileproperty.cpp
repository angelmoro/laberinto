/*
 * tileproperty.cpp
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#include "tileproperty.h"

TileProperty::TileProperty(tinyxml2::XMLElement * t)
{
	/*
	 * Valores por defecto
	 */
	name = ""; // The name of the property.
	value = ""; // The value of the property.

	root_tileproperty = t;
	printf("creado tileproperty\n");
	parse();
}
TileProperty::~TileProperty()
{

}

void TileProperty::parse()
{
	const char 					* szAttributeText;

	/*
	 * Se extraen todos los atributos del elemento property
	 */
	szAttributeText = NULL;
	szAttributeText = root_tileproperty->Attribute("name");
	if (szAttributeText == NULL) {
		printf("name no encontrado\n");
	}else {
		name = szAttributeText;
		printf("name %s\n",name.c_str());
	}
	szAttributeText = NULL;
	szAttributeText = root_tileproperty->Attribute("value");
	if (szAttributeText == NULL) {
		printf("value no encontrado\n");
	}else {
		value = szAttributeText;
		printf("value %s\n",value.c_str());
	}

}
std::string TileProperty::get_name()
{
	return name;
}
std::string TileProperty::get_value()
{
	return value;
}
