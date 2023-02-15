#include "limited_size_bag.hpp"

template<typename T>
LimitedSizeBag<T>::LimitedSizeBag() : size(0) 
  {}
  

template<typename T>
bool LimitedSizeBag<T>::add(const T& item)
{
  //If the bag is full, return false
  if(size==100)
    return false;

  //Increase size by 1
  size++;
  
  //Add new item to the bag
  bag[size-1] = item;

  if(bag[size-1] == item)
    return true;
  else
    return false;
}


template<typename T>
bool LimitedSizeBag<T>::remove(const T& item)
{
  //Return false if unable to decrease size
  if(size==0)
    return false;

  //Returns false if the item is not in the bag
  //If it is in the bag, get the index of the item
  int itemCount = 0;
  int itemIndex;

  for(unsigned int i=0; i<size; i++){
    if(bag[i]==item){
      itemCount++;
      itemIndex = i;
    }
  }

  //If the item is in the last spot
  if(itemCount == 0)
    return false;

  size--;

  //If the remove item is now out of scope
  if(itemIndex == size){
    return true;
  }

  //Move all the items down 1 spot after the item was removed
  for(unsigned int i=itemIndex; i<size; i++){
    bag[i] = bag[i+1];
  }

  return true;
}



template<typename T>
bool LimitedSizeBag<T>::isEmpty() const
{
  if(size == 0)
    return true;
  return false;
}


template<typename T>
std::size_t LimitedSizeBag<T>::getCurrentSize() const
  {return size;}


template<typename T>
bool LimitedSizeBag<T>::contains(const T& item) const
{  
  if(size==0) return false;

  for(unsigned int i=0; i<size; i++){
    if(bag[i]==item)
      return true;
    }
  return false;
}


template<typename T>
void LimitedSizeBag<T>::clear()
  {size = 0;}


template<typename T>
std::size_t LimitedSizeBag<T>::getFrequencyOf(const T & item) const
{
  std::size_t itemCount = 0;
  for(unsigned int i=0; i<size; i++){
    if(bag[i]==item)
      itemCount++;
    }
    return itemCount;
};