#pragma once

#include <stdexcept>

template <class Iterator, class T>
Iterator FindLast(Iterator first, Iterator last, const T& val) {

  Iterator k = last;
  for (Iterator i = first; i != last; ++i) {
    if (val == *i) {
      k = i;
    }
  }

  return k;

}
