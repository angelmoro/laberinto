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
#include "tile.h"

//#define VERBOSE 1

TileMap::TileMap(std::string file)
{
	tinyxml2::XMLError eResult;

	version = "1.0"; // The TMX format version, generally 1.0
	orientation = ""; // Map orientation. Tiled supports "orthogonal", "isometric", "staggered" (since 0.9) and "hexagonal" (since 0.11).
	renderorder = "right-down"; // The order in which tiles on tile layers are rendered. Valid values are right-down (the default), right-up, left-down and left-up. In all cases, the map is drawn row-by-row. (since 0.10, but only supported for orthogonal maps at the moment)
	width = 0; // The map width in tiles.
	height = 0; // The map height in tiles.
	tilewidth = 0; // The width of a tile.
	tileheight = 0; // The height of a tile.
	hexsidelength = 0; // Only for hexagonal maps. Determines the width or height (depending on the staggered axis) of the tile's edge, in pixels.
	staggeraxis = ""; // For staggered and hexagonal maps, determines which axis ("x" or "y") is staggered. (since 0.11)
	staggerindex = ""; // For staggered and hexagonal maps, determines whether the "even" or "odd" indexes along the staggered axis are shifted. (since 0.11)
	backgroundcolor = ""; // The background color of the map. (since 0.9, optional, may include alpha value since 0.15 in the form #AARRGGBB)
	nextobjectid = 0; // Stores the next available ID for new objects. This number is stored to prevent reuse of the same ID after objects have been removed. (since 0.11)

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
		 * chequeamos si el layer es visible
		 */

		if (!((*tilelayers_iter)->get_visible())) continue;

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
			 * Estamos asumiendo un render izquierda->derecha arriba->abajo "right-down"
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
			 * Estamos asumiendo un render izquierda->derecha arriba->abajo "right-down"
			 */

			x = columna * tilewidth;
			y = fila * tileheight;

			/*
			 * añadimos el offset del layer
			 */

			x = x + (*tilelayers_iter)->get_offsetx();
			y = y + (*tilelayers_iter)->get_offsety();

			/*
			 * dibujamos el tile
			 */

			if (tileset_tmp != NULL) tileset_tmp->draw(x,y,tile_tmp);

		}
	}

}
std::list<TileObjectGroup*>::iterator TileMap::get_objectgroups_begin_iterator()
{
	return tileobjectgroups.begin();
}
std::list<TileObjectGroup*>::iterator TileMap::get_objectgroups_end_iterator()
{
	return tileobjectgroups.end();
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
#ifdef VERBOSE
		printf("version no encontrado\n");
#endif
	}else {
		version = szAttributeText;
#ifdef VERBOSE
		printf("version %s\n",version.c_str());
#endif
	}

	szAttributeText = NULL;
	szAttributeText = root_tilemap->Attribute("orientation");
	if (szAttributeText == NULL) {
#ifdef VERBOSE
		printf("orintation no encontrado\n");
#endif
	}else{
		orientation = szAttributeText;
#ifdef VERBOSE
		printf("orientation %s\n",orientation.c_str());
#endif
	}

	szAttributeText = NULL;
	szAttributeText = root_tilemap->Attribute("renderorder");
	if (szAttributeText == NULL) {
#ifdef VERBOSE
		printf("renderorder no encontrado\n");
#endif
	}else{
		renderorder = szAttributeText;
#ifdef VERBOSE
		printf("renderorder %s\n",renderorder.c_str());
#endif
	}

	eResult = root_tilemap->QueryIntAttribute("width", &width);
	if (eResult != tinyxml2::XML_SUCCESS)  {
#ifdef VERBOSE
		printf("Error cargando width: %i\n", eResult);
#endif
	}else{
#ifdef VERBOSE
		printf("width %d\n",width);
#endif
	}

	eResult = root_tilemap->QueryIntAttribute("height", &height);
	if (eResult != tinyxml2::XML_SUCCESS)  {
#ifdef VERBOSE
		printf("Error cargando height: %i\n", eResult);
#endif
	}else{
#ifdef VERBOSE
		printf("height %d\n",height);
#endif
	}

	eResult = root_tilemap->QueryIntAttribute("tilewidth", &tilewidth);
	if (eResult != tinyxml2::XML_SUCCESS)  {
#ifdef VERBOSE
		printf("Error cargando tilewidth: %i\n", eResult);
#endif
	}else{
#ifdef VERBOSE
		printf("tilewidth %d\n",tilewidth);
#endif
	}

	eResult = root_tilemap->QueryIntAttribute("tileheight", &tileheight);
	if (eResult != tinyxml2::XML_SUCCESS)  {
#ifdef VERBOSE
		printf("Error cargando tileheight: %i\n", eResult);
#endif
	}else{
#ifdef VERBOSE
		printf("tileheight %d\n",tileheight);
#endif
	}

	eResult = root_tilemap->QueryIntAttribute("hexsidelength", &hexsidelength);
	if (eResult != tinyxml2::XML_SUCCESS)  {
#ifdef VERBOSE
		printf("Error cargando hexsidelength: %i\n", eResult);
#endif
	}else{
#ifdef VERBOSE
		printf("hexsidelength %d\n",hexsidelength);
#endif
	}

	szAttributeText = NULL;
	szAttributeText = root_tilemap->Attribute("staggeraxis");
	if (szAttributeText == NULL) {
#ifdef VERBOSE
		printf("staggeraxis no encontrado\n");
#endif
	}else{
		staggeraxis = szAttributeText;
#ifdef VERBOSE
		printf("staggeraxis %s\n",staggeraxis.c_str());
#endif
	}

	szAttributeText = NULL;
	szAttributeText = root_tilemap->Attribute("staggerindex");
	if (szAttributeText == NULL) {
#ifdef VERBOSE
		printf("staggerindex no encontrado\n");
#endif
	}else{
		staggerindex = szAttributeText;
#ifdef VERBOSE
		printf("staggerindex %s\n",staggerindex.c_str());
#endif
	}

	szAttributeText = NULL;
	szAttributeText = root_tilemap->Attribute("backgroundcolor");
	if (szAttributeText == NULL) {
#ifdef VERBOSE
		printf("backgroundcolor no encontrado\n");
#endif
	}else{
		backgroundcolor = szAttributeText;
#ifdef VERBOSE
		printf("backgroundcolor %s\n",backgroundcolor.c_str());
#endif
	}

	eResult = root_tilemap->QueryIntAttribute("nextobjectid", &nextobjectid);
	if (eResult != tinyxml2::XML_SUCCESS)  {
#ifdef VERBOSE
		printf("Error cargando nextobjectid: %i\n", eResult);
#endif
	}else{
#ifdef VERBOSE
		printf("nextobjectid %d\n",nextobjectid);
#endif
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
#ifdef VERBOSE
	if (pListElement == NULL) {printf("no hay ningun elemento objectgroup\n");}
#endif
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
#ifdef VERBOSE
	if (pListElement == NULL) {printf("no hay ningun elemento imagelayer\n");}
#endif
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
int TileMap::get_tile_gid(TileLayer * layer,int pixel_x,int pixel_y)
{
	int tile_x,tile_y,pos;

	tile_x = pixel_x / tilewidth;
	tile_y = pixel_y / tileheight;

	pos = width * tile_y + tile_x;//posicion lineal en el vector de almacenamiento

	return layer->get_tile_gid(pos);
}
void TileMap::crear_colision_set(std::string nombre_colision_set,
								std::string meta_tileset,
								std::string atribute_colisionable,
								std::string atribute_objeto,
								std::set<int> * colision_set)
{
	int gid;
	bool attr_colisionable;
	bool attr_objeto;
	bool tileset;

	std::list<TileProperty*>::iterator properties_iter;
	std::list<Tile*>::iterator tiles_iter;


	/*
	 * Iterar para encontrar el meta tileset
	 */
	tileset = false;

	for (tilesets_iter=tilesets.begin();
		 tilesets_iter!=tilesets.end();
		 tilesets_iter++)
	{
		if ((*tilesets_iter)->get_name() == meta_tileset) {tileset = true;break;}
	}
	if (!tileset)
	{
		printf("meta tileset no encontrado\n");
		exit(-1);
	}
	/*
	 * Iterar por todos los tile del tileset
	 */
	for (tiles_iter=(*tilesets_iter)->get_tiles_begin_iterator();
		 tiles_iter!=(*tilesets_iter)->get_tiles_end_iterator();
		 tiles_iter++)
	{

		/*
		 * Iterar por todas las propiedades del tile
		 */
		attr_colisionable = false;
		attr_objeto = false;

		for (properties_iter=(*tiles_iter)->get_properties_begin_iterator();
			 properties_iter!=(*tiles_iter)->get_properties_end_iterator();
			 properties_iter++)
		{

			if (((*properties_iter)->get_name() == atribute_colisionable)&&
					((*properties_iter)->get_value() == "true"))
			{
				attr_colisionable = true;
			}

			if (((*properties_iter)->get_name() == atribute_objeto)&&
					((*properties_iter)->get_value() == nombre_colision_set))
			{
				attr_objeto = true;

			}
		}

		/*
		 * Si hemos encontrado una propiedad que dice que el tile es colisionable
		 * y una propiedad que dice que representa a un objeto con nombre el
		 * mismo que el del colision set que estamos creando, añadimos el tile
		 * al colision set
		 */

		if (attr_colisionable && attr_objeto)
		{
			/*
			 * Al id del tile le sumo el firstgid del tile set para
			 * obtener el gid del tile y este es el que insertamos en el set
			 * de colision
			 */
			gid = (*tilesets_iter)->get_firstgid()+(*tiles_iter)->get_id();
			colision_set->insert(gid);
		}
	}

}
TileLayer * TileMap::get_tilelayer(std::string name)
{
	for (tilelayers_iter=tilelayers.begin();
			 tilelayers_iter!=tilelayers.end();
			 tilelayers_iter++)
	{
		if ((*tilelayers_iter)->get_name() == name) return (*tilelayers_iter);
	}
	return NULL;
}
