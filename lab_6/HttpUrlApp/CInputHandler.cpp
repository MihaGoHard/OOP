#include "CInputHandler.h"

using namespace std;

CInputHandler::CInputHandler(istream& input, ostream& output)
	: m_input(input)
	, m_output(output)
{
}

bool CInputHandler::command()
{
	int maxArgsNum = 4;
	string line;
	getline(m_input, line);
	vector<string> inputStrVector = GetInputStrVector(line);
	try
	{
		if (inputStrVector.size() == 1)
		{
			string fullURL = inputStrVector[0];
			CHttpUrl httpUrl(fullURL);
			m_output << httpUrl.GetURL() << "\n";
		}
		else if (inputStrVector.size() == 3)
		{
			string domain = inputStrVector[0];
			string document = inputStrVector[1];
			Protocol protocol = ConvertStrToProtocol(inputStrVector[2]);
			CHttpUrl httpUrl(domain, document, protocol);
			m_output << httpUrl.GetURL() << "\n";
		}
		else if (inputStrVector.size() == 4)
		{
			string domain = inputStrVector[0];
			string document = inputStrVector[1];
			Protocol protocol = ConvertStrToProtocol(inputStrVector[2]);
			unsigned short port = ConvertStrToPort(inputStrVector[3]);
			CHttpUrl httpUrl(domain, document, protocol, port);
			m_output << httpUrl.GetURL() << "\n";
		}
		else
		{
			string fullUrl = "	https://www.google.com:100/document\n";
			string domDocProto = "	[domain]  [document]|[/document]  [protocol]\n";
			string domDocProtoPort = "	[domain]  [document]|[/document]  [protocol]  [port]\n";
			throw CUrlParsingError("Invalid input. Use one of variants:\n" + fullUrl + domDocProto + domDocProtoPort);
		}
	}
	catch (invalid_argument const& exception)
	{
		m_output << exception.what();
	}

	return true;
}

vector<string> CInputHandler::GetInputStrVector(const string& line) const
{
	istringstream strm(line);
	istream_iterator<string> strmBegin(strm);
	istream_iterator<string> strmEnd;
	vector<string> inputStrVector = {};

	copy(strmBegin, strmEnd, inserter(inputStrVector, inputStrVector.begin()));
	return inputStrVector;
}
