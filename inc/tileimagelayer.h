/*
 * imagelayer.h
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#ifndef INC_TILEIMAGELAYER_H_
#define INC_TILEIMAGELAYER_H_

#include <string>
#include <list>
#include "tinyxml2.h"



class TileProperty;
class TileImage;

class TileImageLayer
{
public:
	TileImageLayer(tinyxml2::XMLElement * t);
	~TileImageLayer();
	void draw();
	void parse();
private:

	std::string name; // The name of the image layer.
	int offsetx; // Rendering offset of the image layer in pixels. Defaults to 0. (since 0.15)
	int offsety; // Rendering offset of the image layer in pixels. Defaults to 0. (since 0.15)
	float opacity; // The opacity of the layer as a value from 0 to 1. Defaults to 1.
	int visible; // Whether the layer is shown (1) or hidden (0). Defaults to 1.
	std::list<TileProperty*> properties;
	std::list<TileProperty*>::iterator properties_iter;
	TileImage * image;

	tinyxml2::XMLElement * root_tileimagelayer;
};



#endif /* INC_TILEIMAGELAYER_H_ */
