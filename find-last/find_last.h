#pragma once

#include <stdexcept>

template <class Iterator, class T>
Iterator FindLast(Iterator first, Iterator last, const T& val) {
  Iterator current = first;
  Iterator last_val = last;
  while (current != last) {
    if (*current == val) {
      last_val = current;
    }
    ++current;
  }
  return last_val;
}
