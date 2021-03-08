#pragma once

#include <stdexcept>

template <class Iterator>
Iterator LocalMax(Iterator first, Iterator last) {
  Iterator it;
  for (it = first; it != last; ++it) {
    if ((first + 1) == last) {
      return first;
    } else if (it == first) {
      if (*it > *(it + 1)) {
        return it;
      }
    } else if (it == last - 1) {
      if (*it > *(it - 1)) {
        return it;
      }
    } else {
      if (*it > *(it - 1) && *it > *(it + 1)) {
        return it;
      }
    }
  }
  return it;
}
