#include "MainMenu.h"
#include "Game.h"
#include "MenuManager.h"



MainMenu::MainMenu(Game* game, MenuManager* menuMngr){
	mMenu = menuMngr;
	mGame = game;
	mMainMenuRunning = true;
	

	mTitle.setFont(*mMenu->getTitleFont());
	mTitle.setFillColor(sf::Color::White);
	mTitle.setString("ASTEROIDS");
	mTitle.setCharacterSize(78);
	mTitle.setPosition(250, 200);

	mPlayButton.setFont(*mMenu->getBreadFont());
	mPlayButton.setFillColor(sf::Color::White);
	mPlayButton.setString("Play");
	mPlayButton.setCharacterSize(34);
	mPlayButton.setPosition(300, 300);
	
	mInstructionButton.setFont(*mMenu->getBreadFont());
	mInstructionButton.setFillColor(sf::Color::White);
	mInstructionButton.setString("Instructions");
	mInstructionButton.setCharacterSize(34);
	mInstructionButton.setPosition(300, 330);

	mQuitButton.setFont(*mMenu->getBreadFont());
	mQuitButton.setFillColor(sf::Color::White);
	mQuitButton.setString("Quit");
	mQuitButton.setCharacterSize(34);
	mQuitButton.setPosition(300, 360);

	mMenuPointer.setFont(*mMenu->getBreadFont());
	mMenuPointer.setFillColor(sf::Color::White);
	mMenuPointer.setString("*");
	mMenuPointer.setCharacterSize(34);
	mMenuPointer.setPosition(280, 300); 
}

MainMenu::~MainMenu()
{
}

void MainMenu::run(){
	mCurrentMenuItem = MenuItem::PLAY;
		while (mGame->getWindow()->isOpen() && mMainMenuRunning) {
			sf::Event event;
			while (mGame->getWindow()->pollEvent(event)) {

				if (event.type == sf::Event::Closed) {
					mGame->getWindow()->close();
					return;
				}
			}
			mGame->getWindow()->clear(sf::Color::Black);
			menuControlls();
			mGame->getWindow()->draw(mTitle);
			mGame->getWindow()->draw(mPlayButton);
			mGame->getWindow()->draw(mInstructionButton);
			mGame->getWindow()->draw(mQuitButton);
			mGame->getWindow()->draw(mMenuPointer);
			mGame->getWindow()->display();


		}

	}

void MainMenu::menuControlls() {
	std::cout << mMenu->getKeyIsPressed() << std::endl;
	sf::Event event;
	while (mGame->getWindow()->pollEvent(event)) {
		if (event.type == sf::Event::KeyPressed) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && mCurrentMenuItem == MenuItem::PLAY && !mMenu->getKeyIsPressed()) {
				mCurrentMenuItem = MenuItem::INTRUCTIONS;
				mMenuPointer.setPosition(280, 330);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && mCurrentMenuItem == MenuItem::INTRUCTIONS && !mMenu->getKeyIsPressed()) {
				mCurrentMenuItem = MenuItem::QUIT;
				mMenuPointer.setPosition(280, 360);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && mCurrentMenuItem == MenuItem::QUIT && !mMenu->getKeyIsPressed()) {
				mCurrentMenuItem = MenuItem::INTRUCTIONS;
				mMenuPointer.setPosition(280, 330);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && mCurrentMenuItem == MenuItem::INTRUCTIONS && !mMenu->getKeyIsPressed()) {
				mCurrentMenuItem = MenuItem::PLAY;
				mMenuPointer.setPosition(280, 300);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !mMenu->getKeyIsPressed()) {
				if (mCurrentMenuItem == MenuItem::PLAY) {
					mMainMenuRunning = false;
					mGame->getWindow()->clear();
					mGame->run();
				}
				if (mCurrentMenuItem == MenuItem::QUIT) {
					mMainMenuRunning = false;
				}
				if (mCurrentMenuItem == MenuItem::INTRUCTIONS) {
					mMainMenuRunning = false;
					mMenu->runInstructionPage();

				}
			}
			mMenu->setKeyIsPressed(true);
		}
		else if (event.type == sf::Event::KeyReleased) {
			mMenu->setKeyIsPressed(false);
		}
	}

}


