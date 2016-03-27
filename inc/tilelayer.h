/*
 * layer.h
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#ifndef INC_TILELAYER_H_
#define INC_TILELAYER_H_

#include <string>
#include <list>
#include <vector>
#include <tinyxml2.h>

class TileData;
class TileProperty;

class TileLayer
{
public:
	TileLayer(tinyxml2::XMLElement * t);
	~TileLayer();
	void draw();
	std::vector<int>::iterator get_begin_iterator();
	std::vector<int>::iterator get_end_iterator();
	void parse();
private:

	std::string name; // The name of the layer.
	float opacity; // The opacity of the layer as a value from 0 to 1. Defaults to 1.
	int visible; // Whether the layer is shown (1) or hidden (0). Defaults to 1.
	int offsetx; // Rendering offset for this layer in pixels. Defaults to 0. (since 0.14)
	int offsety; // Rendering offset for this layer in pixels. Defaults to 0. (since 0.14)
	std::list<TileProperty*> properties;
	std::list<TileProperty*>::iterator properties_iter;
	TileData * data;
	tinyxml2::XMLElement * root_tilelayer;
};




#endif /* INC_TILELAYER_H_ */
