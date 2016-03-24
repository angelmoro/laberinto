/*
 * objectgroup.h
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#ifndef INC_TILEOBJECTGROUP_H_
#define INC_TILEOBJECTGROUP_H_

#include <string.h>
#include <list>
#include <tinyxml2.h>
#include "tileproperty.h"
#include "tileobject.h"

using namespace std;
using namespace tinyxml2;

class TileObjectGroup
{
public:
	TileObjectGroup(XMLElement * t);
	~TileObjectGroup();
	void draw();
private:

	string name; // The name of the object group.
	int color; // The color used to display the objects in this group.

	int opacity; // The opacity of the layer as a value from 0 to 1. Defaults to 1.
	int visible; // Whether the layer is shown (1) or hidden (0). Defaults to 1.
	int offsetx; // Rendering offset for this object group in pixels. Defaults to 0. (since 0.14)
	int offsety; // Rendering offset for this object group in pixels. Defaults to 0. (since 0.14)
	string draworder; // Whether the objects are drawn according to the order of appearance ("index") or sorted by their y-coordinate ("topdown"). Defaults to "topdown".
	list<TileProperty*> properties;
	list<TileProperty*>::iterator properties_iter;
	list<TileObject*> Objects;
	list<TileObject*>::iterator Objects_iter;
	XMLElement * root_tileobjectgroup;

};



#endif /* INC_TILEOBJECTGROUP_H_ */
