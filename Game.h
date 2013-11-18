#ifndef GAME_H
#define GAME_H


#include "SFML\Graphics.hpp"

class Game
{

private:
	sf::RenderWindow* m_window;
	bool m_stillPlaying;
	bool m_retry;

	void update();
	void render();
	void handleEvents();
	void forceQuit();
public:
	Game(sf::RenderWindow* p_window);
	bool run();
};
#endif