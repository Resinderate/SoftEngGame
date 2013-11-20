#ifndef QUIZ_H
#define QUIZ_H

#include <vector>
#include "Question.h"
#include "AnswerCombo.h"

class Quiz
{
private:
	std::vector<Question> m_questions;
	int m_secondsToAnswer;
	std::vector<AnswerCombo> m_answers;
public:
	Quiz(std::vector<Question> p_questions, int p_secondsToAnswer);
	Question popQuestion();
	void pushAnswer(AnswerCombo p_answerCombo);
};
#endif