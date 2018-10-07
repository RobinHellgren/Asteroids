#pragma once
class Game;
class AsteroidHandler
{

public:
	AsteroidHandler(Game* game);
	~AsteroidHandler();
	void spawnAsteroids();
	void pruneAsteroids();

private:
	int mAsteroidAmount;
};
namespace {
	const int BASE_NUMBER_OF_ASTEROIDS = 5;
	const double ASTEROID_SPAWN_DELTA = 0.5;
}

