#pragma once
#include <regex>
#include <string>

using namespace std;

enum class Protocol
{
	HTTP,
	HTTPS
};

class CHttpUrl
{
public:
	
	CHttpUrl(string const& url);

	//CHttpUrl(string const& domain, string const& document, Protocol protocol = Protocol::HTTP);

	//CHttpUrl(string const& domain, string const& document, Protocol protocol, unsigned short port);

	string GetURL() const;

	string GetDomain() const;

	string GetDocument() const;

	Protocol GetProtocol() const;

	unsigned short GetPort() const;

private:

	string m_domain;
	string m_document;
	Protocol m_protocol;
	unsigned short m_port;
};

