#include "limited_size_bag.hpp"

template<typename T>
LimitedSizeBag<T>::LimitedSizeBag() : size(0) 
  {bag = new T[size];}
  


template<typename T>
bool LimitedSizeBag<T>::add(const T& item)
{
  //If the bag is full, return false
  if(size==100)
    return false;

  //Create copy of the current bag
  T* oldBag = bag;

  //Increase size by 1
  size++;
  //Reallocate bag with one that is 1 bigger
  bag = new T[size];

  //Copy data from copy to the bag
  for(unsigned int i=0; i<size; i++)
    bag[i] = oldBag[i];
  
  //Add new item to the bag
  bag[size] = item;

  //Deallocate the copy
  delete [] oldBag;

  if(bag[size] == item)
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

  //Return False if there was no item
  if(itemCount == 0)
    return false;


  //Create copy of the current bag
  T* oldBag = bag;

  //Decrease size by 1
  size--;
  //Reallocate bag with one that is 1 smaller
  bag = new T[size];

  //Copy data from copy to the bag
  int j=0;
  for(unsigned int i=0; i<size; i++){
    //If the item in old bag is the item you want to remove
    if(j==itemIndex)
      j++;
    //If the item is copied
    else{
      bag[i] = oldBag[j];
      j++;
    }
  }

  //Deallocate the copy
  delete [] oldBag;

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
  for(unsigned int i=0; i<size; i++){
    if(bag[i]==item)
      return true;
    }
  return false;
}


template<typename T>
void LimitedSizeBag<T>::clear()
  {size = 0; bag = new T[size];}


template<typename T>
std::size_t LimitedSizeBag<T>::getFrequencyOf(const T & item) const
{
  int itemCount = 0;
  for(unsigned int i=0; i<size; i++){
    if(bag[i]==item)
      itemCount++;
    }
  return itemCount;
};
