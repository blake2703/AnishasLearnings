CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

set(CMAKE_CXX_STANDARD 11)


add_subdirectory(googletest)

add_executable(HashTable
    src/main.cpp 
    src/HashTable.cpp
    src/WordEntry.cpp
)

add_executable(test
    tests/test.cpp
)

target_link_libraries(test gtest)
target_compile_definitions(test PRIVATE gtest_disable_pthreads=ON)