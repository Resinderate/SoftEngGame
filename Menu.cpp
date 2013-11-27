/*
	Menu.cpp
	Written by Ronan Murphy circa Aug-Sep 2013.
*/
#include "Menu.h"

/*
	Name:	Constructor
	Desc:	Constructor for Menu
	Args:	p_window,			the window to be used for the menu
			p_playButton,		the button to be used for playing
			p_exitButton,		the button to be used for quiting
			p_minBalls,			the min amount of balls used for the background graphic
			p_maxBalls,			the max amount of balls used for the background graphic
			p_ballRadius,		the radius of the balls in the background
			p_backgoundDimAlpha,the alpha number to be used on the overlay in the background
			p_logoTexture,		the texture of the logo to be used in the middle of the screen
			p_logoPos,			the position of the logo on the screen
	Rtrn:	None
*/
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


/*
	Name:	run
	Desc:	main function used to run the menu, everything is managed from here until the menu is exited
	Args:	None
	Rtrn:	bool,	true if the game should be now played, or false is the user wishes to exit
*/
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

/*
	Name:	handleEvents
	Desc:	handles all the event for the window and the buttons on the screen.
	Args:	None
	Rtrn:	int,	1 if the user wants to play, 2 if the user wants to quit, and 0 if they havent decided yet (no choice)
*/
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

/*
	Name:	render
	Desc:	renders all of the information of the menu to the window
	Args:	None
	Rtrn:	None
*/
void Menu::render()
{
	m_window->clear(sf::Color::White);
	
	//m_window->draw(m_backgroundDim);
	m_window->draw(m_playButton.getSprite());
	m_window->draw(m_exitButton.getSprite());
	m_window->draw(m_logo);
	m_window->display();
}
