#include "EncodeHtmlPrintResult.h"

vector<char> specials = { '<', '>', '\'', '"', '&' };
vector<string> entities = { "&lt;", "&gt;", "&apos;", "&quot;", "&amp;" };

string EncodeHtml(const string& html)
{
	string decodeStr;
	for (int i = 0; i < int(html.length()); ++i)
	{
		vector<char>::iterator specIter = find(specials.begin(), specials.end(), html[i]);
		if (specIter != specials.end())
		{
			decodeStr += entities[specIter - specials.begin()];
		}
		else
		{
			decodeStr += html[i];
		}
	}

	return decodeStr;
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
