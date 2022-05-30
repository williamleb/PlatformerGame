#pragma once
#include <SFML/Graphics.hpp>
#include <map>

 class RessourceManager
 {
	 using key = unsigned int;

	 std::map<key, sf::Drawable*> ressources;

	 RessourceManager();
	 RessourceManager(const RessourceManager&) = delete;
	 RessourceManager& operator=(const RessourceManager&) = delete;
 public:
	 ~RessourceManager();
	 void clear();

	 RessourceManager* getInstance();

	 void add(sf::Drawable*);
	 sf::Drawable* operator[](const unsigned int);
 };