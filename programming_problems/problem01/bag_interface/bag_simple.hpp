/**@file bag_simple.hpp*/
/**This is the derived class of abstract bag.
 * Its purpose is...*/
/**@author Daniel Stoller*/
/**@date 1.22.2023*/


#ifndef STUDENT_BAG_HPP
#define STUDENT_BAG_HPP

#include "abstract_bag.hpp"

template<typename T> class Bag : public AbstractBag<T>{
public:

  //@param no parameter constructor
  Bag();
  
  //@param no parameter destructor
  ~Bag();
  

  std::size_t getCurrentSize() const;
  

  bool isEmpty() const;

  bool add(const T& entry);

  bool remove(const T& entry);

  void clear();

  std::size_t getFrequencyOf(const T& entry) const;

  bool contains(const T& entry) const;

  static const std::size_t MAXSIZE = 100;
  
private:
  // implementation using fixed automatic storage
  //Size is the amount currently in the bag
  std::size_t size;
  
  //Data is the size that the bag can hold
  T data[MAXSIZE];
};

#include "bag_simple.tpp"

#endif
