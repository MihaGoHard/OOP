#pragma once

#include <iostream>
#include <optional>
#include "Types.h"


DictionaryElem ParseLine(const string& line);
optional<Args> ParseArgs(int argc, char* argv[]);