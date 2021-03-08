#include <catch.hpp>
#include <util.h>
#include <strict_iterator.h>
#include <local_max.h>

TEST_CASE("Simple") {
    std::vector<int> data{5, 9, 3};
    auto first = MakeStrict(data.begin(), data.begin(), data.end());
    auto last = MakeStrict(data.begin(), data.end(), data.end());
    auto it = LocalMax(first, last);

    auto expected = MakeStrict(data.begin(), data.begin() + 1, data.end());
    REQUIRE(expected == it);
}

TEST_CASE("Single element") {
    std::vector<std::string> data{5};
    auto first = MakeStrict(data.begin(), data.begin(), data.end());
    auto last = MakeStrict(data.begin(), data.end(), data.end());
    REQUIRE(first == LocalMax(first, last));
}