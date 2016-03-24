/*
 * tileterrain.h
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#ifndef INC_TILETERRAIN_H_
#define INC_TILETERRAIN_H_

#include <string>
#include <list>
#include "tinyxml2.h"

class TileProperty;

class TileTerrain
{
public:
	TileTerrain(tinyxml2::XMLElement * t);
	~TileTerrain();
	void parse();
private:

	std::string name; // The name of the terrain type.
	int tile; // The local tile-id of the tile that represents the terrain visually
	std::list<TileProperty*> properties;
	std::list<TileProperty*>::iterator properties_iter;

	tinyxml2::XMLElement * root_tileterrain;
};



#endif /* INC_TILETERRAIN_H_ */
