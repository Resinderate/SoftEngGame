/*
	Button.h
	Written by Ronan Murphy circa Aug-Sep 2013.
*/

#ifndef QUESTIONBUTTON_H
#define QUESTIONBUTTON_H

#include <SFML/Graphics.hpp>
#include "GameData.h"

class QuestionButton
{
private:
	sf::Text m_text;
	sf::RectangleShape m_button;
	sf::Color m_hoverColor;
	sf::Color m_nonHoverColor;
	
public:
	QuestionButton(const std::string &p_text, const sf::Font &p_font, int p_fontSize, const sf::Vector2f &p_buttonSize, const sf::Vector2f &p_buttonPos,
		const sf::Color &p_nonHoverColor, const sf::Color &p_hoverColor);
	void				endHover();
	sf::RectangleShape& getShape();
	void				startHover();
	void				setText(const std::string &p_text);
	std::string			getString();
	sf::Text			getText();
};
#endif
