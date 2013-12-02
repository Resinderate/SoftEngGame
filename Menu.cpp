/*
	Menu.cpp
	Written by Ronan Murphy circa Aug-Sep 2013.
*/
#include "Menu.h"

Menu::Menu(sf::RenderWindow &p_window, Button &p_playButton, Button &p_exitButton, int p_minBalls, int p_maxBalls,
		   int p_ballRadius, int p_backgroundDimAlpha, const sf::Texture &p_logoTexture, const sf::Vector2f &p_logoPos) :
	m_window(&p_window),
	m_playButton(p_playButton),
	m_exitButton(p_exitButton),
	
	m_logo(p_logoTexture)
{
	

	m_backgroundDim.setSize(sf::Vector2f(m_window->getSize().x, m_window->getSize().y));
	m_backgroundDim.setFillColor(sf::Color(0, 0, 0, p_backgroundDimAlpha));
	m_backgroundDim.setPosition(0, 0);

	m_logo.setPosition(p_logoPos);
}

bool Menu::run()
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
		else if(choice == 1)
			return true;
		else //choice == 2
			return false;
	}
}

int Menu::handleEvents()
{
	sf::Event event;
	while (m_window->pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
			m_window->close();

		if(event.type == sf::Event::MouseMoved)
		{
			//Buttons
			if(m_playButton.getSprite().getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
				m_playButton.startHover();
			else
				m_playButton.endHover();

			if(m_exitButton.getSprite().getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
				m_exitButton.startHover();
			else
				m_exitButton.endHover();
		}

		if(event.type == sf::Event::MouseButtonReleased)
		{
			if(event.mouseButton.button == sf::Mouse::Left)
			{
				//Play
				if(m_playButton.getSprite().getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
				{
					return 1;
				}
				//Quit
				if(m_exitButton.getSprite().getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
				{
					return 2;
				}
			}
		}

		return 0;
	}


}

void Menu::render()
{
	m_window->clear(sf::Color::White);
	
	//m_window->draw(m_backgroundDim);
	m_window->draw(m_playButton.getSprite());
	m_window->draw(m_exitButton.getSprite());
	m_window->draw(m_logo);
	m_window->display();
}
