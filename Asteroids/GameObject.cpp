#include "GameObject.h"




GameObject::GameObject(){
}


GameObject::~GameObject(){
}
sf::Sprite* GameObject::getMSprite() {
	return mSprite;
}
void setMSprite(sf::Sprite sprite) {
	
}
void GameObject::update(sf::RenderWindow* window, float deltaTime, sf::Texture* texture) {
	std::cout << "Fel update kördes" << std::endl;
}
void GameObject::spawn(sf::RenderWindow* window) {
	std::cout << "Fel spawn kördes" << std::endl;
}