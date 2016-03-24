/*
 * tileobject.h
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#ifndef INC_TILEOBJECT_H_
#define INC_TILEOBJECT_H_

#include <string>
#include <list>
#include <tinyxml2.h>

class TileProperty;


class TileObject
{
public:
	TileObject(tinyxml2::XMLElement * t);
	~TileObject();
	void draw();
	void parse();
private:

	int id; // Unique ID of the object. Each object that is placed on a map gets a unique id. Even if an object was deleted, no object gets the same ID. Can not be changed in Tiled Qt. (since Tiled 0.11)
	std::string name; // The name of the object. An arbitrary string.
	std::string type; // The type of the object. An arbitrary string.
	int x; // The x coordinate of the object in pixels.
	int y; // The y coordinate of the object in pixels.
	int width; // The width of the object in pixels (defaults to 0).
	int height; // The height of the object in pixels (defaults to 0).
	int rotation; // The rotation of the object in degrees clockwise (defaults to 0). (since 0.10)
	int gid; // An reference to a tile (optional).
	int visible; // Whether the object is shown (1) or hidden (0). Defaults to 1. (since 0.9)
	std::list<TileProperty*> properties;
	std::list<TileProperty*>::iterator properties_iter;

	tinyxml2::XMLElement * root_tileobject;
};




#endif /* INC_TILEOBJECT_H_ */
