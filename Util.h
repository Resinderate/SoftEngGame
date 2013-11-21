#ifndef UTIL_H
#define UTIL_H

#include <vector>
#include "dirent.h"
#include "Quiz.h"
#include "Question.h"
#include <fstream>
#include <iostream>
#include <sstream>

class Util
{
public:
	static void getFilenamesInDir(std::vector<std::string> &out, const std::string &directory);
	static Quiz getQuiz(std::string p_filename, int p_secsToAns);
	static std::string toString(int p_int);
	static std::string format(std::string p_input, int p_widthInChars);
};
#endif