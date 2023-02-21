#include "array_list.hpp"

template <typename T>
ArrayList<T>::ArrayList() : length(0) 
  {list = new T[length];}


template <typename T>
ArrayList<T>::~ArrayList() 
  {delete [] list;}


template <typename T>
ArrayList<T>::ArrayList(const ArrayList& rhs)
{
  for(std::size_t i=0; i<length; i++)
    list[i] = rhs.list[i];
}


template <typename T>
ArrayList<T>& ArrayList<T>::operator=(ArrayList rhs)
{
  swap(rhs);
  return *this;
}


template <typename T>
void ArrayList<T>::swap(ArrayList& rhs) 
{
  std::swap(list, rhs.list);
  std::swap(length, rhs.length);
}


template <typename T>
bool ArrayList<T>::isEmpty() const noexcept 
{
  if(length==0)
    return true;
  else
    return false;
}


template <typename T>
std::size_t ArrayList<T>::getLength() const noexcept 
  {return length;}


template <typename T>
bool ArrayList<T>::insert(std::size_t position, const T& item)
{
  //Create copy of the current list
  T* oldList = list;

  //Increase size by 1
  length++;
  //Reallocate list with one that is 1 bigger
  list = new T[length];

  //Copy data from copy to the list
  for(std::size_t i=0; i<position; i++)
    list[i] = oldList[i];
  
  
  //Add new item to the list
  list[position] = item;

  //Copy data from copy to the list
  for(std::size_t i=position; i<length; i++)
    list[i+1] = oldList[i];

  //Deallocate the copy
  delete [] oldList;

  if(list[position] == item)
    return true;
  else 
    return false;
}


template <typename T>
bool ArrayList<T>::remove(std::size_t position)
{
  //Return false if unable to decrease size
  if(length==0)
    return false;

  //Create copy of the current list
  T* oldList = list;

  //Decrease size by 1
  length--;
  //Reallocate list with one that is 1 smaller
  list = new T[length];

  //Copy data from copy to the list
  for(std::size_t i=0; i<position; i++){
      list[i] = oldList[i];
    }

  for(std::size_t i=position; i<length; i++){
      list[i] = oldList[i+1];
  }

  //Deallocate the copy
  delete [] oldList;

  return true;
}


template <typename T>
void ArrayList<T>::clear() 
  {length=0; list = new T[0];}


template <typename T>
T ArrayList<T>::getEntry(std::size_t position) const 
{
  if(position<length)
    return list[position];
  else
    return T();
}


template <typename T>
void ArrayList<T>::setEntry(std::size_t position, const T& newValue) 
{
  if(position<length)
    list[position] = newValue;
}
