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
	while (mAsteroidAmount < BASE_NUMBER_OF_ASTEROIDS +(ASTEROID_SPAWN_DELTA * mGame->getLevel()) && mAsteroidSpawnClock > 0.5f){
		mGame->mGameObjects->push_back(new Asteroid(mGame));
		mAsteroidAmount++;
		//std::cout << mAsteroidAmount << std::endl;
		mAsteroidSpawnClock = 0;
	};
}
void AsteroidHandler::pruneAsteroids() {

	for (unsigned int i = 0; i < mGame->mGameObjects->size(); i++) {
		if (mGame->mGameObjects->at(i)->getMSprite()->getPosition().y < 0) {
			asteroidTrashBin->push_back(mGame->mGameObjects->at(i));
			//std::cout << "Asteroid trashed y<0" << std::endl;
			mAsteroidAmount--;
		}
		else if (mGame->mGameObjects->at(i)->getMSprite()->getPosition().y > 600) {
			asteroidTrashBin->push_back(mGame->mGameObjects->at(i));
			//std::cout << "Asteroid trashed y>600" << std::endl;
			mAsteroidAmount--;
		}
		else if (mGame->mGameObjects->at(i)->getMSprite()->getPosition().x < 0) {
			asteroidTrashBin->push_back(mGame->mGameObjects->at(i));
			//std::cout << "Asteroid trashed x<0" << std::endl;
			mAsteroidAmount--;
		}
		else if (mGame->mGameObjects->at(i)->getMSprite()->getPosition().x > 800) {
			asteroidTrashBin->push_back(mGame->mGameObjects->at(i));
			//std::cout << "Asteroid trashed x>800" << std::endl;
			mAsteroidAmount--;
		}
		else if (mGame->mGameObjects->at(i)->mMarkedForDeletion == true) {
			asteroidTrashBin->push_back(mGame->mGameObjects->at(i));
			mAsteroidAmount--;
		}
		else {
			remainingAsteroids->push_back(mGame->mGameObjects->at(i));
			//std::cout << "Asteroid saved" << std::endl;
		}
		
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
			if (getDistanceBetweenObjects(mGame->mGameObjects->at(i), mGame->mGameObjects->at(j)) <= mGame->mGameObjects->at(i)->radius + mGame->mGameObjects->at(j)->radius ) {
				//TODO Collision logic function with object 2 as parameter
				//std::cout << "COLLISION! "  << std::endl;
				mGame->mGameObjects->at(i)->colide(mGame->mGameObjects->at(j));
				mGame->mGameObjects->at(j)->colide(mGame->mGameObjects->at(i));
			}
		}

	}
}
int AsteroidHandler::getDistanceBetweenObjects(GameObject* obj1, GameObject* obj2) {
	int distanceX = obj1->getMSprite()->getPosition().x - obj2->getMSprite()->getPosition().x;
	int distanceY = obj1->getMSprite()->getPosition().y - obj2->getMSprite()->getPosition().y;
	return sqrt(pow(distanceX, 2) + pow(distanceY, 2));
}
