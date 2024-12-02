# build-engineering
A build engineering demo: C++/Python/CI.

## Dependencies

### Binaries/packages:

- CMake >= 3.26
- Ninja
- pkg-config (Mac, Linux)
- GCC >= 13
- Python >= 3.13
- conan

### Setup commands

- `python -m venv venv`
- `conan profile detect # Edit the profile as needed here to match your config` 
- `mkdir build && cd build`
- `conan install . --build=missing`
- `cd $GITROOT && export PYTHONPATH=$(pwd)/bin/Release:$(pwd)/test:$PYTHONPATH # take care to use this repo's root folder as your $GITROOT here`
- `conan build .`

### Build and run the Docker container:
- `DOCKER_BUILDKIT=1 docker build -t fedora-ci .`
- `docker run --rm fedora-ci`


### TODO:
- Pack and upload artifacts to Actions
- Scripts to automate building and packaging
- Scripts to automate environment setup for the DEPLOY version of the lib
- Write comprehensive docs for the entire env setup, packaging, deployment and usage of the deployed version;
