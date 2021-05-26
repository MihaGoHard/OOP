#include "CHttpUrl.h"
#include <iostream>

using namespace std;

CHttpUrl::CHttpUrl(string const& url)
{
	regex regExp("(http|https)://([^/ :]+):?([^/ ]*)(/?[^ #?]*)\\x3f?([^ #]*)#?([^ ]*)");
	cmatch result;

	if (regex_match(url.c_str(), result, regExp))
	{
		string strProtocol = string(result[1]);
		string port = string(result[3]);
		m_protocol = ConvertStrToProtocol(strProtocol);
		m_port = GetPortFromStr(port);
		m_domain = string(result[2]);
		m_document = string(result[4]);
	}
	else
	{
		cout << "ex";
	}
}

string CHttpUrl::GetURL() const
{
	return GetProtocolInStr() + "://" + m_domain + m_document;
}

string CHttpUrl::GetDocument() const
{
	return m_document;
}

string CHttpUrl::GetDomain() const
{
	return m_domain;
}

unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}

Protocol CHttpUrl::GetProtocol() const
{
	return m_protocol;
}

Protocol CHttpUrl::ConvertStrToProtocol(string& inputStr) const
{
	switch (inputStr.length())
	{
	case 4:
		return Protocol::HTTP;
	case 5:
		return Protocol::HTTPS;
	default:
		cout << "ex";
	}
}

unsigned short CHttpUrl::GetPortFromStr(string& inputStr) const
{
	if (inputStr.empty()) 
	{
		switch (m_protocol) 
		{
		case Protocol::HTTP:
			return 80;
		case Protocol::HTTPS:
			return 443;
		default:
			cout << "ex";
		}
	}

	return ConvertStrToPort(inputStr);
}


unsigned short CHttpUrl::ConvertStrToPort(string& inputStr) const
{
	int port = stoul(inputStr);
	if (port < 1 || port > USHRT_MAX)
	{
		cout << "ex";
	}

	return (unsigned short)port;
}

string CHttpUrl::GetProtocolInStr() const
{
	if (m_protocol == Protocol::HTTP)
	{
		return "http";
	}
	return "https";
}























