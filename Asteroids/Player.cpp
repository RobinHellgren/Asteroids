#include "Player.h"



Player::Player(Game *mGamePointer){
	Player::mGame = mGamePointer;
	mSprite = new sf::Sprite;
	mSprite->setTexture(*mGame.mGameTextures);
	mSprite->setTextureRect(sf::IntRect(16, 0, 32, 34));
	mSprite->setPosition(400, 300);
	mSprite->setOrigin(16, 16);
	Player::mGame = mGamePointer;

}


Player::~Player(){
	delete mSprite;
}


void Player::movement() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		getMSprite()->rotate(*mGame.mDeltaTime * -PLAYER_ROTATION_SPEED);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		getMSprite()->rotate(*mGame.mDeltaTime * PLAYER_ROTATION_SPEED);
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
		getMSprite()->move(x * *mGame.mDeltaTime, y * *mGame.mDeltaTime);
	}	
}
void  Player::update() {
	movement(*mGame.mDeltaTime);
	*mGame.mWindow.draw(*getMSprite());
	//std::cout << "Player updated" << std::endl;
}
void Player::spawn() {
	*mGame.mWindow->draw(*mSprite);
	//std::cout << "Player spawned" << std::endl;
}
