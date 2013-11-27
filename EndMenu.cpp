#include "EndMenu.h"


EndMenu::EndMenu(sf::RenderWindow* p_window, Button p_retryButton, Button p_quitButton, 
		const sf::Texture &p_logoTexture, const sf::Vector2f &p_logoPos, std::vector<AnswerCombo>& p_answers,
		std::vector<QuestionButton>& p_answerComboButtons) :
	m_answers(p_answers),
	m_logo(p_logoTexture),
	m_window(p_window),
	m_retryButton(p_retryButton),
	m_quitButton(p_quitButton),
	m_answerComboButtons(p_answerComboButtons),
	m_retry(false),
	m_quit(false),
	m_currentAnswerCombo(p_answers[0])
{
	m_logo.setPosition(p_logoPos);

	//radius based on how many. (assume 6?)
	int radius = 50;
	int pointCount = 30;
	for(int i  = 0; i < p_answers.size(); i++)
	{
		sf::CircleShape ball(radius, pointCount);
		if(m_answers[i].getAnswer() == m_answers[i].getGuess())
		{
			ball.setFillColor(sf::Color::Green);
		}
		else
		{
			ball.setFillColor(sf::Color::Red);
		}
		ball.setPosition(70 + (110 * i), 10);
		m_questionBalls.push_back(ball);
	}

	updateAnswerComboButtons();
}

bool EndMenu::run()
{
	while(!m_quit && m_window->isOpen())
	{
		handleEvents();

		update();
		render();
	}
	return m_retry;
}


void EndMenu::handleEvents()
{
	sf::Event event;
	while (m_window->pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
		{
			m_quit = true;
		}

		if(event.type == sf::Event::MouseMoved)
		{
			//Buttons
			if(m_retryButton.getSprite().getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
				m_retryButton.startHover();
			else
				m_retryButton.endHover();

			if(m_quitButton.getSprite().getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
				m_quitButton.startHover();
			else
				m_quitButton.endHover();
		}

		//clicks
		if(event.type == sf::Event::MouseButtonReleased)
		{
			if(event.mouseButton.button == sf::Mouse::Left)
			{
				//Play
				if(m_retryButton.getSprite().getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
				{
					m_retry = true;
					m_quit = true;
				}
				//Quit
				if(m_quitButton.getSprite().getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
				{
					m_quit = true;
				}

				for(int i = 0; i < m_questionBalls.size(); i++)
				{
					if(m_questionBalls[i].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
					{
						m_currentAnswerCombo = m_answers[i];
						updateAnswerComboButtons();
					}
				}
			}
		}
	}
	
}

void EndMenu::render()
{
	m_window->clear(sf::Color::White);
	//m_window->draw(m_logo);
	m_window->draw(m_retryButton.getSprite());
	m_window->draw(m_quitButton.getSprite());
	for(int i = 0; i < m_questionBalls.size(); i++)
		m_window->draw(m_questionBalls[i]);
	for(int i = 0; i < m_answerComboButtons.size(); i++)
	{
		m_window->draw(m_answerComboButtons[i].getShape());
		m_window->draw(m_answerComboButtons[i].getText());
	}
	m_window->display();
}

void EndMenu::updateAnswerComboButtons()
{
	//std::string question = m_currentAnswerCombo.getQuestion();
	m_answerComboButtons[0].setText(Util::format(m_currentAnswerCombo.getQuestion(), 42));
	m_answerComboButtons[1].setText(Util::format(m_currentAnswerCombo.getAnswer(), 42));
	m_answerComboButtons[2].setText(Util::format(m_currentAnswerCombo.getGuess(), 42));

	//update colors
	if(m_currentAnswerCombo.getGuess() == m_currentAnswerCombo.getAnswer())
	{
		m_answerComboButtons[2].getShape().setFillColor(sf::Color::Green);
	}
	else
		m_answerComboButtons[2].getShape().setFillColor(sf::Color::Red);
}


void EndMenu::update()
{

}