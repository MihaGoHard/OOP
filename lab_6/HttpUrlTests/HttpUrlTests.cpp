#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <iostream>
#include <sstream>

#include "../HttpUrlApp/CHttpUrl.h"
using namespace std;

TEST_CASE("CHttpUrl")
{
	SECTION("CHttpUrl parse")
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
}
























