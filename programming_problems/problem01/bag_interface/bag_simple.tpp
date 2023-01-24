/**@file bag_simple.tpp*/
/**This is the derived class of abstract bag.
 * Its purpose is...*/
/**@author Daniel Stoller*/
/**@date 1.22.2023*/

#include "bag_simple.hpp"

#include <iostream>

// implementation using fixed automatic storage

//@post constructor that sets size to zero
template <typename T> Bag<T>::Bag(): size(0) {}

template <typename T> Bag<T>::~Bag() {}


//@post returns any type T to show the current size of the bag
template <typename T> std::size_t Bag<T>::getCurrentSize() const { return size; }


//@post returns a boolean to show if the bag is empty or not
template <typename T> bool Bag<T>::isEmpty() const { return (size == 0); }


//@param reference to a variable of any type T
//@post will return false if the bag is too full to add anything
//@post will add 1 to the bag and return true if the bag is not already full
template <typename T> bool Bag<T>::add(const T& entry) {

  if(size >= MAXSIZE){
    return false;
  }

  data[size] = entry;
  ++size;
  
  return true;
}

//@param reference to a variable of any type T
//@post will return false if the bag is empty
//@post will remove 1 item from the bag and return true if the bag is not already empty
template <typename T> bool Bag<T>::remove(const T& entry) {

  if(size == 0) return false;
  
  //Loop to find out how many items of any type T are in the bag
  std::size_t idx = 0;
  for(std::size_t i = 0; i < size; ++i){
    if(data[i] == entry) break;
    ++idx;
  }

  if(idx == size) return false;

  --size;
  
  for(std::size_t i = idx; i < size; ++i){
    data[i] = data[i+1];
  }

  return true;
}


//@post returns the size of the bag to 0
template <typename T> void Bag<T>::clear() { size = 0; }

template <typename T> std::size_t Bag<T>::getFrequencyOf(const T& entry) const {

  std::size_t freq = 0;

  for(std::size_t i = 0; i < size; ++i){
    if(data[i] == entry) ++freq;
  }
  
  return freq;
}

template <typename T> bool Bag<T>::contains(const T& entry) const {

  return (getFrequencyOf(entry) != 0);
}

