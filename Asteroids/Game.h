#pragma once
#include <vector>
#include <string>
#include "GameObject.h"
#include "Asteroid.h"
#include "Player.h"
#include "AsteroidHandler.h"
#include "SFML/Graphics.hpp"
class Game{
	typedef std::vector<GameObject*> GameObjectList;
public:
	Game();
	~Game();
	void run();
	float getDeltaTime();
	void getGameObjectList();
	sf::Texture* getGameTextures();
	sf::RenderWindow* getWindow();
	GameObjectList* mGameObjects;
private:
	float mDeltaTime;

	
	sf::Texture* mGameTextures;
	sf::RenderWindow* mWindow;
	bool mGameIsntOver;
	Game* mGamePointer;
	sf::Clock* mGameClock;
	AsteroidHandler* mAsteroidHandler;
};
namespace config{
	const sf::VideoMode GAME_RESOLUTION = sf::VideoMode(800, 600);
	const std::string WINDOW_TITLE = "Asteroids";
	const std::string TEXTURE_PATH = "./Textures/Textures.png";
	const int FRAMERATE_LIMIT = 60;
	const sf::Color BACKGROUND_COLOR = sf::Color::Black;
};

