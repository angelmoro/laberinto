/*
 * tileframe.h
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#ifndef INC_TILEFRAME_H_
#define INC_TILEFRAME_H_

#include <string.h>


class TileFrame
{
public:
	TileFrame();
	~TileFrame();
private:

	int tileid; // The local ID of a tile within the parent tileset.
	int duration; // How long (in milliseconds) this frame should be displayed before advancing to the next frame.


};



#endif /* INC_TILEFRAME_H_ */
