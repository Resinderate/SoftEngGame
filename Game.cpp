#include "Game.h"

Game::Game(sf::RenderWindow* p_window, Quiz p_quiz, std::vector<QuestionButton> p_questionButtons, sf::Sprite p_logo, const sf::Font &p_font, int p_fontSize, const sf::Color &p_color) :
	m_window(p_window),
	m_stillPlaying(true),
	m_retry(true),
	m_quiz(p_quiz),
	m_questionButtons(p_questionButtons),
	m_logo(p_logo),
	m_answers(),
	m_currentQuestionCounter(1),
	m_totalQuestionsCounter(p_quiz.questionCountRemaining()),
	m_currentQuestionNumberText("", p_font, p_fontSize)
{
	m_logo.setOrigin(m_logo.getLocalBounds().width / 2, 0);
	m_logo.setPosition(m_window->getSize().x / 2, 0);
	
	m_currentQuestionNumberText.setPosition(20, 120);
	m_currentQuestionNumberText.setColor(p_color);
	updateQuestionNumberText();

	m_currentQuestion = m_quiz.popQuestion();
	m_questionButtons[0].setText(m_currentQuestion.getQuestion());
	m_questionButtons[1].setText(m_currentQuestion.getAnswer());
	m_questionButtons[2].setText(m_currentQuestion.getWrongAnswers()[0]);
	m_questionButtons[3].setText(m_currentQuestion.getWrongAnswers()[1]);
	m_questionButtons[4].setText(m_currentQuestion.getWrongAnswers()[2]);
}

std::vector<AnswerCombo> Game::run()
{
	while(m_stillPlaying && m_window->isOpen())
	{
		handleEvents();

		update();
		render();
	}
	return m_answers;
}

void Game::render()
{
	m_window->clear(sf::Color::Black);
	drawButtons();
	drawButtonText();
	drawHeader();
	drawCurrentQuestionNumber();
	m_window->display();
}

void Game::update()
{
	
}

void Game::handleEvents()
{
	sf::Event event;
	while (m_window->pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
		{
			forceQuit();
		}

		if(event.type == sf::Event::MouseMoved)
		{
			//Buttons
			for(int i = 0; i < m_questionButtons.size(); i++)
			{
				if(m_questionButtons[i].getShape().getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
					m_questionButtons[i].startHover();
				else
					m_questionButtons[i].endHover();
			}
		}

		//clicks
		if(event.type == sf::Event::MouseButtonReleased)
		{
			if(event.mouseButton.button == sf::Mouse::Left)
			{
				for(int i = 0; i < m_questionButtons.size(); i++)
				{
					if(m_questionButtons[i].getShape().getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
					{
						nextQuestion(m_questionButtons[i].getString() == m_currentQuestion.getAnswer(), 
							m_currentQuestion.getQuestion(), m_currentQuestion.getAnswer(), 
							m_questionButtons[i].getString());
						
					}
				}
			}
		}
	}
}

void Game::forceQuit()
{
	m_stillPlaying = false;
	m_retry = false;
}

void Game::changeQuestion()
{
	m_currentQuestion = m_quiz.popQuestion();
}

void Game::drawButtons()
{
	for (int i = 0; i < m_questionButtons.size(); i++)
	{
		m_window->draw(m_questionButtons[i].getShape());
	}
}

void Game::drawButtonText()
{
	for (int i = 0; i < m_questionButtons.size(); i++)
	{
		m_window->draw(m_questionButtons[i].getText());
	}
}

void Game::drawHeader()
{
	drawLogo();
}

void Game::drawLogo()
{
	m_window->draw(m_logo);
}

void Game::drawCurrentQuestionNumber()
{
	m_window->draw(m_currentQuestionNumberText);
}

void Game::nextQuestion(bool p_correct, std::string p_question, std::string p_answer, std::string p_guess)
{
	if(m_currentQuestionCounter < m_totalQuestionsCounter) //1 off
	{
		m_answers.push_back(AnswerCombo(p_correct, p_question, p_answer, p_guess));
		m_currentQuestion = m_quiz.popQuestion();
		m_currentQuestionCounter++;
		updateButtons();
		updateQuestionNumberText();
	}
	else
	{
		m_stillPlaying = false;
	}
}

void Game::updateButtons()
{
	m_questionButtons[0].setText(m_currentQuestion.getQuestion());
	m_questionButtons[1].setText(m_currentQuestion.getAnswer());
	m_questionButtons[2].setText(m_currentQuestion.getWrongAnswers()[0]);
	m_questionButtons[3].setText(m_currentQuestion.getWrongAnswers()[1]);
	m_questionButtons[4].setText(m_currentQuestion.getWrongAnswers()[2]);
}

void Game::updateQuestionNumberText()
{
	m_currentQuestionNumberText.setString(Util::toString(m_currentQuestionCounter) + " / " + Util::toString(m_totalQuestionsCounter));
}