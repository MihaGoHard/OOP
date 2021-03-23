#include "EncodeHtmlPrintResult.h"
#include <array>
#include <vector>

using namespace std;

namespace
{
	const vector<pair<char, string>> encodeMap{ { '<', "&lt;"s }, { '>', "&gt;"s }, { '\'', "&apos;"s }, { '"', "&quot;"s }, { '&', "&amp;"s } };
}

string EncodeHtml(const string& html)
{
	string encodeStr;

	for (auto& ch : html)
	{
		auto specIter = find_if(encodeMap.begin(), encodeMap.end(), [&](auto& pairChStr) {
			return pairChStr.first == ch;
		});

		if (specIter != encodeMap.end())
		{
			encodeStr += specIter->second;
		}
		else
		{
			encodeStr += ch;
		}
	}

	return encodeStr;
}

void GetStringPrintEncodeHtml(istream& input, ostream& output)
{
	string line;
	while (getline(input, line))
	{
		output << EncodeHtml(line);

		if (!input.eof())
		{
			output << "\n";
		}
	}
}
