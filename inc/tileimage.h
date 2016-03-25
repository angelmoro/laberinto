/*
 * image.h
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#ifndef INC_TILEIMAGE_H_
#define INC_TILEIMAGE_H_


#include <string>
#include <tinyxml2.h>


#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>

class TileData;

class TileImage
{
public:
	TileImage(tinyxml2::XMLElement * t);
	~TileImage();
	void draw(int x,int y,float opacity=0);
	void draw(int x,int y,int tx,int ty,int tw,int th);
	void parse();
	void cargar_imagen();
	unsigned long hex2dec(std::string hex);
private:
/*
 * Tile area
 */
	std::string format; // Used for embedded images, in combination with a data child element. Valid values are file extensions like png, gif, jpg, bmp, etc. (since 0.9)
	std::string source; // The reference to the tileset image file (Tiled supports most common image formats).
	std::string trans; // Defines a specific color that is treated as transparent (example value: "#FF00FF" for magenta). Up until Tiled 0.12, this value is written out without a # but this is planned to change.
	int width; // The image width in pixels (optional, used for tile index correction when the image changes)
	int height; // The image height in pixels (optional)

	TileData * data;

	tinyxml2::XMLElement * root_tileimage;
/*
 * Allegro area
 */
	ALLEGRO_BITMAP *bmp;
};


#endif /* INC_TILEIMAGE_H_ */
