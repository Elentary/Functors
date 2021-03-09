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

TEST_CASE("Simple 2") {
    std::vector<int> data{100, 222, 13, 0, 0, 0};
    auto it = LocalMax(data.begin(), data.end());
    REQUIRE(*it == 222);
}

TEST_CASE("Simple last") {
    std::vector<int> data{0, 0, 0, 0, 0, 12, 23};
    auto it = LocalMax(data.begin(), data.end());
    REQUIRE(*it == 23);
}

TEST_CASE("Simple pre-last") {
    std::vector<int> data{0, 0, 0, 0, 0, 100, 23};
    auto it = LocalMax(data.begin(), data.end());
    REQUIRE(*it == 100);
}

TEST_CASE("Single element") {
    std::vector<int> data{-10};
    auto it = LocalMax(data.begin(), data.end());
    REQUIRE(*it == data[0]);
}

TEST_CASE("Two elements") {
    std::vector<int> data{7, 5};
    auto it = LocalMax(data.begin(), data.end());
    REQUIRE(*it == 7);
}

TEST_CASE("Two elements reversed") {
    std::vector<int> data{5, 7};
    auto it = LocalMax(data.begin(), data.end());
    REQUIRE(*it == 7);
}

TEST_CASE("Same elements") {
    std::vector<int> data = {20, 20, 20};
    auto it = LocalMax(data.begin(), data.end());
    REQUIRE(it == data.end());
}

TEST_CASE("Empty") {
    std::vector<int> data{};
    auto it = LocalMax(data.begin(), data.end());
    REQUIRE(it == data.end());
}

TEST_CASE("Less only") {
    struct LessOnly {
        LessOnly(int num) {
            num_ = num;
        }

        bool operator< (const LessOnly& other) const {
            return num_ < other.num_;
        }

        int num_;
    };

    std::vector<LessOnly> data = {{7}, {4}, {5}, {5}, {5}};
    auto it = LocalMax(data.begin(), data.end());
    REQUIRE(it->num_ == 7);
}