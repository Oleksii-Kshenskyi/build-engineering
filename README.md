# build-engineering
This is a build engineering demo. It includes:
- A C++ vector sorting library;
- A Python wrapper that uses that library (a "library" itself, that is, it doesn't get executed as main);
- CMake/Conan build and GTest unit testing for the C++ library;
- Unit testing for the Python wrapper;
- Full working CI suite for Windows, MacOS and Ubuntu;
- A Dockerfile with a Fedora image to run this as a Docker container;
- A full automation build.py script that only requires you to run the specific build steps you want; you don't need to know any commands, you can just call the specific build stage and the script will do everything for you.
- If you ever want to see what a specific step actually does, just go to the scripts folder and find your platform in the list of folders there. Then look for a script with the same name as your step.

## Pre-requisites

Generally speaking, you should only need Python 3 (works with 3.11, but >= 3.13 is preferable) and your package manager (dnf on Fedora, apt-get on Ubuntu, brew on Mac and scoop on Windows - note that on Windows, the scripting installs even scoop for you if you don't have it).

You also need to separately install Docker Desktop (and make its utilities available from command line), together with the buildx builder if you want the Fedora container to work.

### What does it use? (these are all downloaded and installed for you, you don't need to do anything here):

- CMake >= 3.26
- Ninja
- GCC >= 13
- Python >= 3.13
- Conan (>= 2.0 should work, but >= 2.9 is much better)
- Docker (for the Fedora container)

In terms of thirdparty libraries Conan build uses:
- pybind11 (for C++/Python interop);
- GTest (for unit testing on the C++ side).

### CI/automation Architecture
The build is set up in a way where everything is orchestrated via a single Python script in the repo root, build.py. This script looks into the `scripts/` folder to see which commands it has available. Then the scripts folder includes several directories for all the available platforms: windows, macos, ubuntu and fedora. The script auto-detects which of the platforms you're on and then looks if there is a script with the name you've called.

### Examples of build.py scripts:

- If you're on Windows and you call `python build.py docker`, build.py looks for a script file at `scripts\windows\docker.ps1`;
- If you're on Mac and you call `python build.py install-deps`, build.py looks for a script file at `scripts/macos/install-deps.sh`;
- If you're on Ubuntu and you call `python build.py build`, build.py looks for a script file at `scripts/ubuntu/build.sh`. 

### build.py commands:

- `python build.py install-deps` - this is to install all the build and runtime dependencies of the project, and set up the development environment.
- `python build.py build` - this is the build step. The thirdparty C++ libs are going to also be fetched by Conan automatically.
- `python build.py test` - after you've built the thing, this step will run both C++/GTest unit tests and the Python wrapper unittest tests too.
- `python build.py pack` - packs the C++ lib, the python wrapper and the test into a .zip artifact.
- `python build.py docker` - if you've installed Docker and buildx, you'll be able to build a Fedora Docker container with this. It also runs C++ and Python unit tests to confirm that the build is functional in Fedora.
