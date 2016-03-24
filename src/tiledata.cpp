/*
 * tiledata.cpp
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#include "tiledata.h"

TileData::TileData(tinyxml2::XMLElement * t)
{
	root_tiledata = t;
	printf("creado tiledata\n");
	data = NULL;
	parse();
}
TileData::~TileData()
{

}
void TileData::parse()
{
	const char 		* szAttributeText;


	/*
	 * Se extraen todos los atributos del elemento tileset
	 */

	szAttributeText = NULL;
	szAttributeText = root_tiledata->Attribute("encoding");
	if (szAttributeText == NULL) {
		printf("encoding no encontrado\n");
	}else {
		encoding = szAttributeText;
		printf("encoding %s\n",encoding.c_str());
	}
	szAttributeText = NULL;
	szAttributeText = root_tiledata->Attribute("compression");
	if (szAttributeText == NULL) {
		printf("compression no encontrado\n");
	}else {
		compression = szAttributeText;
		printf("compression %s\n",compression.c_str());
	}

	/*
	 * extraemos los datos en funcion del encoding
	 */
	if (encoding.compare("base64") == 0) {
		printf("encoding base64 sin implementar\n");
	} else if  (encoding.compare("csv") == 0) {
		data = root_tiledata->GetText();
	} else {
		printf("encoding desconocido\n");
	}
	printf("data %s\n",data);


}
