#include <gtest/gtest.h>

#include "sort.h"

TEST(SortingTest, SortsCorrectly) {
    std::vector<int64_t> data = {5, 6, 4, 1, 88, 3};
    std::vector<int64_t> expected = data;
    std::sort(expected.begin(), expected.end());

    the_sort(data);

    EXPECT_EQ(data, expected) << "The vector was not sorted correctly.";
}

TEST(SortingTest, HandlesEmptyVector) {
    std::vector<int64_t> data;
    std::vector<int64_t> expected;

    the_sort(data);

    EXPECT_EQ(data, expected) << "The empty vector was not handled correctly.";
}

TEST(SortingTest, SortsBigRandomVec) {
    std::vector<int64_t> data;
    data.resize(10000);
    std::generate(data.begin(), data.end(), random_i64);
    std::vector<int64_t> expected = data;
    std::sort(expected.begin(), expected.end());

    the_sort(data);

    EXPECT_EQ(data, expected) << "The empty vector was not handled correctly.";
}