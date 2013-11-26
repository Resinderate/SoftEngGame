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
#include "Util.h"
#include "QuizMenu.h"

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

	//QuizSelect stuff
	Button quizMenuContinue(textures.get(Textures::Buttons), sf::Vector2f(250, 75), sf::Vector2f(250, 500),
		sf::IntRect(0, 300, 250, 75), sf::IntRect(0, 375, 250, 75));

	sf::Text selectQuiz("Select Quiz", fonts.get(Fonts::WhiteRabbit), 24);
	selectQuiz.setPosition(150, 150);
	sf::Text selectTime("Select Time", fonts.get(Fonts::WhiteRabbit), 24);
	selectTime.setPosition(500, 150);

	std::vector<QuestionButton> quizButtons;
	std::vector<std::string> quizFilenames;
	Util::getFilenamesInDir(quizFilenames, "Quizes");
	for(int i = 0; i < quizFilenames.size(); i++)
	{
		quizButtons.push_back(QuestionButton(quizFilenames[i], fonts.get(Fonts::WhiteRabbit), 24, sf::Vector2f(200, 100), sf::Vector2f(100, 200 +( i * 100)), sf::Color::Blue, sf::Color::Red));
	}

	std::vector<QuestionButton> timerButtons;
	timerButtons.push_back(QuestionButton("15", fonts.get(Fonts::WhiteRabbit), 48, sf::Vector2f(200, 100), sf::Vector2f(500, 200), sf::Color::Blue, sf::Color::Red));
	timerButtons.push_back(QuestionButton("25", fonts.get(Fonts::WhiteRabbit), 48, sf::Vector2f(200, 100), sf::Vector2f(500, 300), sf::Color::Blue, sf::Color::Red));
	timerButtons.push_back(QuestionButton("35", fonts.get(Fonts::WhiteRabbit), 48, sf::Vector2f(200, 100), sf::Vector2f(500, 400), sf::Color::Blue, sf::Color::Red));
	


	//MAIN MENU
	Menu startMenu(mainWindow.getWindow(), mainPlayButton, mainQuitButton, 10, 20, 15, 45, textures.get(Textures::Timtam),
		sf::Vector2f(75, 200));
		

	bool play = startMenu.run();
	
	if(play == 1)
	{
		//quiz reader, gets a list of quizes from a dir and displays them.
		//pick one and return with that number.

		//pick a filename / quiz file.
		std::string quizFile;

		//QUIZ CHOICE AND TIMER MENU
		QuizMenu quizMenu(mainWindow.getWindow(), quizMenuContinue, selectQuiz, selectTime, quizButtons, timerButtons, 
			textures.get(Textures::Timtam), sf::Vector2f(100, 0));

		int timeToAns = 0;
		timeToAns = quizMenu.run(quizFile);
		//use the quiz at that index.

		//get the list of Q's
		Quiz quiz = Util::getQuiz("Quizes/" + quizFile, timeToAns);

		std::vector<QuestionButton> questionButtons;
		questionButtons.push_back(QuestionButton("", fonts.get(Fonts::WhiteRabbit), 18, sf::Vector2f(640, 120), sf::Vector2f(80, 210), sf::Color::Blue, sf::Color::Red));
		questionButtons.push_back(QuestionButton("", fonts.get(Fonts::WhiteRabbit), 18, sf::Vector2f(300, 120), sf::Vector2f(80, 340), sf::Color::Blue, sf::Color::Red));
		questionButtons.push_back(QuestionButton("", fonts.get(Fonts::WhiteRabbit), 18, sf::Vector2f(300, 120), sf::Vector2f(80, 470), sf::Color::Blue, sf::Color::Red));
		questionButtons.push_back(QuestionButton("", fonts.get(Fonts::WhiteRabbit), 18, sf::Vector2f(300, 120), sf::Vector2f(420, 340), sf::Color::Blue, sf::Color::Red));
		questionButtons.push_back(QuestionButton("", fonts.get(Fonts::WhiteRabbit), 18, sf::Vector2f(300, 120), sf::Vector2f(420, 470), sf::Color::Blue, sf::Color::Red));

		std::vector<AnswerCombo> answers;

		//while(play)
		//{
		Game game(&mainWindow.getWindow(), quiz, questionButtons, 
			sf::Sprite(textures.get(Textures::Timtam), 
			sf::IntRect(0, 0, textures.get(Textures::Timtam).getSize().x, textures.get(Textures::Timtam).getSize().y)),
			fonts.get(Fonts::WhiteRabbit),
			32,
			sf::Color::White);
		answers = game.run();

		//takes in answers.
		//EndMenu end();
		//}
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