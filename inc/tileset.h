/*
 * tileset.h
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#ifndef INC_TILESET_H_
#define INC_TILESET_H_


#include <list>
#include <tinyxml2.h>
#include "tileproperty.h"
#include "tileterrain.h"

using namespace std;
using namespace tinyxml2;

class TileSet
{
public:
	TileSet (XMLElement * t);
	~TileSet();
	void draw();
private:

	int firstgid; // The first global tile ID of this tileset (this global ID maps to the first tile in this tileset).
	string source; // If this tileset is stored in an external TSX (Tile Set XML) file, this attribute refers to that file. That TSX file has the same structure as the <tileset> element described here. (There is the firstgid attribute missing and this source attribute is also not there. These two attributes are kept in the TMX map, since they are map specific.)
	string name; // The name of this tileset.
	int tilewidth; // The (maximum) width of the tiles in this tileset.
	int tileheight; // The (maximum) height of the tiles in this tileset.
	int spacing; // The spacing in pixels between the tiles in this tileset (applies to the tileset image).
	int margin; // The margin around the tiles in this tileset (applies to the tileset image).
	int tilecount; // The number of tiles in this tileset (since 0.13)
	int columns; // The number of tile columns in the tileset. For image collection tilesets it is editable and is used when displaying the tileset. (since 0.15)
	list<TileProperty*> properties;
	list<TileProperty*>::iterator properties_iter;
	list<TileTerrain*> terraintypes;
	list<TileTerrain*>::iterator terraintypes_iter;
	XMLElement * root_tileset;
};




#endif /* INC_TILESET_H_ */
