from conan import ConanFile
from conan.tools.cmake import CMake, CMakeToolchain, CMakeDeps
from conan.tools.cmake import cmake_layout

class FmtExampleConan(ConanFile):
    name = "the_sort"
    version = "1.0"

    # Settings for portability
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"

    # Dependencies for the project
    requires = "pybind11/2.13.6"

    # Define the layout of the project
    def layout(self):
        cmake_layout(self)  # Automatically organizes build, source, and install folders

    # Toolchain setup (automatically applied when using CMake)
    def generate(self):
        tc = CMakeToolchain(self)

    # Build the project (optional but convenient for automation)
    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()