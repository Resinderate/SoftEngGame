#ifndef QUIZMENU_H
#define QUIZMENU_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "QuestionButton.h"

class QuizMenu
{
private:
	sf::RenderWindow	*m_window;
	Button				m_continueButton;
	sf::Text m_selectQuiz;
	sf::Text m_selectTime;
	std::vector<QuestionButton> m_quizButtons;
	std::vector<QuestionButton> m_timeButtons;
	sf::Sprite m_logo;

	std::string m_currentlySelectedQuizFile;
	int m_currentQuestionTimer;

	int				handleEvents();
	void			render();

public:
	QuizMenu(sf::RenderWindow &p_window, const Button &p_continueButton, const sf::Text &p_selectQuiz, 
		const sf::Text &p_selectTime, std::vector<QuestionButton> &p_quizButtons, std::vector<QuestionButton>&p_timeButtons,
		const sf::Texture &p_logoTexture, const sf::Vector2f &p_logoPos);
	int run(std::string &p_filename);
};
#endif