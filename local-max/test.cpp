#include <catch.hpp>
#include <util.h>
#include <strict_iterator.h>
#include <local_max.h>

TEST_CASE("Empty container") {
    std::vector<int> zero(0);
    auto expected = zero.end();
    REQUIRE(expected == LocalMax(zero.begin(), zero.end()));
}

TEST_CASE("1 element") {
    std::vector<int> one(1, std::numeric_limits<int>::max());
    REQUIRE(one.begin() == LocalMax(one.begin(), one.end()));
}

TEST_CASE("Last") {
    std::vector<std::string> lastIsMax{"a", "b", "c", "d", "sdadsfsdf"};
    REQUIRE(lastIsMax.end() - 1 == LocalMax(lastIsMax.begin(), lastIsMax.end()));
}

TEST_CASE("First") {
    std::vector<std::string> lastIsMax{"aa", "a", "a", "a", "a"};
    REQUIRE(lastIsMax.begin() == LocalMax(lastIsMax.begin(), lastIsMax.end()));
}

TEST_CASE("Simple test") {
    std::vector<int> simpleVec{1, 2, 4, 5, 673434, 323, 1212234, 212, 5411, 547, 12467, 2569, 123132};
    REQUIRE(simpleVec.begin() + 4 == LocalMax(simpleVec.begin(), simpleVec.end()));
}

TEST_CASE("All are equal") {
    std::vector<int> simpleVec{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    REQUIRE(simpleVec.end() == LocalMax(simpleVec.begin(), simpleVec.end()));
}