#include "sort.h"

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cstdint>
#include <limits>
#include <random>

std::vector<int64_t>& the_sort(std::vector<int64_t>& vec) {
    std::sort(vec.begin(), vec.end());
    return vec;
}

int64_t random_i64() {
    auto min = std::numeric_limits<int64_t>::min();
    auto max = std::numeric_limits<int64_t>::max();
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<int64_t> dis(min, max);

    return dis(gen);
}