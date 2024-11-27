#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cstdint>
#include <limits>
#include <random>

constexpr size_t VEC_SIZE = 100000;

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

int main() {
    std::vector<int64_t> vec;
    // vec.reserve(VEC_SIZE);
    vec.resize(VEC_SIZE);

    std::generate(vec.begin(), vec.end(), random_i64);
    the_sort(vec);
    // for(auto& num : vec) {
    //     std::cout << num << " ";
    // }
    std::cout << std::endl;
}