#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cstdint>
#include <limits>
#include <random>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h> // Allows conversion of std::vector to Python lists

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

// Create the Python bindings
PYBIND11_MODULE(sorting, m) {
    m.doc() = "A module to sort vectors using the_sort() function"; // Module docstring

    m.def("the_sort", &the_sort, "Sorts a vector of integers in-place",
          pybind11::arg("vec")); // Bind the function
}