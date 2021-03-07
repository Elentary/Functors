#pragma once

#include <stdexcept>

template<class Iterator>
Iterator LocalMax(Iterator first, Iterator last) {
  if (first == last) {
    return last;
  }
  Iterator lm = first;
  Iterator prev = --lm;
  Iterator second = ++lm;
  ++second;
  for (; second != last; ++lm, ++second, ++prev) {
    if (lm == first && second != last) {
      if (*second < *lm) {
        return lm;
      }
    }
    if (*prev < *lm && *second < *lm) {
      return lm;
    }
  }
  if (lm != first && *prev < *lm) {
    return lm;
  }
  return second;
}
