#pragma once

#include <stdexcept>

template <class Iterator, class Predicate>
Iterator RemoveIf(Iterator first, Iterator last, Predicate pred) {
  Iterator it;
  while (!(pred(*first)) && first != last) {
    ++first;
  }
  if (first != last) {
    for (it = first; ++it != last;) {
      if (!(pred(*it))) {
        *first = std::move(*it);
        ++first;
      }
    }
  }
  return first;
}
