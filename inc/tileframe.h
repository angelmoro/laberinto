/*
 * tileframe.h
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#ifndef INC_TILEFRAME_H_
#define INC_TILEFRAME_H_

#include <string.h>
#include <tinyxml2.h>

class TileFrame
{
public:
	TileFrame(tinyxml2::XMLElement * t);
	~TileFrame();
	void parse();
private:

	int tileid; // The local ID of a tile within the parent tileset.
	int duration; // How long (in milliseconds) this frame should be displayed before advancing to the next frame.

	tinyxml2::XMLElement * root_tileframe;
};



#endif /* INC_TILEFRAME_H_ */
