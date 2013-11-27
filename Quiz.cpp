#include "Quiz.h"

Quiz::Quiz(std::vector<Question> p_questions, int p_secondsToAnswer) :
	m_questions(p_questions),
	m_secondsToAnswer(p_secondsToAnswer)
{
	shuffleQuestions();
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

int Quiz::questionCountRemaining()
{
	return m_questions.size();
}

int Quiz::secondsToAnswer()
{
	return m_secondsToAnswer;
}

void Quiz::shuffleQuestions()
{
	std::random_shuffle(m_questions.begin(), m_questions.end());
}