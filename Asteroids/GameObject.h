#pragma once
#include "SFML\Graphics.hpp"
#include <string>
#include <iostream>
class GameObject {

public:

	GameObject();
	~GameObject();

	virtual void spawn(sf::RenderWindow* window);
	virtual void update(sf::RenderWindow* window);
	sf::Sprite* getMSprite();
	void setMSprite(sf::Sprite);


	sf::Sprite* mSprite;

};