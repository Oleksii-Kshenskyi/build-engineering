FROM fedora:latest

RUN dnf update -y && \
    dnf install -y \
    cmake \
    python3 \
    python3-pip \
    python3-virtualenv \
    python3-devel \
    ninja-build \
    gcc \
    gcc-c++ \
    gtest-devel \
    pybind11-devel \
    make \
    git \
    redhat-rpm-config

WORKDIR /app

COPY . .
RUN rm -rf venv build

RUN python3 -m pip install --upgrade pip && \
    python3 -m pip install conan

RUN mkdir -p ~/.conan2/profiles && \
    echo "[settings]" > ~/.conan2/profiles/default && \
    echo "os=Linux" >> ~/.conan2/profiles/default && \
    echo "arch=armv8" >> ~/.conan2/profiles/default && \
    echo "build_type=Release" >> ~/.conan2/profiles/default && \
    echo "compiler=gcc" >> ~/.conan2/profiles/default && \
    echo "compiler.version=14" >> ~/.conan2/profiles/default && \
    echo "compiler.libcxx=libstdc++11" >> ~/.conan2/profiles/default && \
    echo "compiler.cppstd=20" >> ~/.conan2/profiles/default

RUN chmod +x build.sh
CMD ["./build.sh"]

