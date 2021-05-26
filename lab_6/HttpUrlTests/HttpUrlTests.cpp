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
		string url = "https://www.google.com:443/webhp?gws_rd=ssl#q=cpp";
		CHttpUrl httpUrl(url);

		CHECK(httpUrl.GetDocument() == "/webhp");
		CHECK(httpUrl.GetDomain() == "www.google.com");
		CHECK(httpUrl.GetPort() == 443);
		CHECK(httpUrl.GetProtocol() == Protocol::HTTPS);
		CHECK(httpUrl.GetURL() == "https://www.google.com/webhp");

		string url2 = "http://www.google.com/webhp?gws_rd=ssl#q=cpp";
		CHECK(httpUrl.GetPort() == 80);
	}
}

