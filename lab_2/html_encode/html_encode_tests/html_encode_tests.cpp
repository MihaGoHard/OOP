#define CATCH_CONFIG_MAIN
#include "HTML_Decode/HTML_Decode_App/EncodeHtmlPrintResult.cpp"
#include <catch2/catch.hpp>

TEST_CASE("Encode html from line")
{
	SECTION("Doesn't change the empty string")
	{
		string str = "";
		CHECK(EncodeHtml(str) == str);
	}

	SECTION("Doesn't change the string without specials")
	{
		string str = "Cat says Meow. What does the fox says?";
		CHECK(EncodeHtml(str) == str);
	}

	SECTION("Change the string with specials")
	{
		string inStr = "Cat <says> \"\Meow\"\. M&M's";
		string outStr = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";
		CHECK(EncodeHtml(inStr) == outStr);
	}
}

TEST_CASE("Encode html from input")
{
	SECTION("Encode one line")
	{
		istringstream input("Cat <says> \"\Meow\"\. M&M's");
		stringstream output;
		GetStringPrintEncodeHtml(input, output);
		CHECK(output.str() == "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s");
		CHECK(input.eof());
	}

	SECTION("Encode some lines")
	{
		istringstream input("Cat <says> \"\Meow\"\. M&M's \n Dog <says> \"\Wof\"\. M&M's");
		stringstream output;
		GetStringPrintEncodeHtml(input, output);
		CHECK(output.str() == "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s \n Dog &lt;says&gt; &quot;Wof&quot;. M&amp;M&apos;s");
		CHECK(input.eof());
	}
}
