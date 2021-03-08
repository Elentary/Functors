#pragma once

#include <vector>

template<class Functor>
class ReverseBinaryFunctor {
 public:
  ReverseBinaryFunctor(Functor functor) : functor_(functor) {}

  template<class T>
  bool operator()(const T &a, const T &b) {
	return functor_(b, a);
  }
 private:
  Functor functor_;
};

template<class Functor>
class ReverseUnaryFunctor {
 public:
  ReverseUnaryFunctor(Functor functor) : functor_(functor) {}

  template<class T>
  bool operator()(const T &a) {
	return !functor_(a);
  }
 private:
  Functor functor_;
};

template<class Functor>
ReverseUnaryFunctor<Functor> MakeReverseUnaryFunctor(Functor functor) {
  return ReverseUnaryFunctor<Functor>(functor);
}

template<class Functor>
ReverseBinaryFunctor<Functor> MakeReverseBinaryFunctor(Functor functor) {
  return ReverseBinaryFunctor<Functor>(functor);
}

class CountComparator {
 public:
  CountComparator(int *count) : count_(count) {}

  template<class T>
  bool operator()(const T &a, const T &b) {
	++(*count_);
	return a != b;
  }
 private:
  int *count_;
};

template<class Iterator>
int ComparisonsCount(Iterator first, Iterator last) {
  int count = 0;

  std::sort(first, last, CountComparator(&count));

  return count;
}

