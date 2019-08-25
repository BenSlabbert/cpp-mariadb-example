FROM ubuntu:bionic

RUN apt update --fix-missing && \
    apt upgrade -y && \
    apt install -y libmysqlcppconn-dev build-essential wget libssl-dev

# install cmake
WORKDIR /
ARG CMAKE_VERSION=3.15.2
RUN wget https://github.com/Kitware/CMake/releases/download/v${CMAKE_VERSION}/cmake-${CMAKE_VERSION}.tar.gz
RUN tar -xf cmake-${CMAKE_VERSION}.tar.gz
WORKDIR cmake-${CMAKE_VERSION}
RUN ./bootstrap && make && make install
RUN cmake --version

# Install app
WORKDIR /
RUN mkdir app
WORKDIR app
COPY . .
RUN bash build.sh

CMD ["./build/cpp_mariadb"]
