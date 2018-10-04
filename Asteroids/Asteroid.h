#pragma once
#include "GameObject.h"
#include <string>
#include <random>
#include <iostream>
class Asteroid :
	public GameObject
{
public:
	Asteroid(sf::Texture* texture);
	~Asteroid();
	void update(sf::RenderWindow* window, float deltaTime, sf::Texture* texture);
	void spawn(sf::RenderWindow* window);
	void movement();
private:
	std::string mOriginPoint;
	std::mt19937 mRandomGen;
	sf::Vector2f mAsteroidMovement;
	int mAsteroidRotation;
};

