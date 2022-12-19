//
// Created by Filip on 28.11.2022.
//

#include "base_for_puzzles.h"

std::ostream &operator<<(std::ostream &o, const answer_t &puzzle){
    using namespace std;
    o << " " << "\t";

    for (const auto & row_line : puzzle.row_lines)
    {

        for (int j = 0; j < row_line.size(); j++){
            o << row_line[j];
            if(j != row_line.size()-1){
                o << ",";
            }
        }
        o << "\t";
    }
    o << std::endl;

    for (int y = 0; y < puzzle.size; y++){

        for (int j = 0; j < puzzle.column_lines[y].size(); j++){
            o << puzzle.column_lines[y][j];
            if(j != puzzle.column_lines[y].size() - 1){
                o << ",";
            }
        }
        for (int x = 0; x < puzzle.size ; x++){
            auto &val = puzzle.board[y*puzzle.size+x];
            o << "\t" <<((val>0));
        }
        o << std::endl;
    }
    return o;
}

/*bool operator==(solved_Puzzle_t l, solved_Puzzle_t r) {
    if (l.size != r.size) return false;
    for (unsigned i = 0; i < r.board.size(); i++) {
        if (l.board.at(i) != r.board.at(i)) return false;
    }
    return true;
}*/



solved_Puzzle_t solved_Puzzle_t::generate_random_solution_t() const {
    using namespace  std;
    const solved_Puzzle_t
    &p = *this;
    static random_device rd;
    static mt19937 mt(rd());
    uniform_int_distribution<int> distr(0,1);
    solved_Puzzle_t rand_sol = p;
    for (int i = 0; i < p.board.size(); i++) {
        if (p.board[i] <= 1){
            auto new_board = p;
            rand_sol.board[i] = distr(mt);
        }
    }
    return rand_sol;
}

std::vector<solved_Puzzle_t> solved_Puzzle_t::generate_neighbours_t() const {
    const solved_Puzzle_t &p = *this;
    std::vector<solved_Puzzle_t> neighbours;
    int board_size = p.size*p.size;
    for(int i = 0; i < board_size; i++){
        if(p.board[i] == 0){
            auto new_board = p;
            new_board.board[i] = 1;
            neighbours.push_back(new_board);
        } else if (p.board[i] == 1){
            auto new_board = p;
            new_board.board[i] = 0;
            neighbours.push_back(new_board);
        }
    }
    return neighbours;
}

solved_Puzzle_t solved_Puzzle_t::generate_neighbor_almost_normal() const {
    using namespace std;
    static random_device rd;
    static mt19937 mt(rd());
    const solved_Puzzle_t &p = *this;
    std::normal_distribution norm;
    std::uniform_int_distribution<int> int_distr(0, p.board.size() - 1);
    double how_may_change = norm(mt);
    auto new_board = p;
    for (int i = 0; i < how_may_change; i++) {
        int n = int_distr(mt);
        if(p.board[n] == 0){
            new_board.board[n] = 1;
        } else if (p.board[n] == 1){
            new_board.board[n] = 0;
        }
    }
    return new_board;
}