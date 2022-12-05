//
// Created by Filip on 29.11.2022.
//

#ifndef ZAD6_ANNEALING_H
#define ZAD6_ANNEALING_H

solved_Puzzle_t annealing(const solved_Puzzle_t &puzzle, int iterations, bool c_t, bool c_c, bool c_i, bool g,
                          bool show_progress = false,
                          std::function<double(int)> T = [](int k){return 1000.0/(k+1);});

#endif //ZAD6_ANNEALING_H
