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
#include "EndMenu.h"

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
		quizButtons.push_back(QuestionButton(quizFilenames[i], fonts.get(Fonts::WhiteRabbit), 24, sf::Vector2f(200, 100), sf::Vector2f(100, 200 +( i * 100)), sf::Color(116, 40, 148, 255), sf::Color(181, 103, 214, 255)));
	}

	std::vector<QuestionButton> timerButtons;
	timerButtons.push_back(QuestionButton("15", fonts.get(Fonts::WhiteRabbit), 48, sf::Vector2f(200, 100), sf::Vector2f(500, 200), sf::Color(116, 40, 148, 255), sf::Color(181, 103, 214, 255)));
	timerButtons.push_back(QuestionButton("25", fonts.get(Fonts::WhiteRabbit), 48, sf::Vector2f(200, 100), sf::Vector2f(500, 300), sf::Color(116, 40, 148, 255), sf::Color(181, 103, 214, 255)));
	timerButtons.push_back(QuestionButton("35", fonts.get(Fonts::WhiteRabbit), 48, sf::Vector2f(200, 100), sf::Vector2f(500, 400), sf::Color(116, 40, 148, 255), sf::Color(181, 103, 214, 255)));

	//EndMenu Stuff
	Button endRetry(textures.get(Textures::Buttons), sf::Vector2f(250, 75), sf::Vector2f(25, 500),
		sf::IntRect(0, 450, 250, 75), sf::IntRect(0, 525, 250, 75)); 
	Button endQuit(textures.get(Textures::Buttons), sf::Vector2f(250,  75), sf::Vector2f(525, 500),
		sf::IntRect(0, 150, 250, 75), sf::IntRect(0, 225, 250,  75));

	sf::Vector2f endLogoPos(100, 0);

	std::vector<QuestionButton> endAnswers;
	endAnswers.push_back(QuestionButton("", fonts.get(Fonts::WhiteRabbit), 24, sf::Vector2f(640, 120), sf::Vector2f(80, 120), sf::Color(116, 40, 148, 255), sf::Color(116, 40, 148, 255)));
	endAnswers.push_back(QuestionButton("", fonts.get(Fonts::WhiteRabbit), 24, sf::Vector2f(640, 120), sf::Vector2f(80, 250), sf::Color::Green, sf::Color::Green));
	endAnswers.push_back(QuestionButton("", fonts.get(Fonts::WhiteRabbit), 24, sf::Vector2f(640, 120), sf::Vector2f(80, 380), sf::Color::Red, sf::Color::Red));

	
	


	//MAIN MENU
	Menu startMenu(mainWindow.getWindow(), mainPlayButton, mainQuitButton, 10, 20, 15, 45, textures.get(Textures::Timtam),
		sf::Vector2f(75, 200));
		

	bool play = startMenu.run();
	
	
	while(play)
	{
		play = false;
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

		if(timeToAns == 15 || timeToAns == 25 || timeToAns == 35)
		{
			//get the list of Q's
			Quiz quiz = Util::getQuiz("Quizes/" + quizFile, timeToAns);

			std::vector<QuestionButton> questionButtons;
			questionButtons.push_back(QuestionButton("", fonts.get(Fonts::WhiteRabbit), 18, sf::Vector2f(640, 120), sf::Vector2f(80, 210), sf::Color(116, 40, 148, 255), sf::Color(116, 40, 148, 255)));
			questionButtons.push_back(QuestionButton("", fonts.get(Fonts::WhiteRabbit), 18, sf::Vector2f(300, 120), sf::Vector2f(80, 340), sf::Color(116, 40, 148, 255), sf::Color(181, 103, 214, 255)));
			questionButtons.push_back(QuestionButton("", fonts.get(Fonts::WhiteRabbit), 18, sf::Vector2f(300, 120), sf::Vector2f(80, 470), sf::Color(116, 40, 148, 255), sf::Color(181, 103, 214, 255)));
			questionButtons.push_back(QuestionButton("", fonts.get(Fonts::WhiteRabbit), 18, sf::Vector2f(300, 120), sf::Vector2f(420, 340), sf::Color(116, 40, 148, 255), sf::Color(181, 103, 214, 255)));
			questionButtons.push_back(QuestionButton("", fonts.get(Fonts::WhiteRabbit), 18, sf::Vector2f(300, 120), sf::Vector2f(420, 470), sf::Color(116, 40, 148, 255), sf::Color(181, 103, 214, 255)));

			std::vector<AnswerCombo> answers;


		
			Game game(&mainWindow.getWindow(), quiz, questionButtons, 
				sf::Sprite(textures.get(Textures::Timtam), 
				sf::IntRect(0, 0, textures.get(Textures::Timtam).getSize().x, textures.get(Textures::Timtam).getSize().y)),
				fonts.get(Fonts::WhiteRabbit),
				32,
				sf::Color::Black);
			answers = game.run();

			if(answers.size() > 0)
			{
				//takes in answers.
				EndMenu endMenu(&mainWindow.getWindow(), endRetry, endQuit, textures.get(Textures::Timtam), endLogoPos,
					answers, endAnswers);
				play = endMenu.run();
			}
		}
	}
	

	return 0;
}