#pragma once

#include <stdexcept>

template <class Iterator, class Predicate>
Iterator Partition(Iterator first, Iterator last, Predicate pred) {
  Iterator it = first, border = last;
  while (it != border) {
    if (!pred(*it)) {
      --border;
      std::swap(*it, *border);
    } else {
      ++it;
    }
  }
  return it;
}
