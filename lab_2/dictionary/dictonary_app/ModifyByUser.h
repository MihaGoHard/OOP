#pragma once

#include <iostream>
#include "Types.h"

void DialogWithUser(Dictionary& dictionary, DictionaryElem& dictionaryElem, istream& inStream, ostream& outStream, bool& modified);
bool ModifyPrintDictionary(Dictionary& dictionary, istream& inStream, ostream& outStream);
void GetUserAnswerChangeDictionary(Dictionary& dictionary, DictionaryElem& dictionaryElem, istream& inStream, ostream& outStream, bool& modified);