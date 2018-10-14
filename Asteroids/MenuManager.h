#pragma once
#include "SFML/Graphics.hpp"
#include "GameOverScreen.h"
#include "InstructionPage.h"
#include "MainMenu.h"
class MenuManager
{
public:
	MenuManager(Game* game);
	~MenuManager();
	sf::Font* getTitleFont();
	sf::Font* getBreadFont();
	void runMainMenu();
	void runInstructionPage();
	bool getKeyIsPressed();
	void setKeyIsPressed(bool state);
private:
	sf::Font* mTitleFont;
	sf::Font* mBreadFont;
	Game* mGame;
	bool mKeyIsPressed;
};

