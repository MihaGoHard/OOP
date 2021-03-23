#pragma once

#include <iostream>
#include <fstream>
#include <iostream>
#include "Types.h"

bool OpenInStream(ifstream& input, Args& args);
bool OpenOutStream(ofstream& output, Args& args);
bool GetDictionaryFromFile(Dictionary& dictionary, ifstream& input);
void PutDictionaryToFile(Dictionary dictionary, ostream& output);
bool CheckFileSaveDictioanry(bool noFile, const Dictionary& dictionary, Args& args, char* argv[]);