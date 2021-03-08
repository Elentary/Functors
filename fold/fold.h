#pragma once

struct Sum {
  template<class T>
  T operator()(const T &a, const T &b) {
	return a + b;
  }
};

struct Prod {
  template<class T>
  T operator()(const T &a, const T &b) {
	return a * b;
  }
};

struct Concat {
  template<class T>
  std::vector<T> operator()(std::vector<T> a, const std::vector<T> &b) {
	a.insert(a.end(), b.begin(), b.end());
	return a;
  }
};

template<class Iterator, class T, class BinaryOp>
T Fold(Iterator first, Iterator last, T init, BinaryOp func) {
  for (auto it = first; it != last; ++it) {
	init = func(init, *it);
  }

  return init;
}

class Length {
 public:
  Length(int *length) : length_(length) {}

  template<class T>
  T operator()(const T &a, const T &b) {
	++(*length_);
	return a;
  }
 private:
  int *length_;
};
