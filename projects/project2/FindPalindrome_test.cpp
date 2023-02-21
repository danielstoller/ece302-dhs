#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"

// There should be at least one test per FindPalindrome method



TEST_CASE("test recursion vector of strings with repeating word", "[FindPalindrome]"){
	FindPalindrome b;

	vector<string> vect = {"Was", "it", "a", "car", "or", "a", "cat", "saw", "I"};
	REQUIRE(!b.add(vect));
}

TEST_CASE("test recursion vector of strings", "[FindPalindrome]"){
	FindPalindrome b;

	vector<string> vect = {"Mr", "Owl", "ate", "my", "metal"};
	REQUIRE(b.add(vect));
	REQUIRE(b.number() == 0);
	REQUIRE(b.add("worm"));
	REQUIRE(b.number() == 1);
}


TEST_CASE( "Test adding a non-allowable word", "[FindPalindrome]" )
{
	FindPalindrome b;
	REQUIRE(!b.add("kayak1"));
}

TEST_CASE("test recursion", "[FindPalindrome]"){
	FindPalindrome b;

	REQUIRE(b.add("a"));
	REQUIRE(b.add("AA"));
	REQUIRE(b.add("AaA"));
	REQUIRE(b.number() == 6);
}

TEST_CASE("test recursion vector of strings with error", "[FindPalindrome]"){
	FindPalindrome b;

	vector<string> vect = {"Was", "it", "a", "car", "or", "a", "cat", "saw?", "I"};
	REQUIRE(!b.add(vect));
}