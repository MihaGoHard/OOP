#pragma once

#include <string>
#include <map>

using namespace std;

using DictionaryElem = pair<string, string>;
using Dictionary = map<string, string>;

struct Args
{
	std::string fileName;
};