#ifndef BITSET_HPP
#define BITSET_HPP
#include <stdint.h>
#include <stdlib.h>
#include <string>

class Bitset{
public:

  //** Default constructor
  //purpose: Set bitset to size N=8, all initialized to 0
  //@param No parameter
  //*/
  Bitset();

  //** Constructor
  //purpose: Set bitset to int N=size, all initialized to 0
  //@param: int Size for bitset
  //@throw: If N<=0, bitset is invalid
  //*/
  Bitset(intmax_t size);

  //** Constructor
  //purpose: Set bitset to size N=string length, all initialized to 0
  //@param: int Size for bitset
  //@throw: If string contains character other than 0 or 1, bitset is invalid
  //*/
  Bitset(const std::string & value);

  //** Destructor
  //purpose: Deallocated to prevent memory leakage
  //@post Bitset will be deallocated
  //*/
  ~Bitset();

  //** 
  //=======================================
  Bitset(const Bitset & ) = delete;
  Bitset & operator=(const Bitset &) = delete;

  //** Accessor Function
  //@param None
  //@return Size as int
  //@throw if string, must turn into an int
  //*/
  intmax_t size() const;

  //** Accessor Function
  //@param None
  //@return Boolean isValid
  //*/
  bool good() const;

  //** Mutator Function
  //purpose: Set nth bit to 1
  //@param int Index of the bit to set
  //@post if nth bit was 0, now it's 1
  //*/
  void set(intmax_t index);

  //** Mutator Function
  //purpose: Set nth bit to 0
  //@param int Index of the bit to set
  //@post if nth bit was 1, now it's 0
  //*/
  void reset(intmax_t index);

  //** Mutator Function
  //purpose: Toggle nth bit
  //@param: int Index of the bit to set
  //@post: if nth bit was 0, now it's 1
  //@post: if nth bit was 1, now it's 0
  //*/
  void toggle(intmax_t index);

  //** Accessor Function
  //purpose: Check if nth bit is a 1 or 0
  //@param: Index of bit
  //@return: Boolean to show whether the bit is 1 or 0
  //*/
  bool test(intmax_t index);

  //** Accessor Function
  //purpose: turns the bitset of ints into a string of characters 0 and 1
  //@param: None
  //@return: bitset as a string
  //*/
  std::string asString() const;

private:

  //true if valid, false if not valid
  unsigned int bitsetSize;
  //Dynamically allocated array of ints
  //Must be deallocated
  int* bitset = new int[bitsetSize];
  //Starts the array as valid, becomes false if it breaks a rule
  bool isValid;
};

#endif
