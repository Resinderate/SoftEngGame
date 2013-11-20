#ifndef QUESTION_H
#define QUESTION_H

#include <vector>
#include <string>

class Question
{
private:
	std::string m_question;
	std::string m_answer;
	std::string m_wrongAns1;
	std::string m_wrongAns2;
	std::string m_wrongAns3;

public:
	Question(std::string p_question, std::string p_answer, std::string p_wrongAns1, std::string p_wrongAns2, std::string p_wrongAns3);
	Question();
	std::string getAnswer();
	std::string getQuestion();
	std::vector<std::string> getWrongAnswers();
};
#endif