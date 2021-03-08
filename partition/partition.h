#pragma once

#include <stdexcept>

template<class Iterator, class Predicate>
Iterator Partition(Iterator first, Iterator last, Predicate pred) {
  first = std::find_if(first, last, std::not_fn(pred));

  for (auto it = first; it != last; ++it) {
	if (pred(*it)) {
	  std::swap(*first++, *it);
	}
  }

  return first;
}
