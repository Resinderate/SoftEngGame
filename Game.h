#ifndef GAME_H
#define GAME_H


#include "SFML\Graphics.hpp"
#include "Quiz.h"
#include "QuestionButton.h"
class QuestionButton;
class Game
{

private:
	sf::RenderWindow* m_window;
	bool m_stillPlaying;
	bool m_retry;
	Quiz m_quiz;
	sf::Time m_questionTimer;
	Question m_currentQuestion;
	std::vector<QuestionButton> m_questionButtons;
	sf::Sprite m_logo;

	void update();
	void render();
	void handleEvents();
	void forceQuit();
	void changeQuestion();
	void drawButtons();
	void drawButtonText();
	void drawHeader();
	void drawLogo();
public:
	Game(sf::RenderWindow* p_window, Quiz p_quiz, std::vector<QuestionButton> p_questionButtons, sf::Sprite p_logo, sf::Vector2f p_logoPos);
	bool run();
};
#endif