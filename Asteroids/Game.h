#pragma once
#include <vector>
#include <string>
#include "GameObject.h"
#include "Asteroid.h"
#include "Player.h"
#include "SFML/Graphics.hpp"
class Game{
public:
	Game();
	~Game();
	void run();
private:
	float mDeltaTime;
	typedef std::vector<GameObject*> GameObjectList;
	GameObjectList* mGameObjects;
	sf::Texture* mGameTextures;
	sf::RenderWindow* mWindow;
	bool mGameIsntOver;
	Game* mGamePointer;
	sf::Clock* mGameClock;
};
namespace config{
	const sf::VideoMode GAME_RESOLUTION = sf::VideoMode(800, 600);
	const std::string WINDOW_TITLE = "Asteroids";
	const std::string TEXTURE_PATH = "./Textures/Textures.png";
	const int FRAMERATE_LIMIT = 60;
	const sf::Color BACKGROUND_COLOR = sf::Color::Black;
};

