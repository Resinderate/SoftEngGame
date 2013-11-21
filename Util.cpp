#include "Util.h"


void Util::getFilenamesInDir(std::vector<std::string> &out, const std::string &directory)
{
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir (directory.c_str())) != NULL) 
	{
		/* add all files to vector */
		while ((ent = readdir (dir)) != NULL) 
		{
			out.push_back(ent->d_name);
		}
		closedir (dir);
	} 
}

Quiz Util::getQuiz(std::string p_filename, int p_secsToAns)
{
	int count;
	std::vector<Question> questions;

	char trash[256];
	char value[256];

	std::string question;
	std::string answer;
	std::string guess1;
	std::string guess2;
	std::string guess3;

	std::ifstream myfile(p_filename);

	if(myfile.is_open())
	{
		myfile.getline(trash, 256);
		myfile.getline(value, 256);
		count = atoi(value);

		for (int i = 0; i < count; i++)
		{
			myfile.getline(trash, 256);
			myfile.getline(value, 256);
			question = value;
			myfile.getline(value, 256);
			answer = value;
			myfile.getline(value, 256);
			guess1 = value;
			myfile.getline(value, 256);
			guess2 = value;
			myfile.getline(value, 256);
			guess3 = value;

			questions.push_back(Question(question, answer, guess1, guess2, guess3));
		}
	}
	myfile.close();
	return Quiz(questions, p_secsToAns);
}

std::string Util::toString(int p_int)
{
	std::ostringstream  os;
	os << p_int;
	return os.str();
}
