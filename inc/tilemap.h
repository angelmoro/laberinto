/*
 * tilemap.h
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#ifndef INC_TILEMAP_H_
#define INC_TILEMAP_H_

#include <string>
#include <list>
#include <tileproperty.h>
#include <tinyxml2.h>
#include "tileset.h"
#include "tilelayer.h"
#include "tileobjectgroup.h"
#include "tileimagelayer.h"

using namespace std;
using namespace tinyxml2;


class TileMap
{
public:
	TileMap(string file);
	~TileMap();
	void draw();
	void parse();
private:
	string version; // The TMX format version, generally 1.0
	string orientation; // Map orientation. Tiled supports "orthogonal", "isometric", "staggered" (since 0.9) and "hexagonal" (since 0.11).
	string renderorder; // The order in which tiles on tile layers are rendered. Valid values are right-down (the default), right-up, left-down and left-up. In all cases, the map is drawn row-by-row. (since 0.10, but only supported for orthogonal maps at the moment)
	int width; // The map width in tiles.
	int height; // The map height in tiles.
	int tilewidth; // The width of a tile.
	int tileheight; // The height of a tile.
	int hexsidelength; // Only for hexagonal maps. Determines the width or height (depending on the staggered axis) of the tile's edge, in pixels.
	string staggeraxis; // For staggered and hexagonal maps, determines which axis ("x" or "y") is staggered. (since 0.11)
	string staggerindex; // For staggered and hexagonal maps, determines whether the "even" or "odd" indexes along the staggered axis are shifted. (since 0.11)
	string backgroundcolor; // The background color of the map. (since 0.9, optional, may include alpha value since 0.15 in the form #AARRGGBB)
	int nextobjectid; // Stores the next available ID for new objects. This number is stored to prevent reuse of the same ID after objects have been removed. (since 0.11)

	list<TileSet*> tilesets;
	list<TileSet*>::iterator tilesets_iter;
	list<TileLayer*> tilelayers;
	list<TileLayer*>::iterator tilelayers_iter;
	list<TileObjectGroup*> tileobjectgroups;
	list<TileObjectGroup*>::iterator tileobjectgroups_iter;
	list<TileImageLayer*> tileimagelayers;
	list<TileImageLayer*>::iterator tileimagelayers_iter;
	list<TileProperty*> properties;
	list<TileProperty*>::iterator properties_iter;

	XMLDocument xmlDoc;
	XMLElement * root_tilemap;
};



#endif /* INC_TILEMAP_H_ */
