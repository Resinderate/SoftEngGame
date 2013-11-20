/*
	main.cpp
	Written by Ronan Murphy circa Aug-Sep 2013.
*/
#include "Window.h"
#include "Game.h"
#include "ResourceHolder.hpp"
#include "ResourceUtil.h"
#include "Menu.h"
#include "Button.h"
#include "Question.h"

#include <iostream>

int main()
{
	srand(time(0));
	ResourceHolder<sf::Font, Fonts::ID> fonts;
	ResourceHolder<sf::Texture, Textures::ID> textures;
	//ResourceHolder<sf::SoundBuffer, Sounds::ID> sounds;
	try
	{
		fonts.load(Fonts::WhiteRabbit, "Assets/whiterabbit.ttf");
		textures.load(Textures::Buttons, "Assets/buttons.png");
		textures.load(Textures::Timtam, "Assets/cmcquiz.png");
	}
	catch(std::runtime_error &e)
	{
		//would be better off using a log file for release code.
		return 1;
	}

	Window mainWindow(sf::Vector2f(800, 600), "Soft Eng Game");

	
	Button mainPlayButton(textures.get(Textures::Buttons), sf::Vector2f(250,  75), sf::Vector2f(25, 500),
		sf::IntRect(0, 0, 250, 75), sf::IntRect(0, 75, 250,  75));
	Button mainQuitButton(textures.get(Textures::Buttons), sf::Vector2f(250,  75), sf::Vector2f(525, 500),
		sf::IntRect(0, 150, 250, 75), sf::IntRect(0, 225, 250,  75));

	


	//MAIN MENU
	Menu startMenu(mainWindow.getWindow(), mainPlayButton, mainQuitButton, 10, 20, 15, 45, textures.get(Textures::Timtam),
		sf::Vector2f(75, 200));
		

	bool play = startMenu.run();
	
	//quiz reader, gets a list of quizes from a dir and displays them.
	//pick one and return with that number.

	//use the quiz at that index.

	//get the list of Q's
	std::vector<Question> qs;
	qs.push_back(Question("Q", "A", "A", "A", "A"));
	qs.push_back(Question("Q", "A", "A", "A", "A"));
	qs.push_back(Question("Q", "A", "A", "A", "A"));
	qs.push_back(Question("Q", "A", "A", "A", "A"));
	qs.push_back(Question("Q", "A", "A", "A", "A"));
	qs.push_back(Question("Q", "A", "A", "A", "A"));

	//need to get a time to answer somehow.
	Quiz quiz(qs, 10);

	std::vector<QuestionButton> questionButtons;
	questionButtons.push_back(QuestionButton("", fonts.get(Fonts::WhiteRabbit), 18, sf::Vector2f(640, 120), sf::Vector2f(80, 210), sf::Color::Blue, sf::Color::Red));
	questionButtons.push_back(QuestionButton("", fonts.get(Fonts::WhiteRabbit), 18, sf::Vector2f(300, 120), sf::Vector2f(80, 340), sf::Color::Blue, sf::Color::Red));
	questionButtons.push_back(QuestionButton("", fonts.get(Fonts::WhiteRabbit), 18, sf::Vector2f(300, 120), sf::Vector2f(80, 470), sf::Color::Blue, sf::Color::Red));
	questionButtons.push_back(QuestionButton("", fonts.get(Fonts::WhiteRabbit), 18, sf::Vector2f(300, 120), sf::Vector2f(420, 340), sf::Color::Blue, sf::Color::Red));
	questionButtons.push_back(QuestionButton("", fonts.get(Fonts::WhiteRabbit), 18, sf::Vector2f(300, 120), sf::Vector2f(420, 470), sf::Color::Blue, sf::Color::Red));
	
	while(play)
	{
		Game game(&mainWindow.getWindow(), quiz, questionButtons, 
			sf::Sprite(textures.get(Textures::Timtam), 
			sf::IntRect(0, 0, textures.get(Textures::Timtam).getSize().x, textures.get(Textures::Timtam).getSize().y)),
			sf::Vector2f(0,0));
		play = game.run();
	}

	return 0;
}


/*
	Button pauseContButton(textures.get(Textures::Buttons), sf::Vector2f(250, 75), sf::Vector2f(275, 212.5),
		sf::IntRect(0, 300, 250, 75), sf::IntRect(0, 375, 250, 75));
	Button pauseQuitButton(textures.get(Textures::Buttons), sf::Vector2f(250,  75), sf::Vector2f(275, 312.5),
		sf::IntRect(0, 150, 250, 75), sf::IntRect(0, 225, 250,  75));

	Button endRetryButton(textures.get(Textures::Buttons), sf::Vector2f(250, 75), sf::Vector2f(25, 500),
		sf::IntRect(0, 450, 250, 75), sf::IntRect(0, 525, 250, 75));
	Button endQuitButton(textures.get(Textures::Buttons), sf::Vector2f(250,  75), sf::Vector2f(525, 500),
		sf::IntRect(0, 150, 250, 75), sf::IntRect(0, 225, 250,  75));
	*/