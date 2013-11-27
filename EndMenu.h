#ifndef ENDMENU_H
#define ENDMENU_H

//#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Button.h"
#include "QuestionButton.h"
#include "AnswerCombo.h"
#include <string>
#include "Util.h"

class EndMenu
{
private:
	Button				m_retryButton;
	Button				m_quitButton;
	std::vector<sf::CircleShape> m_questionBalls;
	sf::RenderWindow	*m_window;
	sf::Sprite			m_logo;
	std::vector<QuestionButton> m_answerComboButtons;
	std::vector<AnswerCombo> m_answers;
	bool m_retry;
	bool m_quit;
	AnswerCombo m_currentAnswerCombo;

	void			handleEvents();
	void			update();
	void			render();
	void			updateAnswerComboButtons();

public:
	EndMenu(sf::RenderWindow* p_window, Button p_retryButton, Button p_quitButton, 
		const sf::Texture &p_logoTexture, const sf::Vector2f &p_logoPos, std::vector<AnswerCombo>& p_answers,
		std::vector<QuestionButton>& p_answerComboButtons);
	bool run();
};
#endif
