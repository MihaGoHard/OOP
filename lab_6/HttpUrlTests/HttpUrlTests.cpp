#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <iostream>
#include <sstream>

#include "../HttpUrlApp/CHttpUrl.h"
#include "../HttpUrlApp/CUrlParsingError.h"

using namespace std;

TEST_CASE("CHttpUrl")
{
	SECTION("URL")
	{
		SECTION("Valid url")
		{
			string url = "https://disk.yandex.ru:443/i/U61TCPZ4oz-LXw";
			CHttpUrl httpUrl(url);

			CHECK(httpUrl.GetDocument() == "/i/U61TCPZ4oz-LXw");
			CHECK(httpUrl.GetDomain() == "disk.yandex.ru");
			CHECK(httpUrl.GetPort() == 443);
			CHECK(httpUrl.GetProtocol() == Protocol::HTTPS);
			CHECK(httpUrl.GetURL() == "https://disk.yandex.ru/i/U61TCPZ4oz-LXw");

			string url2 = "http://www.google.com/webhp?gws_rd=ssl#q=cpp";
			CHttpUrl httpUrl2(url2);
			CHECK(httpUrl2.GetPort() == 80);
		}

		SECTION("Invalid url")
		{
			SECTION("Invalid protocol")
			{
				string url = "ht://www.google.com:443/webhp?gws_rd=ssl#q=cpp";
				CHECK_THROWS(CHttpUrl{ url });
			}

			SECTION("Invalid domain")
			{
				string url = "http:///webhp?gws_rd=ssl#q=cpp";
				CHECK_THROWS(CHttpUrl{ url });
			}

			SECTION("Invalid port")
			{
				string url = "www.google.com/webhp?gws_rd=ssl#q=cpp";
				CHECK_THROWS(CHttpUrl{ url });
			}

			SECTION("Invalid document")
			{
				string url = "www.google.com/webhp?gws_rd=ssl#q=cpp";
				CHECK_THROWS(CHttpUrl{ url });
			}
		}
	}

	SECTION("Domain, document, protocol")
	{
		SECTION("Valid (domain, document, protocol)")
		{
			CHttpUrl httpUrl("www.google.com", "webhp", Protocol::HTTPS);

			CHECK(httpUrl.GetDocument() == "/webhp");
			CHECK(httpUrl.GetDomain() == "www.google.com");
			CHECK(httpUrl.GetPort() == 443);
			CHECK(httpUrl.GetProtocol() == Protocol::HTTPS);
			CHECK(httpUrl.GetURL() == "https://www.google.com/webhp");
		}

		SECTION("Invalid domain (domain, document, protocol)")
		{
			CHECK_THROWS(CHttpUrl{ "", "webhp", Protocol::HTTPS });
		}

		SECTION("Invalid document (domain, document, protocol)")
		{
			CHECK_THROWS(CHttpUrl{ "www.google.com", "", Protocol::HTTPS });
		}

		SECTION("Invalid domain, document (domain, document, protocol)")
		{
			CHECK_THROWS(CHttpUrl{ "", "", Protocol::HTTP });
		}
	}
}
























