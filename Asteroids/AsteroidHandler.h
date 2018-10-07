#pragma once
#include <vector>
#include "GameObject.h"
typedef std::vector<GameObject*> GameObjectList;
class Game;
class AsteroidHandler
{

public:
	AsteroidHandler(Game* game);
	~AsteroidHandler();
	void spawnAsteroids();
	void pruneAsteroids();
	void reformGameObjectList();
	void checkForCollisions();

	int getDistanceBetweenObjects(GameObject*, GameObject* obj2);
private:
	int mAsteroidAmount;
	float mAsteroidSpawnClock;
	Game* mGame; 
	GameObjectList* asteroidTrashBin;
	GameObjectList* remainingAsteroids;

};
namespace {
	const int BASE_NUMBER_OF_ASTEROIDS = 5;
	const double ASTEROID_SPAWN_DELTA = 0.5;
}

