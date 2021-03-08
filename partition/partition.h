#pragma once

#include <stdexcept>

template <class Iterator, class Predicate>
Iterator Partition(Iterator first, Iterator last, Predicate pred) {
  Iterator it;
  while (pred(*first)) {
    ++first;
  }
  for (Iterator i = first; ++i != last;) {
    if (pred(*i)) {
      auto t = *first;
      *first = *i;
      *i = t;
      ++first;
    }
  }
  return first;
}
