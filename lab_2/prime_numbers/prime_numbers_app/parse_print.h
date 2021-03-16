#pragma once
#include <iostream>
#include <optional>
#include <set>

using namespace std;

struct Args
{
	unsigned int inputNum;
};

std::optional<Args> ParseArgs(int argc, char* argv[]);
uint32_t ParseBytes(const std::string& inputStr);
void PrintSet(set<int>& numsSet);
