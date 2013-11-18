#include "Game.h"

Game::Game(sf::RenderWindow* p_window) :
	m_window(p_window),
	m_stillPlaying(true),
	m_retry(true)
{

}

bool Game::run()
{
	while(m_stillPlaying && m_window->isOpen())
	{
		handleEvents();

		update();
		render();
	}
	return m_retry;
}

void Game::render()
{
	m_window->clear(sf::Color::Black);

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
			
        }
}

void Game::forceQuit()
{
	m_stillPlaying = false;
	m_retry = false;
}