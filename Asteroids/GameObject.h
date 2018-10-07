#pragma once
#include "SFML\Graphics.hpp"
#include <string>
#include <iostream>
class Game;
class GameObject {
	
public:
	enum class ObjectType { PLAYER, ASTEROID, COIN };
	GameObject();
	~GameObject();
	ObjectType mType;
	virtual void spawn() = 0;
	virtual void update()= 0;
	sf::Sprite* getMSprite();
	int radius;
	Game* mGame;
	sf::Sprite* mSprite;

};