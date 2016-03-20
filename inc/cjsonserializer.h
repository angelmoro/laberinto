/*
 * cjsonserializer.h
 *
 *  Created on: 5/3/2016
 *      Author: Usuario
 */

#ifndef INC_CJSONSERIALIZER_H_
#define INC_CJSONSERIALIZER_H_

#include <string>
#include "ijsonserializable.h"

class CJsonSerializer
{
	public:
	   static bool Serialize( IJsonSerializable* pObj, std::string& output );
	   static bool Deserialize( IJsonSerializable* pObj, std::string& input );

	private:
	   CJsonSerializer( void ) {};
};



#endif /* INC_CJSONSERIALIZER_H_ */
