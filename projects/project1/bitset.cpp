#include "bitset.hpp"
using namespace std;

Bitset::Bitset() : bitsetSize(8), isValid(true) {
   
    bitset = new int[8];
    //All bits are 0
    for(intmax_t i=0; i<bitsetSize; i++)
        reset(i);
}

Bitset::Bitset(intmax_t size) : isValid(true) {
    
    //If N<=0, invalid
    if(size<=0) isValid = false;
    bitsetSize = abs(size);
    
    bitset = new int[bitsetSize];

    
    
    //All bits are 0
    for(intmax_t i=0; i<bitsetSize; i++)
        reset(i);
}

Bitset::Bitset(const std::string & value) : bitsetSize(value.length()),  isValid(true) {
    
    bitset = new int[bitsetSize];

    //Loop to add each string bit into the bitset
    for(int i=0; i<value.length(); i++){
        
        //If character is a 0
        if(value.at(i) == '0')
            bitset[i] = 0;

        //If character is a 1
        else if(value.at(i) == '1')
            bitset[i] = 1;

        //If a character is neither
        else isValid = false; 
    }

}

Bitset::~Bitset() 
    {delete [] bitset;}



  //** Accessor Function
  //@param None
  //@return Size as int
  //@throw if string, must turn into an int
  intmax_t Bitset::size() const
  {return bitsetSize;}

  //** Accessor Function
  //@param None
  //@return Boolean isValid
  bool Bitset::good() const
  {return isValid;}

  //** Mutator Function
  //purpose: Set nth bit to 1
  //@param int Index of the bit to set
  //@post if nth bit was 0, now it's 1
  void Bitset::set(intmax_t index){
    if(0<=index && index<=(bitsetSize-1))
        bitset[index] = 1;
    else isValid = false;
  }

  //** Mutator Function
  //purpose: Set nth bit to 0
  //@param int Index of the bit to set
  //@post if nth bit was 1, now it's 0
  void Bitset::reset(intmax_t index){
    if(0<=index && index<=(bitsetSize-1))
        bitset[index] = 0;
    else isValid = false;
  }

  //** Mutator Function
  //purpose: Toggle nth bit
  //@param: int Index of the bit to set
  //@post: if nth bit was 0, now it's 1
  //@post: if nth bit was 1, now it's 0
  void Bitset::toggle(intmax_t index){
    if(0<=index && index<=(bitsetSize-1)){
        if(bitset[index] == 0)
            bitset[index] = 1;
        else if(bitset[index] == 1)
            bitset[index] = 0;
    }
    else isValid = false;
  }

  //** Check Function
  //purpose: Check if nth bit is a 1 or 0
  //@param: Index of bit
  //@return: Boolean to show whether the bit is 1 or 0
  bool Bitset::test(intmax_t index){
    if(0<=index && index<=(bitsetSize-1)) 
        return bitset[index];
    else{
         isValid = false;
         return false;
    }
  }

  //** Accessor Function with return in different variable type
  //purpose: turns the bitset of ints into a string of characters 0 and 1
  //@param: None
  //@return: bitset as a string
  std::string Bitset::asString() const{
    //Declare new string
    std::string bitString;
    //Turn each bit into a string (cases for 0 and 1)
    for(intmax_t i=0; i<bitsetSize; i++){
        if(bitset[i] == 0)
            bitString += "0";
        else if(bitset[i] == 1)
            bitString += "1";
    }
    return bitString;
  };