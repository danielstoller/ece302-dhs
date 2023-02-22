#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"

// There should be at least one test per FindPalindrome method


TEST_CASE("Test add string", "[FindPalindrome]"){
FindPalindrome b;
REQUIRE(b.add("adsfkjl"));
REQUIRE_FALSE(b.add("a.a"));
REQUIRE_FALSE(b.add("t6u-"));

REQUIRE_FALSE(b.add("adsfkjl"));
}

TEST_CASE("Test add string vector", "[FindPalindrome]"){
FindPalindrome b;

std::vector<std::string> adder;
adder.push_back("aba");
adder.push_back("aba");            
REQUIRE_FALSE(b.add(adder));

}

TEST_CASE("test cutTest2", "[FindPalindrome]"){
FindPalindrome b;

std::vector<std::string> v1;
v1.push_back("ddd");
v1.push_back("aaa");

std::vector<std::string> v2;
v2.push_back("ada");
v2.push_back("dad");

REQUIRE(b.cutTest2(v1,v2));


v1.pop_back();
v2.pop_back();
REQUIRE_FALSE(b.cutTest2(v2,v1));

}

TEST_CASE("test cutTest1", "[FindPalindrome]"){
FindPalindrome b;
std::vector<std::string> v;

v.push_back("dada");
v.push_back("yuyu");

REQUIRE(b.cutTest1(v));

v.pop_back();
v.pop_back();
v.push_back("aboba");
REQUIRE(b.cutTest1(v));

v.push_back("bbbbba");
REQUIRE_FALSE(b.cutTest1(v));


}


TEST_CASE("test recursion vector of strings with multiple palindromes with errors", "[FindPalindrome]"){
	FindPalindrome b;

	REQUIRE(b.add("BA"));
	REQUIRE(b.number() == 0);
	vector<string> vect = {"AB", "BA", "AB"};
	REQUIRE(!b.add(vect));
	REQUIRE(b.number() == 0);
	REQUIRE(!b.add("BA"));
	REQUIRE(b.number() == 0);
	vect = {"!", "1"};
	REQUIRE(!b.add(vect));
	vect = {"BA"};
	REQUIRE(!b.add(vect));
	vect = {"a", "1"};
	REQUIRE(!b.add(vect));
	vect = {"D"};
	REQUIRE(b.add(vect));
	REQUIRE(b.number() == 0);
}

TEST_CASE("test recursion vector of strings with multiple palindromes", "[FindPalindrome]"){
	FindPalindrome b;

	REQUIRE(b.add("BA"));
	REQUIRE(b.number() == 0);
	vector<string> vect = {"AB"};
	REQUIRE(b.add(vect));
	REQUIRE(b.number() == 2);
	REQUIRE(b.add("AC"));
	REQUIRE(b.number() == 0);
	vect = {"CA"};
	REQUIRE(b.add(vect));
	REQUIRE(b.number() > 2);
	vect = {"D"};
	REQUIRE(b.add(vect));
	REQUIRE(b.number() > 2);
}

TEST_CASE("test recursion vector of strings with more to it", "[FindPalindrome]"){
	FindPalindrome b;

	REQUIRE(b.add("Mr"));
	REQUIRE(b.number() == 0);
	vector<string> vect = {"metal", "ate", "Owl", "my"};
	REQUIRE(b.add(vect));
	REQUIRE(b.number() == 0);
	REQUIRE(b.add("worm"));
	REQUIRE(b.number() == 1);
	REQUIRE(b.add("Mrs"));
	REQUIRE(b.number() == 0);
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
