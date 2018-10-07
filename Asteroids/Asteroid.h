#pragma once
#include "GameObject.h"
#include <string>
#include <random>
#include <iostream>
class Asteroid :
	public GameObject
{
public:
	Asteroid(Game* mGamePointer);
	~Asteroid();
	void update();
	void spawn();
	void movement();
	static void asteroidSpawner();
private:
	std::string mOriginPoint;
	std::mt19937 mRandomGen;
	sf::Vector2f mAsteroidMovement;
	int mAsteroidRotation;


};


