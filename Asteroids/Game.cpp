#include "Game.h"


Game::Game(){
	mGameTextures = new sf::Texture;
	mGameTextures->loadFromFile(config::TEXTURE_PATH);

	mGameObjects = new GameObjectList;
	mGameObjects->push_back(new Player(mGameTextures));
	mWindow = new sf::RenderWindow(config::GAME_RESOLUTION, config::WINDOW_TITLE);
	mWindow->setFramerateLimit(config::FRAMERATE_LIMIT);
	
	mGameIsntOver = true;

	mGamePointer = this;

	for (unsigned int i = 0; i < mGameObjects->size(); i++) {
		mGameObjects->at(i)->spawn(mWindow);
		std::cout << typeid(mGameObjects->at(i)).name() << std::endl;
	}
}


Game::~Game(){
	delete mGameTextures;
	delete mGameObjects;
	delete mWindow;
}
void Game::run() {
	while (mWindow->isOpen() && mGameIsntOver) {
		sf::Event event;
		while (mWindow->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				mWindow->close();
			}
		}
		mWindow->clear(config::BACKGROUND_COLOR);
		for (unsigned int i = 0; i < mGameObjects->size(); i++) {
			mGameObjects->at(i)->update(mWindow);
			
		}



		mWindow->display();
	}
}
