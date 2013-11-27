#include "QuizMenu.h"

QuizMenu::QuizMenu(sf::RenderWindow &p_window, const Button &p_continueButton, const sf::Text &p_selectQuiz, 
		const sf::Text &p_selectTime, std::vector<QuestionButton> &p_quizButtons, std::vector<QuestionButton>&p_timeButtons,
		const sf::Texture &p_logoTexture, const sf::Vector2f &p_logoPos) : 
		m_window(&p_window),
		m_continueButton(p_continueButton),
		m_selectQuiz(p_selectQuiz),
		m_selectTime(p_selectTime),
		m_quizButtons(p_quizButtons),
		m_timeButtons(p_timeButtons),
		m_currentlySelectedQuizFile("quiz1.txt"),
		m_currentQuestionTimer(15),
		m_logo(p_logoTexture)
{
	m_logo.setPosition(p_logoPos);
	
}

int QuizMenu::run(std::string &p_filename)
{
	int choice = 0;

	while(m_window->isOpen())
	{
		choice = handleEvents();
		if(choice == 0)
		{
			if(m_window->isOpen())
			{
				render();
			}
		}
		else if (choice == 1)
		{
			p_filename = m_currentlySelectedQuizFile;
			return m_currentQuestionTimer;
		}
	}
}

int QuizMenu::handleEvents()
{
	sf::Event event;
	while (m_window->pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
		{
			m_window->close();
			m_currentQuestionTimer = -1;
		}

		if(event.type == sf::Event::MouseMoved)
		{
			if(m_continueButton.getSprite().getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
				m_continueButton.startHover();
			else
				m_continueButton.endHover();
		}

		if(event.type == sf::Event::MouseButtonReleased)
		{
			if(event.mouseButton.button == sf::Mouse::Left)
			{
				//check for changing quiz files selected.
				for(int i = 0; i < m_quizButtons.size(); i++)
				{
					if(m_quizButtons[i].getShape().getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
					{
						m_currentlySelectedQuizFile = m_quizButtons[i].getString();
						for(int j = 0; j < m_quizButtons.size(); j++)
						{
							m_quizButtons[j].endHover();
						}
						m_quizButtons[i].startHover();
					}
				}
				//check for changing timer length selection
				for(int i = 0; i < m_timeButtons.size(); i++)
				{
					if(m_timeButtons[i].getShape().getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
					{
						for(int j = 0; j < m_timeButtons.size(); j++)
						{
							m_timeButtons[j].endHover();
						}
						m_timeButtons[i].startHover();
						m_currentQuestionTimer = atoi(m_timeButtons[i].getString().c_str());
					}
				}
				//Play
				if(m_continueButton.getSprite().getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
				{
					return 1;
				}
			}
		}
		return 0;
	}
}

void QuizMenu::render()
{
	m_window->clear(sf::Color::White);
	m_window->draw(m_logo);
	m_window->draw(m_selectQuiz);
	m_window->draw(m_selectTime);
	m_window->draw(m_continueButton.getSprite());
	for(int i = 0; i < m_quizButtons.size(); i++)
	{
		m_window->draw(m_quizButtons[i].getShape());
		m_window->draw(m_quizButtons[i].getText());
	}
	for(int i = 0; i < m_timeButtons.size(); i++)
	{
		m_window->draw(m_timeButtons[i].getShape());
		m_window->draw(m_timeButtons[i].getText());
	}
	m_window->display();
}