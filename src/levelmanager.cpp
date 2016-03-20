/*
 * levelmanager.cpp
 *
 *  Created on: 26/2/2016
 *      Author: Usuario
 */

#include "level.h"
#include "levelmanager.h"

LevelManager::LevelManager(Game *g)
{
	game = g;
}
LevelManager::~LevelManager()
{
	for (levels_iter=levels.begin(); levels_iter!=levels.end();
			levels_iter++)
	delete (*levels_iter);
}
void LevelManager::add(Level *l)
{

	levels.push_back(l);
	//Ojo con lo que se mete en el init, porque si el nivel se añade tambien al actor manager
	//se vuelve a llamar a init(), por eso voy a crear el metodo iniciar()
	l->init();
	l->iniciar();

}
void LevelManager::del(Level *l)
{

	list<Level*>::iterator tmp_levels_iter;
	tmp_levels_iter=find(levels.begin(), levels.end(), l);
	if (tmp_levels_iter!=levels.end())
	levels.erase(tmp_levels_iter);

}
void LevelManager::rewind()
{
	levels_iter=levels.begin();
}
Level *LevelManager::next()
{
	Level *tmp_l;
	tmp_l=*levels_iter;
	if (levels_iter==levels.end()) return NULL;
	levels_iter++;
	return tmp_l;
}
Level *LevelManager::current()
{
	if (levels_iter==levels.end()) return NULL;
	else
		return *levels_iter;
}
int LevelManager::num_levels()
{
	return levels.size();
}
void LevelManager::update()
{


}


list<Level*>::iterator LevelManager::get_begin_iterator()
{
	return levels.begin();
}
list<Level*>::iterator LevelManager::get_end_iterator()
{
	return levels.end();
}

void LevelManager::tick()
{
	/*
	 * Recorro todos los niveles y le envio el tick solo al activo
	 */
	list<Level*>::iterator tmp_iter;
	for (tmp_iter=get_begin_iterator();
			 tmp_iter!=get_end_iterator();
			 tmp_iter++)
	{
		if ((*tmp_iter)->nivel_activo()){
			(*tmp_iter)->tick();
		}
	}
}




