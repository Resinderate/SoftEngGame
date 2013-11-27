#include "QuestionButton.h"

QuestionButton::QuestionButton(const std::string &p_text, const sf::Font &p_font, int p_fontSize, 
							   const sf::Vector2f &p_buttonSize, const sf::Vector2f &p_buttonPos, 
							   const sf::Color &p_nonHoverColor, const sf::Color &p_hoverColor) :
		m_text(p_text, p_font, p_fontSize),
			m_button(p_buttonSize),
			m_hoverColor(p_hoverColor),
			m_nonHoverColor(p_nonHoverColor)

{
	m_button.setPosition(p_buttonPos);
	m_text.setPosition(m_button.getPosition().x + GameData::questionTextInset, m_button.getPosition().y + GameData::questionTextInset);
	m_button.setFillColor(p_nonHoverColor);
}
void		QuestionButton::endHover()
{
	m_button.setFillColor(m_nonHoverColor);
}
sf::RectangleShape& QuestionButton::getShape()
{
	return m_button;
}
void QuestionButton::startHover()
{
	m_button.setFillColor(m_hoverColor);
}

void QuestionButton::setText(std::string p_text)
{
	m_text.setString(p_text);
}

std::string QuestionButton::getString()
{
	return m_text.getString();
}

sf::Text QuestionButton::getText()
{
	return m_text;
}