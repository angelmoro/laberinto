/*
 * peripheral.cpp
 *
 *  Created on: 31/1/2016
 *      Author: Usuario
 */

#include "peripheral.h"
#include <string.h>

Peripheral::Peripheral()
{
}
Peripheral::~Peripheral()
{
}
Peripheral::state_t Peripheral::get_state(state_t comp)
{
	return 0;
}
Peripheral::component_t Peripheral::get_change()
{
	return 0;
}
void Peripheral::reset()
{
}
string Peripheral::get_component_name(component_t comp)
{
	return "";
}
void Peripheral::evento(ALLEGRO_EVENT e)
{

}

