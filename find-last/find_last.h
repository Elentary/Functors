#pragma once

#include <stdexcept>

template<class Iterator, class T>
Iterator FindLast(Iterator first, Iterator last, const T &val) {
  auto answer = last;

  for (auto it = first; it != last; it++) {
    if (*it == val) {
      answer = it;
    }
  }

  return answer;
}
