#include "RessourceManager.h"

#include <map>

RessourceManager::RessourceManager()
{
}

RessourceManager::~RessourceManager()
{
	clear();
}

void RessourceManager::clear()
{
	for (std::map<key, sf::Drawable*>::iterator i = ressources.begin(); i != ressources.end(); i++)
	{
		delete (*i).second;
	}
}