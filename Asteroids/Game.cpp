#include "Game.h"

Game::Game(){

	mGameTextures = new sf::Texture;
	if(!mGameTextures->loadFromFile(config::TEXTURE_PATH)){
		std::cout << "Error  loading textures" << std::endl;
	}
	mGameObjects = new GameObjectList;
	mGameObjects->push_back(new Player(this));
	mGameObjects->push_back(new Coin(this));
	//mGameObjects->push_back(new Asteroid(mGameTextures));
	mGameClock = new sf::Clock;
	mAsteroidHandler = new AsteroidHandler(this);
	mWindow = new sf::RenderWindow(config::GAME_RESOLUTION, config::WINDOW_TITLE);
	mWindow->setFramerateLimit(config::FRAMERATE_LIMIT);
	
	mGameIsntOver = true;

	

	for (unsigned int i = 0; i < mGameObjects->size(); i++) {
		mGameObjects->at(i)->spawn();
		//std::cout << typeid(*mGameObjects->at(i)).name() << std::endl;
	}
}


Game::~Game(){
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
			//std::cout << typeid(*mGameObjects->at(i)).name() << std::endl;	
		}
		mAsteroidHandler->checkForCollisions();
		mAsteroidHandler->spawnAsteroids();
		mAsteroidHandler->pruneAsteroids();
		mAsteroidHandler->reformGameObjectList();

		mWindow->display();


	}
}
float Game::getDeltaTime() {
	return mDeltaTime;
}
void Game::setGameIsntOver(bool newValue) {
	mGameIsntOver = newValue;
}
sf::Texture* Game::getGameTextures() {
	return mGameTextures;
}
sf::RenderWindow* Game::getWindow() {
	return mWindow;
}

int Game::getLevel()
{
	return mLevel;
}

void Game::increaseLevel(){
	mLevel++;
}

