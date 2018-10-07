#pragma once
#include "SFML\Graphics.hpp"
#include <string>
#include <iostream>
class Game;
class GameObject {

public:

	GameObject();
	~GameObject();

	virtual void spawn() = 0;
	virtual void update()= 0;
	sf::Sprite* getMSprite();

	Game* mGame;
	sf::Sprite* mSprite;

};