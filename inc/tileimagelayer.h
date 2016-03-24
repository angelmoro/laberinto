/*
 * imagelayer.h
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#ifndef INC_TILEIMAGELAYER_H_
#define INC_TILEIMAGELAYER_H_

#include <string.h>
#include <list>
#include <tinyxml2.h>
#include "tileproperty.h"
#include "tileimage.h"

using namespace std;
using namespace tinyxml2;

class TileImageLayer
{
public:
	TileImageLayer(XMLElement * t);
	~TileImageLayer();
	void draw();
private:

	string name; // The name of the image layer.
	int offsetx; // Rendering offset of the image layer in pixels. Defaults to 0. (since 0.15)
	int offsety; // Rendering offset of the image layer in pixels. Defaults to 0. (since 0.15)
	int opacity; // The opacity of the layer as a value from 0 to 1. Defaults to 1.
	int visible; // Whether the layer is shown (1) or hidden (0). Defaults to 1.
	list<TileProperty*> properties;
	list<TileProperty*>::iterator properties_iter;
	TileImage imagen;
	XMLElement * root_tileimagelayer;
};



#endif /* INC_TILEIMAGELAYER_H_ */
