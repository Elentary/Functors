#include <catch.hpp>
#include <util.h>
#include <strict_iterator.h>
#include <local_max.h>

struct Int {
  int a;
  Int(int a) : a(a) {}

  bool operator<(const Int &second) const {
	return a < second.a;
  }
};

TEST_CASE("Empty") {
  std::vector<int> v{};
  auto first = MakeStrict(v.begin(), v.begin(), v.end());
  auto last = MakeStrict(v.begin(), v.end(), v.end());
  REQUIRE(last == LocalMax(first, last));
}

TEST_CASE("One") {
  std::vector<int> v{1};
  auto first = MakeStrict(v.begin(), v.begin(), v.end());
  auto last = MakeStrict(v.begin(), v.end(), v.end());
  REQUIRE(first == LocalMax(first, last));
}

TEST_CASE("Two_second") {
  std::vector<int> v{1, 2};
  auto first = MakeStrict(v.begin(), v.begin(), v.end());
  auto last = MakeStrict(v.begin(), v.end(), v.end());
  auto it = LocalMax(first, last);

  auto expected = MakeStrict(v.begin(), v.begin() + 1, v.end());
  REQUIRE(expected == it);
}

TEST_CASE("Three") {
  std::vector<int> v{1, 2, 3};
  auto first = MakeStrict(v.begin(), v.begin(), v.end());
  auto last = MakeStrict(v.begin(), v.end(), v.end());
  auto it = LocalMax(first, last);

  auto expected = MakeStrict(v.begin(), v.begin() + 2, v.end());
  REQUIRE(expected == it);
}

TEST_CASE("First") {
  std::vector<int> v{2, 1, 0};
  auto first = MakeStrict(v.begin(), v.begin(), v.end());
  auto last = MakeStrict(v.begin(), v.end(), v.end());
  REQUIRE(first == LocalMax(first, last));
}

TEST_CASE("All equal") {
  std::vector<int> v{1, 1, 1, 1, 1};
  auto first = MakeStrict(v.begin(), v.begin(), v.end());
  auto last = MakeStrict(v.begin(), v.end(), v.end());
  REQUIRE(last == LocalMax(first, last));
}

TEST_CASE("Only <") {
  std::vector<Int> v = {Int(1), Int(2), Int(9), Int(6)};
  auto first = MakeStrict(v.begin(), v.begin(), v.end());
  auto last = MakeStrict(v.begin(), v.end(), v.end());
  auto it = LocalMax(first, last);

  auto expected = MakeStrict(v.begin(), v.begin() + 2, v.end());
  REQUIRE(expected == it);
}

TEST_CASE("Simple") {
  std::vector<int> v{1, 13, 23, 34, 45, 56, 7, 8, 3, 123};
  auto first = MakeStrict(v.begin(), v.begin(), v.end());
  auto last = MakeStrict(v.begin(), v.end(), v.end());
  auto it = LocalMax(first, last);

  auto expected = MakeStrict(v.begin(), v.begin() + 5, v.end());
  REQUIRE(expected == it);
}
