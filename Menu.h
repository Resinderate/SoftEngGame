/*
	Menu.h
	Written by Ronan Murphy circa Aug-Sep 2013.
*/
#ifndef MENU_H
#define MENU_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Button.h"

class Menu
{
private:
	Button				m_exitButton;
	Button				m_playButton;
	sf::RectangleShape	m_backgroundDim;
	sf::RenderWindow	*m_window;
	sf::Sprite			m_logo;

	int				handleEvents();
	void			render();

public:
	Menu(sf::RenderWindow &p_window, Button &p_playButton, Button &p_exitButton, int p_minBalls, int p_maxBalls, 
		int p_ballRadius, int p_backgroundDimAlpha, const sf::Texture &p_logoTexture, const sf::Vector2f &p_logoPos);
	bool run();
};
#endif