#include "Game.h"


Game::Game(){
	mGameTextures = new sf::Texture;
	if(!mGameTextures->loadFromFile(config::TEXTURE_PATH)){
		std::cout << "Error  loading textures" << std::endl;
	}
	mGameObjects = new GameObjectList;
	mGameObjects->push_back(new Player(this));
	//mGameObjects->push_back(new Asteroid(mGameTextures));
	mGameClock = new sf::Clock;

	mWindow = new sf::RenderWindow(config::GAME_RESOLUTION, config::WINDOW_TITLE);
	mWindow->setFramerateLimit(config::FRAMERATE_LIMIT);
	
	mGameIsntOver = true;

	

	for (unsigned int i = 0; i < mGameObjects->size(); i++) {
		mGameObjects->at(i)->spawn();
		//std::cout << typeid(*mGameObjects->at(i)).name() << std::endl;
	}
}


Game::~Game(){
	for (unsigned int i = 0; i < mGameObjects->size(); i++) {
		delete mGameObjects->at(i);
	}
	delete mGameTextures;
	delete mGameObjects;
	delete mWindow;
}
void Game::run() {
	while (mWindow->isOpen() && mGameIsntOver) {
		//mGameObjects->push_back(new Asteroid(this));
		mDeltaTime = mGameClock->restart().asSeconds();
		sf::Event event;
		while (mWindow->pollEvent(event)) {
			
			if (event.type == sf::Event::Closed) {
				mWindow->close();
				return;
			}
		}
		mWindow->clear(config::BACKGROUND_COLOR);
		for (unsigned int i = 0; i < mGameObjects->size(); i++) {
			mGameObjects->at(i)->update();
			//std::cout << typeid(mGameObjects->at(i)).name() << std::endl;
			
		}



		mWindow->display();
	}
}
float Game::getDeltaTime() {
	return mDeltaTime;
}
sf::Texture* Game::getGameTextures() {
	return mGameTextures;
}
sf::RenderWindow* Game::getWindow() {
	return mWindow;
}
