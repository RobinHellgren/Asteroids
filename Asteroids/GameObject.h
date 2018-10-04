#pragma once
#include "SFML\Graphics.hpp"
#include <string>
#include <iostream>
class Game;
class GameObject {

public:

	GameObject();
	~GameObject();

	virtual void spawn(sf::RenderWindow* window);
	virtual void update(sf::RenderWindow* window, float deltaTime, sf::Texture* texture);
	sf::Sprite* getMSprite();

	Game mGame;
	sf::Sprite* mSprite;

};