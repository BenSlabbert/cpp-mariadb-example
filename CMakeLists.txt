cmake_minimum_required(VERSION 3.14)
set(CMAKE_C_FLAGS -Wall)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++17")

project(cpp_mariadb)

set(CMAKE_CXX_STANDARD 11)

include_directories(. /usr/include/cppconn)
link_directories(/usr/lib/ mysqlcppconn)

add_executable(cpp_mariadb main.cpp)

target_link_libraries(cpp_mariadb mysqlcppconn)

# gcc compile sudo g++ -Wall -I/usr/include/cppconn -o testapp tester.cpp -L/usr/lib -lmysqlcppconn
