cmake_minimum_required(VERSION 3.23)
project(algorithms)

set(CMAKE_CXX_STANDARD 20)

add_executable(sparse_table sparse_table.cpp)
add_executable(binary_heap binary_heap.cpp)
add_executable(circular_queue circular_queue.cpp)
add_executable(trie trie.cpp)
