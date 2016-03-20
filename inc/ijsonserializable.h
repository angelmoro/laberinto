/*
 * ijsonserializable.h
 *
 *  Created on: 5/3/2016
 *      Author: Usuario
 */

#ifndef INC_IJSONSERIALIZABLE_H_
#define INC_IJSONSERIALIZABLE_H_

#include <json/json.h>

class IJsonSerializable
{
public:
   virtual ~IJsonSerializable( void ) {};
   virtual void Serialize( Json::Value& root ) =0;
   virtual void Deserialize( Json::Value& root) =0;
};


#endif /* INC_IJSONSERIALIZABLE_H_ */
