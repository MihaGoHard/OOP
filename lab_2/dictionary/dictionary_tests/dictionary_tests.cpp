#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

#include "../dictonary_app/Types.h"
#include "../dictonary_app/DataFiles.h"
#include "../dictonary_app/ModifyByUser.h"
#include "../dictonary_app/Parsing.h"

using namespace std;

TEST_CASE("Writing to dictionary")
{

	SECTION("Check add translation to dictionary")
	{
		bool modified = false;
		DictionaryElem dictionaryElem;
		dictionaryElem.first = "cat";
		Dictionary dictionary;
		istringstream input("кот\n");
		ostringstream output;
		GetUserAnswerChangeDictionary(dictionary, dictionaryElem, input, output, modified);
		CHECK(dictionary["cat"] == "кот");

	}

	SECTION("Check not add translation to dictionary")
	{
		bool modified = false;
		DictionaryElem dictionaryElem;
		dictionaryElem.first = "cat";
		Dictionary dictionary;
		istringstream input("\n");
		ostringstream output;
		GetUserAnswerChangeDictionary(dictionary, dictionaryElem, input, output, modified);
		CHECK(dictionary["cat"] == "");

	}
}