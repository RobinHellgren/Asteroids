#include "Player.h"
#include "Game.h"



Player::Player(Game* mGamePointer){
	mGame = mGamePointer;
	mSprite = new sf::Sprite;
	mSprite->setTexture(*mGame->getGameTextures());
	mSprite->setTextureRect(sf::IntRect(16, 0, 32, 34));
	mSprite->setPosition(400, 300);
	mSprite->setOrigin(16, 16);
	mType = ObjectType::PLAYER;
	radius = 13;
}


Player::~Player(){
	delete mSprite;
}


void Player::movement() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		getMSprite()->rotate(mGame->getDeltaTime() * -PLAYER_ROTATION_SPEED);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		getMSprite()->rotate(mGame->getDeltaTime() * PLAYER_ROTATION_SPEED);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		float x = sinf(getMSprite()->getRotation() * 3.14 / 180) * PLAYER_FOWARD_SPEED;
		float y = -cosf(getMSprite()->getRotation() * 3.14 / 180) * PLAYER_FOWARD_SPEED;
		if (getMSprite()->getPosition().x > (800 - 15)) {
			x -= PLAYER_FOWARD_SPEED;
		}
		if (getMSprite()->getPosition().x < (0 + 15)) {
			x += PLAYER_FOWARD_SPEED;
		}
		if (getMSprite()->getPosition().y > (600 - 15)) {
			y-= PLAYER_FOWARD_SPEED;
		}
		if (getMSprite()->getPosition().y < 0 + 15) {
			y+= PLAYER_FOWARD_SPEED;
		}
		getMSprite()->move(x * mGame->getDeltaTime(), y * mGame->getDeltaTime());
	}	
}
void  Player::update() {
	movement();
	mGame->getWindow()->draw(*getMSprite());
	//std::cout << "Player updated" << std::endl;
}
void Player::spawn() {
	mGame->getWindow()->draw(*mSprite);
	//std::cout << "Player spawned" << std::endl;
}
