#pragma once
#include "GameObject.h"
#include <iostream>

class Player : public GameObject{

public:
	Player(sf::Texture* texture);
	~Player();
	void movement();
	void update(sf::RenderWindow* window);
	void spawn(sf::RenderWindow* window);

};

