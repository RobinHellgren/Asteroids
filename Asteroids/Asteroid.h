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
	void update()override;
	void spawn()override;
	void colide(GameObject* objectColidedWith) override;
private:
	std::string mOriginPoint;
	std::mt19937 mRandomGen;
	sf::Vector2f mAsteroidMovement;
	int mAsteroidRotation;


};


