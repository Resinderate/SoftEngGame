#ifndef ANSWERCOMBO_H
#define ANSWERCOMBO_H
#include <string>

class AnswerCombo
{
private:
	bool m_correct;
	std::string m_question;
	std::string m_guess;
	std::string m_answer;
public:
	AnswerCombo(bool p_correct, std::string p_question, std::string p_answer, std::string p_guess);
	AnswerCombo();
	bool isCorrect();
	std::string getQuestion();
	std::string getGuess();
	std::string getAnswer();
};
#endif