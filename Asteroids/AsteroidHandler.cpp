#include "AsteroidHandler.h"
#include "Game.h"
#include "Asteroid.h"
#include "iostream"
#include <math.h>

AsteroidHandler::AsteroidHandler(Game* game){
	mGame = game;
	mAsteroidAmount = 0;
	remainingAsteroids = new GameObjectList();
	asteroidTrashBin = new GameObjectList();
}


AsteroidHandler::~AsteroidHandler(){
	delete mGame;
}
void AsteroidHandler::spawnAsteroids() {
	mAsteroidSpawnClock += mGame->getDeltaTime();
	//std::cout << mAsteroidSpawnClock << std::endl;
	while (mAsteroidAmount < BASE_NUMBER_OF_ASTEROIDS && mAsteroidSpawnClock > 1.5f){
		mGame->mGameObjects->push_back(new Asteroid(mGame));
		mAsteroidAmount++;
		//std::cout << "Asteroid spawned" << std::endl;
		mAsteroidSpawnClock = 0;
	};
}
void AsteroidHandler::pruneAsteroids() {

	for (unsigned int i = 0; i < mGame->mGameObjects->size(); i++) {
		if (mGame->mGameObjects->at(i)->getMSprite()->getPosition().y < 0) {
			asteroidTrashBin->push_back(mGame->mGameObjects->at(i));
			std::cout << "Asteroid trashed" << std::endl;
			mAsteroidAmount--;
		}
		else if (mGame->mGameObjects->at(i)->getMSprite()->getPosition().y > 600) {
			asteroidTrashBin->push_back(mGame->mGameObjects->at(i));
			std::cout << "Asteroid trashed" << std::endl;
			mAsteroidAmount--;
		}
		else if (mGame->mGameObjects->at(i)->getMSprite()->getPosition().x < 0) {
			asteroidTrashBin->push_back(mGame->mGameObjects->at(i));
			std::cout << "Asteroid trashed" << std::endl;
			mAsteroidAmount--;
		}
		else if (mGame->mGameObjects->at(i)->getMSprite()->getPosition().x > 800) {
			asteroidTrashBin->push_back(mGame->mGameObjects->at(i));
			std::cout << "Asteroid trashed" << std::endl;
			mAsteroidAmount--;
		}
		else {
			remainingAsteroids->push_back(mGame->mGameObjects->at(i));
			//std::cout << "Asteroid saved" << std::endl;
		}
		mAsteroidAmount -= asteroidTrashBin->size();
		for (unsigned int i = 0; i < asteroidTrashBin->size(); i++) {
			delete asteroidTrashBin->at(i);
		}
		asteroidTrashBin->clear();
		
	}
}
void AsteroidHandler::reformGameObjectList() {
	*mGame->mGameObjects = *remainingAsteroids;
	remainingAsteroids->clear();

}
void AsteroidHandler::checkForCollisions() {
	for (unsigned int i = 0; i < mGame->mGameObjects->size(); i++){
		for (unsigned int j = i + 1; j < mGame->mGameObjects->size(); j++ ) {
			if (getDistanceBetweenObjects(mGame->mGameObjects->at(i), mGame->mGameObjects->at(i + 1)) <= mGame->mGameObjects->at(i)->radius + mGame->mGameObjects->at(j)->radius +3) {
				//TODO Collision logic function with object 2 as parameter
				std::cout << "COLLISION!" << std::endl;
			}


		}

	}
}
int AsteroidHandler::getDistanceBetweenObjects(GameObject* obj1, GameObject* obj2) {
	int distanceX = obj1->getMSprite()->getPosition().x - obj2->getMSprite()->getPosition().x;
	int distanceY = obj1->getMSprite()->getPosition().y - obj2->getMSprite()->getPosition().y;
	return sqrt(pow(distanceX, 2) + pow(distanceY, 2));
}
