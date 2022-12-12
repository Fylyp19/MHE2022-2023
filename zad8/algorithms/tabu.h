//
// Created by Filip on 29.11.2022.
//

#ifndef ZAD6_TABU_H
#define ZAD6_TABU_H

#include "../base_for_puzzles.h"

solved_Puzzle_t tabu_search(const solved_Puzzle_t &puzzle, int iterations, int tabu_size, bool c_t, bool c_c, bool c_i, bool g, bool show_progress = false);

#endif //ZAD6_TABU_H
