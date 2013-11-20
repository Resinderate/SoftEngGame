#ifndef UTIL_H
#define UTIL_H

#include <vector>
#include "dirent.h"

class Util
{
public:
	static void getFilenamesInDir(std::vector<std::string> &out, const std::string &directory);
};
#endif