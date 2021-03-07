#pragma once

#include <vector>
#include <iostream>

template<class Functor>
class ReverseBinaryFunctor {};

template<class Functor>
class ReverseUnaryFunctor {};

template<class Functor>
ReverseUnaryFunctor<Functor> MakeReverseUnaryFunctor(Functor functor) {
  return ReverseUnaryFunctor<Functor>(functor);
}

template<class Functor>
ReverseBinaryFunctor<Functor> MakeReverseBinaryFunctor(Functor functor) {
  return ReverseBinaryFunctor<Functor>(functor);
}

template<class Iterator>
int ComparisonsCount(Iterator first, Iterator last) {
  int n = 0;
  std::sort(first,
            last,
            [&n](const typename Iterator::value_type& lhs, const typename Iterator::value_type& rhs) {
              ++n;
              return lhs < rhs;
            });
  return n;
}
