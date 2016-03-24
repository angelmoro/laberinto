/*
 * tileterrain.h
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#ifndef INC_TILETERRAIN_H_
#define INC_TILETERRAIN_H_

#include <string>



class TileTerrain
{
public:
	TileTerrain();
	~TileTerrain();
private:

	std::string name; // The name of the terrain type.
	int tile; // The local tile-id of the tile that represents the terrain visually
};



#endif /* INC_TILETERRAIN_H_ */
