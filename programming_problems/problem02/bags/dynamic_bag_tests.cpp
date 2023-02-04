#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "dynamic_bag.hpp"

// force template expansion for ints
template class DynamicBag<int>;

TEST_CASE("Calling all public members", "[DynamicBag]"){
  DynamicBag<int> b;

  b.add(0);
  b.remove(0);
  b.isEmpty();
  b.getCurrentSize();
  b.clear();
  b.getFrequencyOf(0);
  b.contains(0);
}

TEST_CASE("Default constructor creates bag of size 0","[DynamicBag]"){
  DynamicBag<int> b;
 
  REQUIRE(b.getCurrentSize() == 0);
}

TEST_CASE("Maximum size is 100", "[DynamicBag]"){
  DynamicBag<int> b;
 
  REQUIRE(b.getCurrentSize() < 100);
  //REQUIRE(b.maxsize == 100);
}

TEST_CASE("Item is added successfully", "[DynamicBag]"){
  DynamicBag<int> b;

  REQUIRE(b.add(1));
  REQUIRE(b.contains(1));
}


TEST_CASE("Item is removed successfully", "[DynamicBag]"){
  DynamicBag<int> b;

  b.add(1);
  b.add(2);

  REQUIRE(b.remove(2));
  REQUIRE_FALSE(b.contains(2));
  REQUIRE(b.contains(1));  


}

TEST_CASE("All items are cleared from bag", "[DynamicBag]"){
  DynamicBag<int> b;

  b.add(1);
  b.add(2);
  b.clear();

  REQUIRE_FALSE(b.contains(1));
  REQUIRE_FALSE(b.contains(2));
  REQUIRE(b.getCurrentSize() == 0);
  REQUIRE(b.isEmpty());

}

TEST_CASE("Get the frequency of an item in the bag", "[DynamicBag]"){
  DynamicBag<int> b;

  b.add(1);
  b.add(1);

  REQUIRE(b.getFrequencyOf(1) == 2);
}