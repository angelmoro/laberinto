/*
 * tiledata.cpp
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#include "tiledata.h"
#include <vector>

TileData::TileData(tinyxml2::XMLElement * t)
{
	/*
	 * Valores por defecto
	 */
	encoding = ""; // The encoding used to encode the tile layer data. When used, it can be "base64" and "csv" at the moment.
	compression = ""; // The compression used to compress the tile layer data. Tiled Qt supports "gzip" and "zlib".
//tile

	data = "";

	root_tiledata = t;
	printf("creado tiledata\n");
	parse();
}
TileData::~TileData()
{

}
void TileData::rewind()
{
	vtiles_iter=vtiles.begin();
}
int TileData::next()
{
	int tmp_t;
	tmp_t=*vtiles_iter;
	if (vtiles_iter==vtiles.end()) return -1;
	vtiles_iter++;
	return tmp_t;
}
int TileData::current()
{
	if (vtiles_iter==vtiles.end()) return -1;
	else
		return *vtiles_iter;
}
int TileData::num_tiles()
{
	return vtiles.size();
}
std::vector<int>::iterator TileData::get_begin_iterator()
{
	return vtiles.begin();
}
std::vector<int>::iterator TileData::get_end_iterator()
{
	return vtiles.end();
}
void TileData::parse()
{
	tinyxml2::XMLError 			eResult;
	tinyxml2::XMLElement 		* pListElement;
	const char 					* szAttributeText;
	const char 					* text_tmp;
	std::string::iterator		it; // The string iterator.
	std::string					string_tmp;
	int							gid_tmp;

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

		text_tmp = root_tiledata->GetText();
		data = text_tmp;
		/*
		 * Populamos un vector con todos los tiles en formato entero
		 */

		string_tmp = "";
		for (it= data.begin(); it != data.end(); it++)
		{
		  if ((*it) == ',') {
			  vtiles.push_back(atoi(string_tmp.c_str()));
			  string_tmp = "";
			  vtiles_iter++;
		  }
		  if (((*it) == '0') || ((*it) == '1') || ((*it) == '2') ||
			  ((*it) == '3') ||	((*it) == '4') || ((*it) == '5') ||
			  ((*it) == '6') ||	((*it) == '7') || ((*it) == '8') ||
			  ((*it) == '9')) {
			  string_tmp = string_tmp + (*it);
		  }
		}
		vtiles.push_back(atoi(string_tmp.c_str()));//el ultimo elemento no esta seguido de ","

	} else if ((encoding.compare("") == 0)&&((compression.compare("") == 0))){

		printf("no definido encoding ni compression, parseando tags <tile>\n");

		/*
		 * Cargamos la lista de tile, no creamos objetos tile, directamente lo almacenamos
		 * en el vector de data
		 */
		pListElement = root_tiledata->FirstChildElement("tile");

		while (pListElement != NULL)
		{
			eResult = pListElement->QueryIntAttribute("gid", &gid_tmp);
			if (eResult != tinyxml2::XML_SUCCESS)  {
				printf("Error cargando gid: %i\n", eResult);
			}else{
//				printf("gid %d\n",gid_tmp);
			}
			vtiles.push_back(gid_tmp);
			pListElement = pListElement->NextSiblingElement("tile");
		}

	} else {

		printf("encoding desconocido\n");

	}

	printf("data %s\n",data.c_str());
/*
	for (vtiles_iter= vtiles.begin(); vtiles_iter != vtiles.end(); vtiles_iter++)
	{
	  printf("tile %d\n",*vtiles_iter);
	}

*/

}
int TileData::get_tile_gid(int pos)
{

	int i;

	for(i=0,vtiles_iter=vtiles.begin();vtiles_iter!=vtiles.end();vtiles_iter++,i++)
	{
		if (i == pos) return (*vtiles_iter);
	}

	return -1;

}
