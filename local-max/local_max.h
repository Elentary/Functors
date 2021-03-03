#pragma once

#include <stdexcept>

template <class Iterator>
Iterator LocalMax(Iterator first, Iterator last) {

  if (*(first + 1) < *first) {
    return first;
  }
  first++;
  for (Iterator i = first; i != last; ++i) {
    if (*(i - 1) < *i && *(i + 1) < *i) {
      return i;
    }

  }

  return last;

}
