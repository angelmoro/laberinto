/*
 * tileimage.cpp
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#include "tileimage.h"
#include "tiledata.h"

TileImage::TileImage(tinyxml2::XMLElement * t)
{
	root_tileimage = t;
	printf("creado tileimage\n");
	parse();
}
TileImage::~TileImage()
{

}
void TileImage::draw()
{

}
void TileImage::parse()
{
	tinyxml2::XMLError 			eResult;
	tinyxml2::XMLElement 		* pElement_tmp;
	tinyxml2::XMLElement 		* pListElement;
	const char 					* szAttributeText;

	/*
	 * Se extraen todos los atributos del elemento map
	 */
	szAttributeText = NULL;
	szAttributeText = root_tileimage->Attribute("format");
	if (szAttributeText == NULL) {
		printf("format no encontrado\n");
	}else {
		format = szAttributeText;
		printf("format %s\n",format.c_str());
	}
	szAttributeText = NULL;
	szAttributeText = root_tileimage->Attribute("source");
	if (szAttributeText == NULL) {
		printf("source no encontrado\n");
	}else {
		source = szAttributeText;
		printf("source %s\n",source.c_str());
	}
	szAttributeText = NULL;
	szAttributeText = root_tileimage->Attribute("trans");
	if (szAttributeText == NULL) {
		printf("trans no encontrado\n");
	}else {
		trans = szAttributeText;
		printf("trans %s\n",trans.c_str());
	}
	eResult = root_tileimage->QueryIntAttribute("width", &width);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando width: %i\n", eResult);
	}else{
		printf("width %d\n",width);
	}
	eResult = root_tileimage->QueryIntAttribute("height", &height);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando height: %i\n", eResult);
	}else{
		printf("height %d\n",height);
	}
	/*
	 * Creamos el elemento data si existe
	 */
	pElement_tmp = root_tileimage->FirstChildElement("data");
	if (pElement_tmp == NULL) {
		printf("no hay ningun elemento tiledata\n");
	} else {
		data = new TileData(pElement_tmp);
	}

}
