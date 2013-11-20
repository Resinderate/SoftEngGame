#include "Question.h"

Question::Question(std::string p_question, std::string p_answer, std::string p_wrongAns1, std::string p_wrongAns2, std::string p_wrongAns3) :
	m_question(p_question),
	m_answer(p_answer),
	m_wrongAns1(p_wrongAns1),
	m_wrongAns2(p_wrongAns2),
	m_wrongAns3(p_wrongAns3)
{
}

Question::Question() :
	m_question(""),
	m_answer(""),
	m_wrongAns1(""),
	m_wrongAns2(""),
	m_wrongAns3("")
{
}

std::string Question::getAnswer()
{
	return m_answer;
}
std::string Question::getQuestion()
{
	return m_question;
}
std::vector<std::string> Question::getWrongAnswers()
{
	std::vector<std::string> wrongAnswers;
	wrongAnswers.push_back(m_wrongAns1);
	wrongAnswers.push_back(m_wrongAns2);
	wrongAnswers.push_back(m_wrongAns3);
	return wrongAnswers;
}