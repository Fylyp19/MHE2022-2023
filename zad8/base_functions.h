//
// Created by Filip on 28.11.2022.
//

#ifndef ZAD6_BASE_FUNCTIONS_H
#define ZAD6_BASE_FUNCTIONS_H

#include "base_for_puzzles.h"

vector<vector<int>> board_to_vector(int boardSize, vector<int> boardContent);
vector<int> reverse_board(solved_Puzzle_t &test);
int count_incorrect_lines(solved_Puzzle_t &solutionBoard);
double evaluate(solved_Puzzle_t &solvedPuzzle);
vector<int> convert(int x);
solved_Puzzle_t generate_random_solution(const solved_Puzzle_t &p);
vector<vector<int>> argument_to_vector(string arg);
vector<int> board_gen(int size);
void draw_chart(vector<int> iters, vector<int> grades, vector<double> times);
#endif //ZAD6_BASE_FUNCTIONS_H
