#include <catch.hpp>
#include <util.h>
#include <strict_iterator.h>
#include <local_max.h>
#include <set>
#include <string>


TEST_CASE("Middle") {
  std::vector<int> a{1, 2, 0, -1, 3, 4};
  auto it = LocalMax(a.begin(), a.end());
  REQUIRE(*it == 2);
}
TEST_CASE("Only") {
  std::vector<int> a{5};
  auto it = LocalMax(a.begin(), a.end());
  REQUIRE(it == a.end());
}
TEST_CASE("Empty") {
  std::vector<int> a{};
  auto it = LocalMax(a.begin(), a.end());
  REQUIRE(it == a.end());
}
TEST_CASE("Set") {
  std::set<int> s{1, 2, 6, 7};
  auto it = LocalMax(s.begin(), s.end());
  REQUIRE(*it == 7);
}
TEST_CASE("Equal") {
  int n[] = {1, 1, 1};
  auto it = LocalMax(n, n + 3);
  REQUIRE(it == n + 3);
}
TEST_CASE("Only <") {
  struct SS {
    SS(int val) {
      val_ = val;
    }
    bool operator<(const SS& other) const {
      return val_ < other.val_;
    }
    int val_;
  };
  std::vector<SS> v = {{3}, {5}, {7}};
  auto it = LocalMax(v.begin(), v.end());
  REQUIRE(it->val_ == 7);
}
TEST_CASE("With first"){
  std::string s {"cba"};
  auto it = LocalMax(s.begin(), s.end());
  REQUIRE(it == s.begin());
}
