/*
 * tileset.cpp
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */


#include "tileset.h"
#include "tileproperty.h"
#include "tileimage.h"
#include "tileterrain.h"
#include "tileoffset.h"
#include "tile.h"



TileSet::TileSet(tinyxml2::XMLElement * t)
{
	/*
	 * Valores por defecto
	 */
	firstgid = 0; // The first global tile ID of this tileset (this global ID maps to the first tile in this tileset).
	source = ""; // If this tileset is stored in an external TSX (Tile Set XML) file, this attribute refers to that file. That TSX file has the same structure as the <tileset> element described here. (There is the firstgid attribute missing and this source attribute is also not there. These two attributes are kept in the TMX map, since they are map specific.)
	name = ""; // The name of this tileset.
	tilewidth = 0; // The (maximum) width of the tiles in this tileset.
	tileheight = 0; // The (maximum) height of the tiles in this tileset.
	spacing = 0; // The spacing in pixels between the tiles in this tileset (applies to the tileset image).
	margin = 0; // The margin around the tiles in this tileset (applies to the tileset image).
	tilecount = 0; // The number of tiles in this tileset (since 0.13)
	columns = 0; // The number of tile columns in the tileset. For image collection tilesets it is editable and is used when displaying the tileset. (since 0.15)


	root_tileset = t;
	printf("creado tileset\n");
	parse();
}
TileSet::~TileSet()
{

}
void TileSet::draw(int x,int y,int tile)
{
	int fila, columna;
	int tx,ty; // posicion dentro del tileset, calcularlas a partir del tile

	/*
	 * Calcular las posiciones en la imagen a partir de tile
	 */
	fila = (tile - firstgid)/columns; // cociente
	columna = (tile - firstgid)%columns; // resto

	// El margin no tengo claro como tratarlo TBD
	tx = columna * (tilewidth + spacing);
	ty = fila * (tileheight + spacing);


	image->draw(x,y,tx,ty,tilewidth,tileheight);
}
void TileSet::parse()
{
	tinyxml2::XMLError 			eResult;
	tinyxml2::XMLElement 		* pElement_tmp;
	tinyxml2::XMLElement 		* pListElement;
	const char 					* szAttributeText;
	TileProperty				*tp;
	TileTerrain					*tt;
	Tile						*t;

	/*
	 * Se extraen todos los atributos del elemento tileset
	 */
	eResult = root_tileset->QueryIntAttribute("firstgid", &firstgid);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando firstgid: %i\n", eResult);
	}else{
		printf("firstgid %d\n",firstgid);
	}
	szAttributeText = NULL;
	szAttributeText = root_tileset->Attribute("source");
	if (szAttributeText == NULL) {
		printf("source no encontrado\n");
	}else {
		source = szAttributeText;
		printf("source %s\n",source.c_str());
	}
	szAttributeText = NULL;
	szAttributeText = root_tileset->Attribute("name");
	if (szAttributeText == NULL) {
		printf("name no encontrado\n");
	}else {
		name = szAttributeText;
		printf("name %s\n",name.c_str());
	}
	eResult = root_tileset->QueryIntAttribute("tilewidth", &tilewidth);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando tilewidth: %i\n", eResult);
	}else{
		printf("tilewidth %d\n",tilewidth);
	}

	eResult = root_tileset->QueryIntAttribute("tileheight", &tileheight);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando tileheight: %i\n", eResult);
	}else{
		printf("tileheight %d\n",tileheight);
	}
	eResult = root_tileset->QueryIntAttribute("spacing", &spacing);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando spacing: %i\n", eResult);
	}else{
		printf("spacing %d\n",spacing);
	}
	eResult = root_tileset->QueryIntAttribute("margin", &margin);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando margin: %i\n", eResult);
	}else{
		printf("margin %d\n",margin);
	}
	eResult = root_tileset->QueryIntAttribute("tilecount", &tilecount);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando tilecount: %i\n", eResult);
	}else{
		printf("tilecount %d\n",tilecount);
	}
	eResult = root_tileset->QueryIntAttribute("columns", &columns);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando columns: %i\n", eResult);
	}else{
		printf("columns %d\n",columns);
	}
	/*
	 * Cargamos el offset si existe
	 */
	pElement_tmp = root_tileset->FirstChildElement("tileoffset");
	if (pElement_tmp != NULL) {
		tileoffset = new TileOffset(pElement_tmp);
	}else {
		pListElement = NULL;
		printf("no hay ningun elemento tileoffset\n");
	}
	/*
	 * Cargamos la lista de properties
	 */
	pElement_tmp = root_tileset->FirstChildElement("properties"); //nos saltamos el tag properties
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
	pElement_tmp = root_tileset->FirstChildElement("image");
	if (pElement_tmp != NULL) {
		image = new TileImage(pElement_tmp);
	}else {
		pListElement = NULL;
		printf("no hay ningun elemento image\n");
	}
	/*
	 * Cargamos la lista de terraintypes
	 */
	pElement_tmp = root_tileset->FirstChildElement("terraintypes"); //nos saltamos el tag terraintypes
	if (pElement_tmp != NULL) {
		pListElement = pElement_tmp->FirstChildElement("terrain");
	}else {
		pListElement = NULL;
		printf("no hay ningun elemento terraintypes\n");
	}
	if (pListElement == NULL) {printf("no hay ningun elemento terrain\n");}
	while (pListElement != NULL)
	{
		tt = new TileTerrain(pListElement);
		terraintypes.push_back(tt);
		pListElement = pListElement->NextSiblingElement("terrain");
	}
	/*
	 * Cargamos la lista de tiles
	 */
	pListElement = root_tileset->FirstChildElement("tile");
	if (pListElement == NULL) {printf("no hay ningun elemento tile\n");}
	while (pListElement != NULL)
	{
		t = new Tile(pListElement);
		tiles.push_back(t);
		pListElement = pListElement->NextSiblingElement("tile");
	}

}
bool TileSet::contiene_tile(int tile)
{
	if ((tile >= firstgid)&&(tile < firstgid+tilecount)) {
		return TRUE;
	} else {
		return FALSE;
	}
}
std::string TileSet::get_name()
{
	return name;
}
std::list<TileProperty*>::iterator TileSet::get_properties_begin_iterator()
{
	return properties.begin();
}
std::list<TileProperty*>::iterator TileSet::get_properties_end_iterator()
{
	return properties.end();
}
std::list<Tile*>::iterator TileSet::get_tiles_begin_iterator()
{
	return tiles.begin();
}
std::list<Tile*>::iterator TileSet::get_tiles_end_iterator()
{
	return tiles.end();
}
int TileSet::get_firstgid()
{
	return firstgid;
}
