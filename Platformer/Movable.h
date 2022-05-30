#pragma once

#include "GameObject.h"

class Movable : public GameObject
{
	float speed;
	sf::Vector2f direction;

public:
	enum Direction
	{ 
		UP, 
		LEFT, 
		DOWN, 
		RIGHT 
	};

	Movable(const float speed);

	void update(float deltaT);

	const sf::Vector2f& getDirection() const;

	void setDirection();
};