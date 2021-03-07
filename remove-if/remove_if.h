#pragma once

#include <stdexcept>

template<class Iterator, class Predicate>
Iterator RemoveIf(Iterator first, Iterator last, Predicate pred) {
  if (first == last) {
    return last;
  }
  Iterator curr = first;
  while (curr != last && !pred(*curr)) {
    ++curr;
  }
  for (Iterator it = curr; ++it != last;) {
    if (!pred(*it)) {
      *curr++ = *it;
    }
  }
  return curr;
}


