#include "CHttpUrl.h"
#include "CUrlParsingError.h"

using namespace std;

CHttpUrl::CHttpUrl(string const& url)
{
	regex regExp("^(http|https)://([^/ :]+):?([^/ ]*)(/?[^ #?]*)\\x3f?([^ #]*)#?([^ ]*)$");
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
		throw CUrlParsingError("Invalid URL. use  protocol://domain:port/document or protocol://domain/document\n");
	}
}

CHttpUrl::CHttpUrl(string const& domain, string const& document, Protocol protocol)
	: m_protocol(protocol)
{
	if (domain.empty() || document.empty())
	{
		throw CUrlParsingError("Invalid domain or document. Use [domain] [document]|[/document] [protocol]\n");
	}

	m_domain = domain;
	m_document = NormalizeDocumentStr(document);

	string portEmptyStr = "";
	m_port = GetPortFromStr(portEmptyStr);
}

CHttpUrl::CHttpUrl(string const& domain, string const& document, Protocol protocol, unsigned short port)
	: m_protocol(protocol)
	, m_port(port)
{
	if (domain.empty() || document.empty())
	{
		throw CUrlParsingError("Invalid domain or document. Use [domain] [document]|[/document] [protocol]\n");
	};

	m_domain = domain;
	m_document = NormalizeDocumentStr(document);
}

string CHttpUrl::GetURL() const
{
	string port = ':' + to_string(m_port);
	if ((m_port == 80 && m_protocol == Protocol::HTTP) || (m_port == 443 && m_protocol == Protocol::HTTPS))
	{
		port = "";
	}
	return GetProtocolInStr() + "://" + m_domain + port + m_document;
}

string CHttpUrl::GetDomain() const
{
	return m_domain;
}

string CHttpUrl::GetDocument() const
{
	return m_document;
}

Protocol CHttpUrl::GetProtocol() const
{
	return m_protocol;
}

unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}

unsigned short CHttpUrl::GetPortFromStr(string& inputStr)
{
	if (inputStr.empty())
	{
		switch (m_protocol)
		{
		case Protocol::HTTP:
			return 80;
		case Protocol::HTTPS:
			return 443;
		}
	}

	return ConvertStrToPort(inputStr);
}

string CHttpUrl::NormalizeDocumentStr(string const& inputStr)
{
	if (inputStr[0] != '/')
	{
		return '/' + inputStr;
	}
	return inputStr;
}

string CHttpUrl::GetProtocolInStr() const
{
	if (m_protocol == Protocol::HTTP)
	{
		return "http";
	}
	return "https";
}

Protocol ConvertStrToProtocol(string inputStr)
{
	transform(inputStr.begin(), inputStr.end(), inputStr.begin(), ::tolower);

	if (inputStr == "http")
	{
		return Protocol::HTTP;
	}
	else if (inputStr == "https")
	{
		return Protocol::HTTPS;
	}
	else
	{
		throw CUrlParsingError("Invalid protocol. Use http|https \n");
	}
}

unsigned short ConvertStrToPort(const string& inputStr)
{
	int port = stoi(inputStr);
	if (port < 1 || port > USHRT_MAX)
	{
		throw CUrlParsingError("Invalid port number. Use port in range [1 - 65535]\n");
	}
	return (unsigned short)port;
}





















