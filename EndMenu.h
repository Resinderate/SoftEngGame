#ifndef ENDMENU_H
#define ENDMENU_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "DLinkedList.h"
#include "Button.h"
#include "QuestionButton.h"

class Menu
{
private:
	Button				m_retryButton;
	Button				m_quitButton;
	std::vector<sf::CircleShape> m_questionBalls;
	sf::RenderWindow	*m_window;
	sf::Sprite			m_logo;
	std::vector<QuestionButton> m_answerComboButtons;

	int				handleEvents();
	void			render();

public:
	Menu(sf::RenderWindow &p_window, Button &p_retryButton, Button &p_quitButton, 
		const sf::Texture &p_logoTexture, const sf::Vector2f &p_logoPos);
	bool run();
};
#endif