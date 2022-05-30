#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class GameObject
{
	sf::Vector2f position;
	sf::Vector2f dimension;
	sf::IntRect collisionRect;

public:	
	GameObject();

	virtual void draw(sf::RenderWindow& window) = 0;

	bool collidesWith(const GameObject& other) const;
	bool contains(const sf::Vector2f& position) const;

	float getDistanceWith(const GameObject& other) const;
	float getDistanceWith(const sf::Vector2f position) const;

	const sf::Vector2f& getPosition() const;
	const sf::Vector2f& getDimension() const;

	void setPosition(const sf::Vector2f& position);
	void setDimension(const sf::Vector2f& dimension);

private:
	void computeCollisionRect();
};