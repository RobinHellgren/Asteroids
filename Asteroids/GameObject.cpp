#include "GameObject.h"




GameObject::GameObject(){
}


GameObject::~GameObject(){
}
sf::Sprite* GameObject::getMSprite() {
	return mSprite;
}
void GameObject::update() {
	//std::cout << "Fel update k�rdes" << std::endl;
}
void GameObject::spawn() {
	//std::cout << "Fel spawn k�rdes" << std::endl;
}