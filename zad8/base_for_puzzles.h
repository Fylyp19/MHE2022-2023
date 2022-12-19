//
// Created by Filip on 28.11.2022.
//

#include <iostream>
#include <vector>
#include <vector>
#include <random>
#include <string>
#include <algorithm>
#include <ctime>
#include <list>
#include <chrono>
#include <functional>

#ifndef ZAD8_BASE_FOR_PUZZLES_H
#define ZAD8_BASE_FOR_PUZZLES_H

using namespace std;

struct solved_Puzzle_t{
    int size; //rozmiar w pionie i poziomie
    vector<vector<int>>  row_lines; // pozioma linia decyzyjna o zaznaczeniu
    vector<vector<int>> column_lines; // pionowa linia decyzyjna o zaznaczeniu
    vector<int> board; // tablica na której weryfikujemy rozwiązanie


    solved_Puzzle_t generate_random_solution_t() const;

    std::vector<solved_Puzzle_t> generate_neighbours_t() const;

    solved_Puzzle_t generate_neighbor_almost_normal() const;

    bool next_solution();
};

using answer_t = solved_Puzzle_t;

ostream &operator<<(std::ostream &o, const answer_t &puzzle);
//bool operator==(solved_Puzzle_t l, solved_Puzzle_t r);

#endif //ZAD6_BASE_FOR_PUZZLES_H
