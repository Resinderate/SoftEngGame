#ifndef GAME_H
#define GAME_H


#include "SFML\Graphics.hpp"
#include "Quiz.h"
#include "QuestionButton.h"
#include "Util.h"
#include "AnswerCombo.h"

class QuestionButton;
class Game
{

private:
	sf::RenderWindow* m_window;
	bool m_stillPlaying;
	bool m_retry;
	Quiz m_quiz;
	std::vector<AnswerCombo> m_answers;
	sf::Clock m_questionTimer;
	Question m_currentQuestion;
	std::vector<QuestionButton> m_questionButtons;
	sf::Sprite m_logo;
	int m_currentQuestionCounter;
	int m_totalQuestionsCounter;
	sf::Text m_currentQuestionNumberText;
	sf::Text m_timeLeftToAnswerText;
	int m_maxTimePerQuestion;

	void update();
	void render();
	void handleEvents();
	void forceQuit();
	void changeQuestion();
	void drawButtons();
	void drawButtonText();
	void drawHeader();
	void drawLogo();
	void nextQuestion(bool p_correct, std::string p_question, std::string p_answer, std::string p_guess);
	void updateButtons();
	void updateQuestionNumberText();
	void drawCurrentQuestionNumber();
	void checkQuestionTimeLimit();
	void updateTimeLeftToAnswerText();
	void drawTimeLeftToAnswer();
public:
	Game(sf::RenderWindow* p_window, Quiz p_quiz, std::vector<QuestionButton> p_questionButtons, sf::Sprite p_logo, const sf::Font &p_font, int p_fontSize, const sf::Color &p_color);
	std::vector<AnswerCombo> run();
};
#endif