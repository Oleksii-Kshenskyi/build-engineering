#include "sort.h"

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cstdint>
#include <limits>
#include <random>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

PYBIND11_MODULE(sorting, m) {
    m.doc() = "A module to sort vectors using the_sort() function";

    m.def("the_sort", &the_sort, "Sorts a vector of integers in-place",
          pybind11::arg("vec"));
    m.def("random_i64", &random_i64, "Returns a random 64-bit integer");
}