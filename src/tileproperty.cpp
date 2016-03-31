/*
 * tileproperty.cpp
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#include "tileproperty.h"

//#define VERBOSE 1

TileProperty::TileProperty(tinyxml2::XMLElement * t)
{
	/*
	 * Valores por defecto
	 */
	name = ""; // The name of the property.
	value = ""; // The value of the property.

	root_tileproperty = t;
#ifdef VERBOSE
	printf("creado tileproperty\n");
#endif
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
#ifdef VERBOSE
		printf("name no encontrado\n");
#endif
	}else {
		name = szAttributeText;
#ifdef VERBOSE
		printf("name %s\n",name.c_str());
#endif
	}
	szAttributeText = NULL;
	szAttributeText = root_tileproperty->Attribute("value");
	if (szAttributeText == NULL) {
#ifdef VERBOSE
		printf("value no encontrado\n");
#endif
	}else {
		value = szAttributeText;
#ifdef VERBOSE
		printf("value %s\n",value.c_str());
#endif
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
