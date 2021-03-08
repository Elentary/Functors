#pragma once

#include <stdexcept>

template <class Iterator, class Predicate>
Iterator RemoveIf(Iterator first, Iterator last, Predicate pred) {
  first = std::find_if(first, last, pred);

  for(auto it = first; it !=last; ++it){
	if (!pred(*it)) {
	  *first++ = *it;
	}
  }

  return first;
}
