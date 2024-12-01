# build-engineering
A build engineering demo: C++/Python/CI.

## Dependencies

### Binaries/packages:

- CMake >= 3.26
- Ninja
- pkg-config (Mac, Linux)
- GCC 14
- Python >= 3.13
- conan

### Libraries (for vcpkg to work):

- Mac: `brew install autoconf automake libtool gettext pkg-config`

### Setup commands

- python -m venv venv
- conan profile detect
- mkdir build && cd build
- conan install .. --build=missing --output-folder=.
- cmake .. -DCMAKE_TOOLCHAIN_FILE=./conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
- cmake --build .
- cd $GITROOT && export PYTHONPATH=$(pwd)/bin/Release:$(pwd)/test:$PYTHONPATH # take care to use this repo's root folder as your $GITROOT here


### TODO:
- CI builds for Windows and Linux
- Make sure it runs in a Docker container
- Pack and upload artifacts to Actions
- Scripts to automate building and packaging
- Scripts to automate environment setup for the DEPLOY version of the lib
- Write comprehensive docs for the entire env setup, packaging, deployment and usage of the deployed version;
