cmake_minimum_required(VERSION 3.20)
project(zad6)

set(CMAKE_CXX_STANDARD 20)

add_executable(zad6 main.cpp algorithms/random.h base_for_puzzles.h algorithms/random.cpp base_functions.cpp base_functions.h base_for_puzzles.cpp algorithms/brute.cpp algorithms/brute.h algorithms/hills.h algorithms/hills.cpp algorithms/tabu.cpp algorithms/tabu.h algorithms/annealing.cpp algorithms/annealing.h)
