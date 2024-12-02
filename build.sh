#!/bin/bash
set -e

python3 -m venv venv
source venv/bin/activate

pip install conan

conan install . --build=missing
conan build .

cd build/Release
ctest --output-on-failure
cd ../..

export PYTHONPATH=$(pwd)/build/Release:$(pwd)/test:$PYTHONPATH
python -m unittest test_pysort
