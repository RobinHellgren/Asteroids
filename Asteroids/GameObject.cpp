#include "GameObject.h"




GameObject::GameObject(){
}


GameObject::~GameObject(){
}
sf::Sprite* GameObject::getMSprite() {
	return mSprite;
}
void GameObject::update() {
	//std::cout << "Fel update kördes" << std::endl;
}
void GameObject::spawn() {
	//std::cout << "Fel spawn kördes" << std::endl;
}