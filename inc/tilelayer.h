/*
 * layer.h
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#ifndef INC_TILELAYER_H_
#define INC_TILELAYER_H_

#include <string.h>
#include <list>
#include <tinyxml2.h>
#include "tileproperty.h"
#include "tiledata.h"

using namespace std;
using namespace tinyxml2;

class TileLayer
{
public:
	TileLayer(XMLElement * t);
	~TileLayer();
	void draw();
private:

	string name; // The name of the layer.
	float opacity; // The opacity of the layer as a value from 0 to 1. Defaults to 1.
	int visible; // Whether the layer is shown (1) or hidden (0). Defaults to 1.
	int offsetx; // Rendering offset for this layer in pixels. Defaults to 0. (since 0.14)
	int offsety; // Rendering offset for this layer in pixels. Defaults to 0. (since 0.14)
	list<TileProperty*> properties;
	list<TileProperty*>::iterator properties_iter;
	TileData datos;
	XMLElement * root_tilelayer;
};




#endif /* INC_TILELAYER_H_ */
