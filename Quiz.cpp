#include "Quiz.h"

Quiz::Quiz(std::vector<Question> p_questions, int p_secondsToAnswer) :
	m_questions(p_questions),
	m_secondsToAnswer(p_secondsToAnswer)
{

}
Question Quiz::popQuestion()
{
	Question q = m_questions.back();
	m_questions.pop_back();
	return q;
}
void Quiz::pushAnswer(AnswerCombo p_answerCombo)
{
	m_answers.push_back(p_answerCombo);
}