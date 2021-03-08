#pragma once

#include <stdexcept>

template<class Iterator>
Iterator LocalMax(Iterator first, Iterator last) {
  if (first == last) {
	return last;
  }

  auto prev = first++;
  if (first == last || *first < *prev) {
	return prev;
  }

  auto current = first++;
  auto next = first;

  for (; next != last; ++prev, ++current, ++next) {
	if (*next < *current && *prev < *current) {
	  return current;
	}
  }

  if (*prev < *current) {
	return current;
  }

  return last;
}
