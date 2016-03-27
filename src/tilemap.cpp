/*
 * tilemap.cpp
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#include <vector>
#include "tilemap.h"
#include "tileset.h"
#include "tilelayer.h"
#include "tileobjectgroup.h"
#include "tileimagelayer.h"
#include "tileproperty.h"



TileMap::TileMap(std::string file)
{
	tinyxml2::XMLError eResult;

	eResult = xmlDoc.LoadFile(file.c_str());
	if (eResult != tinyxml2::XML_SUCCESS)
	{
		printf("Error: %i no puedo cargar el fichero %s\n", eResult,file.c_str());
		exit(-1);
	}
	parse();

}
TileMap::~TileMap()
{

}
void TileMap::draw()
{
	TileSet * tileset_tmp;
	std::vector<int>::iterator tiledata_tmp_iter;
	int tile_tmp;
	int x,y;
	int fila,columna;

	//revisar el orden de dibujo de todos los elementos del mapa TBD
	/*
	 * Iterar para dibujar todos los imagelayers
	 */
	for (tileimagelayers_iter=tileimagelayers.begin();
		 tileimagelayers_iter!=tileimagelayers.end();
		 tileimagelayers_iter++)
	{
		(*tileimagelayers_iter)->draw();
	}

	/*
	 * Iterar para dibujar todos los layers
	 */
	for (tilelayers_iter=tilelayers.begin();
		 tilelayers_iter!=tilelayers.end();
		 tilelayers_iter++)
	{
		/*
		 * Para cada layer iteramos por sus datos obteniendo tiles
		 */
		fila = 0;
		columna = 0;
		for (tiledata_tmp_iter=(*tilelayers_iter)->get_begin_iterator();
				 tiledata_tmp_iter!=(*tilelayers_iter)->get_end_iterator();
				 tiledata_tmp_iter++,columna++)
		{
			/*
			 * Comprobamos si hay cambio de fila
			 * Estamos asumiendo un render izquierda->derecha arriba-abajo
			 */

			if (columna == width ) {columna = 0;fila++;}

			/*
			 * obtenemos el tile
			 */

			tile_tmp = (*tiledata_tmp_iter);

			/*
			 * determinamos el tileset al que pertenece
			 */

			tileset_tmp = tileset_contiene_tile(tile_tmp);

			/*
			 * Calculamos la posicion x,y donde dibujar el tile
			 * Estamos asumiendo un render izquierda->derecha arriba-abajo
			 */

			x = columna * tilewidth;
			y = fila * tileheight;

			/*
			 * dibujamos el tile
			 */

			if (tileset_tmp != NULL) tileset_tmp->draw(x,y,tile_tmp);

		}
	}



}
void TileMap::parse()
{
	tinyxml2::XMLError 			eResult;
	tinyxml2::XMLElement 		* pElement_tmp;
	tinyxml2::XMLElement 		* pListElement;
	const char 					* szAttributeText;
	TileSet 					* ts;
	TileLayer					* tl;
	TileObjectGroup				*to;
	TileImageLayer				*ti;
	TileProperty				*tp;
/*
 * Localiza el elemento map
 */
	root_tilemap = xmlDoc.FirstChildElement("map");
	if (root_tilemap == NULL) {printf("Error: no hay elemento map\n");exit(-1);}
/*
 * Se extraen todos los atributos del elemento map
 */
	szAttributeText = NULL;
	szAttributeText = root_tilemap->Attribute("version");
	if (szAttributeText == NULL) {
		printf("version no encontrado\n");
	}else {
		version = szAttributeText;
		printf("version %s\n",version.c_str());
	}

	szAttributeText = NULL;
	szAttributeText = root_tilemap->Attribute("orientation");
	if (szAttributeText == NULL) {
		printf("orintation no encontrado\n");
	}else{
		orientation = szAttributeText;
		printf("orientation %s\n",orientation.c_str());
	}

	szAttributeText = NULL;
	szAttributeText = root_tilemap->Attribute("renderorder");
	if (szAttributeText == NULL) {
		printf("renderorder no encontrado\n");
	}else{
		renderorder = szAttributeText;
		printf("renderorder %s\n",renderorder.c_str());
	}

	eResult = root_tilemap->QueryIntAttribute("width", &width);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando width: %i\n", eResult);
	}else{
		printf("width %d\n",width);
	}

	eResult = root_tilemap->QueryIntAttribute("height", &height);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando height: %i\n", eResult);
	}else{
		printf("height %d\n",height);
	}

	eResult = root_tilemap->QueryIntAttribute("tilewidth", &tilewidth);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando tilewidth: %i\n", eResult);
	}else{
		printf("tilewidth %d\n",tilewidth);
	}

	eResult = root_tilemap->QueryIntAttribute("tileheight", &tileheight);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando tileheight: %i\n", eResult);
	}else{
		printf("tileheight %d\n",tileheight);
	}

	eResult = root_tilemap->QueryIntAttribute("hexsidelength", &hexsidelength);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando hexsidelength: %i\n", eResult);
	}else{
		printf("hexsidelength %d\n",hexsidelength);
	}

	szAttributeText = NULL;
	szAttributeText = root_tilemap->Attribute("staggeraxis");
	if (szAttributeText == NULL) {
		printf("staggeraxis no encontrado\n");
	}else{
		staggeraxis = szAttributeText;
		printf("staggeraxis %s\n",staggeraxis.c_str());
	}

	szAttributeText = NULL;
	szAttributeText = root_tilemap->Attribute("staggerindex");
	if (szAttributeText == NULL) {
		printf("staggerindex no encontrado\n");
	}else{
		staggerindex = szAttributeText;
		printf("staggerindex %s\n",staggerindex.c_str());
	}

	szAttributeText = NULL;
	szAttributeText = root_tilemap->Attribute("backgroundcolor");
	if (szAttributeText == NULL) {
		printf("backgroundcolor no encontrado\n");
	}else{
		backgroundcolor = szAttributeText;
		printf("backgroundcolor %s\n",backgroundcolor.c_str());
	}

	eResult = root_tilemap->QueryIntAttribute("nextobjectid", &nextobjectid);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando nextobjectid: %i\n", eResult);
	}else{
		printf("nextobjectid %d\n",nextobjectid);
	}
	/*
	 * Cargamos la lista de tilesets
	 */
	pListElement = root_tilemap->FirstChildElement("tileset");
	if (pListElement == NULL) {printf("no hay ningun elemento tileset\n");}
	while (pListElement != NULL)
	{
		ts = new TileSet(pListElement);
		tilesets.push_back(ts);
		pListElement = pListElement->NextSiblingElement("tileset");
	}
	/*
	 * Cargamos la lista de layers
	 */
	pListElement = root_tilemap->FirstChildElement("layer");
	if (pListElement == NULL) {printf("no hay ningun elemento layer\n");}
	while (pListElement != NULL)
	{
		tl = new TileLayer(pListElement);
		tilelayers.push_back(tl);
		pListElement = pListElement->NextSiblingElement("layer");
	}
	/*
	 * Cargamos la lista de objectgroups
	 */
	pListElement = root_tilemap->FirstChildElement("objectgroup");
	if (pListElement == NULL) {printf("no hay ningun elemento objectgroup\n");}
	while (pListElement != NULL)
	{
		to = new TileObjectGroup(pListElement);
		tileobjectgroups.push_back(to);
		pListElement = pListElement->NextSiblingElement("objectgroup");
	}
	/*
	 * Cargamos la lista de imagelayers
	 */
	pListElement = root_tilemap->FirstChildElement("imagelayer");
	if (pListElement == NULL) {printf("no hay ningun elemento imagelayer\n");}
	while (pListElement != NULL)
	{
		ti = new TileImageLayer(pListElement);
		tileimagelayers.push_back(ti);
		pListElement = pListElement->NextSiblingElement("imagelayer");
	}
	/*
	 * Cargamos la lista de properties
	 */
	pElement_tmp = root_tilemap->FirstChildElement("properties"); //nos saltamos el tag properties
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

//	XMLElement * pElement = pRoot->FirstChildElement("tileset");
//	if (pElement == NULL) {printf("Error: parsing element\n");exit(-1);}



}

TileSet * TileMap::tileset_contiene_tile(int tile)
{
	for (tilesets_iter=tilesets.begin();
		 tilesets_iter!=tilesets.end();
		 tilesets_iter++)
	{
		if ((*tilesets_iter)->contiene_tile(tile)) return (*tilesets_iter);
	}
	return NULL;
}
