#pragma once
#include "GameObject.h"
#include <iostream>

class Player : public GameObject{

public:
	Player(Game* mGamePointer);
	~Player();
	void movement(Game* gamePointer);
	void update();
	void spawn();

};
namespace {
	int PLAYER_FOWARD_SPEED = 350;
	int PLAYER_ROTATION_SPEED = 250;
}

