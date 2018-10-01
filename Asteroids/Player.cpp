#include "Player.h"



Player::Player(sf::Texture* texture){
	mSprite = new sf::Sprite;
	mSprite->setTexture(*texture);
	mSprite->setTextureRect(sf::IntRect(16, 0, 32, 34));
	mSprite->setPosition(400, 300);

}


Player::~Player(){
	delete mSprite;
}



void Player::movement() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		getMSprite()->rotate(-5);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		getMSprite()->rotate(5);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		float x = sinf(getMSprite()->getRotation() * 3.14 / 180) * 5;
		float y = -cosf(getMSprite()->getRotation() * 3.14 / 180) * 5;
		if (getMSprite()->getPosition().x > (800 - 15)) {
			x -=5;
		}
		if (getMSprite()->getPosition().x < (0 + 15)) {
			x +=5;
		}
		if (getMSprite()->getPosition().y > (600 - 15)) {
			y-=5;
		}
		if (getMSprite()->getPosition().y < 0 + 15) {
			y+=5;
		}
		getMSprite()->move(x, y);
	}	
}
void  Player::update(sf::RenderWindow* window) {
	movement();
	window->draw(*getMSprite());
	std::cout << "Player updated" << std::endl;
}
void Player::spawn(sf::RenderWindow* window) {
	window->draw(*mSprite);
	std::cout << "Player spawned" << std::endl;
}
