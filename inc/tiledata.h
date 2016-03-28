/*
 * tiledata.h
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#ifndef INC_TILEDATA_H_
#define INC_TILEDATA_H_

#include <string>
#include <vector>
#include "tinyxml2.h"


class TileData
{
public:
	TileData(tinyxml2::XMLElement * t);
	~TileData();
	void parse();
	void rewind();
	int next();
	int current();
	int num_tiles();

	std::vector<int>::iterator get_begin_iterator();
	std::vector<int>::iterator get_end_iterator();

	int get_tile_gid(int pos);

private:

	std::string encoding; // The encoding used to encode the tile layer data. When used, it can be "base64" and "csv" at the moment.
	std::string compression; // The compression used to compress the tile layer data. Tiled Qt supports "gzip" and "zlib".
//tile

	std::string data;
	std::vector<int> vtiles; //vector con los tile id
	std::vector<int>::iterator vtiles_iter;

	tinyxml2::XMLElement * root_tiledata;
};



#endif /* INC_TILEDATA_H_ */
