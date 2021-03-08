#pragma once

#include <stdexcept>

template <class Iterator, class T>
Iterator FindLast(Iterator first, Iterator last, const T& val) {
  Iterator FindLast(Iterator first, Iterator last, const T& val) {
    Iterator itToLast = last;
    for (Iterator it = first; it != last; ++it) {
      if (*it == val) {
        itToLast = it;
      }
    }
    return itToLast;
  }
