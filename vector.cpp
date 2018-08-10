#include <iostream>

using namespace std;


template <typename T>
Vector<T>::Vector(int sz) : count(0), size(sz)
{
  array = new T[size];
} // Vector()


template <typename T>
Vector<T>::~Vector()
{
  delete [] array;
} // ~Vector()


template <typename T>
int Vector<T>::getCount() const
{
  return count;
} // getCount()


template <typename T>
const T& Vector<T>::operator[] (int index) const
{
  return array[index];
} // operator[] ()


template <typename T>
T& Vector<T>::operator[] (int index)
{
  if (index <= (size - 1))
    return array[index];

  else // else, index is bigger than size, resize, then return
  {
    T *temp = new T[size * 2];
  
    for(int i = 0; i < count; i++)
      temp[i] = array[i];
  
    delete [] array;
    array = temp;
    size *= 2;

    return array[index];
  } // else
} // operator[] ()


template <typename T>
int Vector<T>::operator+= (const T &object)
{
  int pos; 
    
  for(pos = 0; 
     pos < count && ! (object == array[pos]); pos++); 

  if(pos == count) // not found
  {
    if (count == size)
    {
      T *temp = new T[size * 2];
      
      for(int i = 0; i < count; i++)
        temp[i] = array[i];
      
      delete [] array;
      array = temp;
      size *= 2;
    } // if, resize

    for(pos = count - 1; 
      pos >= 0 && object < array[pos]; pos--)
        array[pos + 1] = array[pos];

    array[++pos] = object;  // copy the new day into pos + 1
    count++;
  } // if not found
  
  return pos;
} // operator+= ()
