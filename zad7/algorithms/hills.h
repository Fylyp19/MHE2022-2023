//
// Created by Filip on 29.11.2022.
//

#ifndef ZAD6_HILLS_H
#define ZAD6_HILLS_H

#include "../base_for_puzzles.h"

vector<vector<int>> generate_neighbours(solved_Puzzle_t &p);
solved_Puzzle_t generate_neighbours_solution(solved_Puzzle_t &p);
solved_Puzzle_t generate_random_neighbours_solution(solved_Puzzle_t &p);
void det_hill_solution(solved_Puzzle_t &test, int iters, bool c_t, bool c_c, bool a, bool q, bool c_i, bool g);
void rand_hill_solution(solved_Puzzle_t &test, int iters, bool c_t, bool c_c, bool a, bool q, bool c_i, bool g);

#endif //ZAD6_HILLS_H
