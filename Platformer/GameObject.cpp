#include "GameObject.h"

#include <cmath>

/// <summary>
/// Crée un nouveau <see cref="GameObject"/>.
/// </summary>
GameObject::GameObject()
	:position(), dimension(), collisionRect()
{
}

/// <summary>
/// Affiche l'objet sur la fenêtre spécifiée.
/// </summary>
/// <param name="window">La fenêtre avec laquelle afficher l'objet.</param>
void GameObject::draw(sf::RenderWindow& window)
{
	// TODO avec le gérant de ressources
	// setPosition du sprite avec la position
}

/// <summary>
/// Vérifie la collision entre deux objets.
/// </summary>
/// <param name="other">L'objet avec lequel vérifier la colision.</param>
/// <returns>True si les deux objets sont en collision; false sinon.</returns>
bool GameObject::collidesWith(const GameObject& other) const
{
	return collisionRect.intersects(other.collisionRect);
}

/// <summary>
/// Détermine si l'objet contient une position spécifique.
/// </summary>
/// <param name="position">La position avec laquelle vérifier la collision.</param>
/// <returns>True si l'objet contient la position; false sinon.</returns>
bool GameObject::contains(const sf::Vector2f& position) const
{
	return collisionRect.contains(position.x, position.y);
}

/// <summary>
/// Calcule la distance entre deux objets.
/// </summary>
/// <param name="other">L'objet avec lequel vérifier la distance.</param>
/// <returns>La distance entre les deux objets.</returns>
float GameObject::getDistanceWith(const GameObject& other) const
{
	return getDistanceWith(other.getPosition());
}

/// <summary>
/// Calcle la distance entre l'objet et une position.
/// </summary>
/// <param name="position">La position avec laquelle calculer la distance.</param>
/// <returns>La distance entre l'objet et la position.</returns>
float GameObject::getDistanceWith(const sf::Vector2f position) const
{
	float xSqrdVal = (this->position.x + position.x) * (this->position.x + position.x);
	float ySqrdVal = (this->position.y + position.y) * (this->position.y + position.y);

	return sqrt(xSqrdVal + ySqrdVal);
}

/// <summary>
/// Retourne la position du centre de l'objet.
/// </summary>
/// <returns>La position du centre de l'objet.</returns>
const sf::Vector2f& GameObject::getPosition() const
{
	return position;
}

/// <summary>
/// Retourne les dimensions de l'objet.
/// </summary>
/// <returns>Les dimensions de l'objet.</returns>
const sf::Vector2f& GameObject::getDimension() const
{
	return dimension;
}

/// <summary>
/// Change la position du centre de l'objet.
/// </summary>
/// <param name="position">La position du centre de l'objet.</param>
void GameObject::setPosition(const sf::Vector2f& position)
{
	this->position = position;
	computeCollisionRect();
}

/// <summary>
/// Change les dimensions de l'objet.
/// </summary>
/// <param name="dimension">Les dimensions de l'objet.</param>
void GameObject::setDimension(const sf::Vector2f& dimension)
{
	this->dimension = dimension;
	computeCollisionRect();
}

/// <summary>
/// Change le retangle de collision dépendamment des attributs de l'objet.
/// </summary>
void GameObject::computeCollisionRect()
{
	collisionRect.left = position.x - (dimension.x / 2);
	collisionRect.top = position.y - (dimension.y / 2);
	collisionRect.width = dimension.x;
	collisionRect.height = dimension.y;
}