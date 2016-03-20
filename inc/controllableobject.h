/*
 * controllableobject.h
 *
 *  Created on: 30/1/2016
 *      Author: Usuario
 */

#ifndef INC_CONTROLLABLEOBJECT_H_
#define INC_CONTROLLABLEOBJECT_H_

class ControllableObject
{
	public:
		typedef int action_t;
		virtual void do_action(action_t action, int magnitude);
};



#endif /* INC_CONTROLLABLEOBJECT_H_ */
