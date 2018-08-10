#ifndef VECTOR_H
#define VECTOR_H

#include "day.h"
using namespace std;

template <typename T>
class Vector
{
  T* array;
  int count;
  int size;
public:
  Vector(int sz);
  ~Vector();
  int getCount() const;
  const T& operator[] (int index) const;
  T& operator[] (int index);
  int operator+= (const T &object);
}; // class Vector

#include "vector.cpp"
#endif 