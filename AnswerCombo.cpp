#include "AnswerCombo.h"

AnswerCombo::AnswerCombo(bool p_correct, std::string p_question, std::string p_answer, std::string p_guess) :
	m_correct(p_correct),
	m_answer(p_answer),
	m_guess(p_guess),
	m_question(p_question)
{
	
}

AnswerCombo::AnswerCombo() :
	m_correct(true),
	m_answer(""),
	m_guess(""),
	m_question("")
{
}

bool AnswerCombo::isCorrect()
{
	return m_correct;
}
std::string AnswerCombo::getGuess()
{
	return m_guess;
}
std::string AnswerCombo::getAnswer()
{
	return m_answer;
}