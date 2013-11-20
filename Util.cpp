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
