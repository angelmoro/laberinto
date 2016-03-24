/*
 * image.h
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#ifndef INC_TILEIMAGE_H_
#define INC_TILEIMAGE_H_


#include <string.h>
#include <list>
#include "tileproperty.h"

using namespace std;

class TileImage
{
public:
	TileImage();
	~TileImage();
	void draw();
private:

	string format; // Used for embedded images, in combination with a data child element. Valid values are file extensions like png, gif, jpg, bmp, etc. (since 0.9)
	string source; // The reference to the tileset image file (Tiled supports most common image formats).
	string trans; // Defines a specific color that is treated as transparent (example value: "#FF00FF" for magenta). Up until Tiled 0.12, this value is written out without a # but this is planned to change.
	int width; // The image width in pixels (optional, used for tile index correction when the image changes)
	int height; // The image height in pixels (optional)
};


#endif /* INC_TILEIMAGE_H_ */
