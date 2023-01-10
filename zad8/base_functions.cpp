//
// Created by Filip on 28.11.2022.
//
#include <valarray>
#include <random>
#include "base_for_puzzles.h"

vector<vector<int>> board_to_vector(int boardSize, vector<int> boardContent){
    int sum = 0;
    int size_counter = 0;
    vector<vector<int>> placeholder;
    vector<int> placeholder_part;
    vector<int> mini;
    for(int i = 0; i < boardContent.size(); i++){
        size_counter+=1;
        if(boardContent[i] == 1){
            sum+=1;
        } else {
            if(sum != 0){
                placeholder_part.push_back(sum);
            }
            sum=0;
        }
        if (size_counter%boardSize == 0){
            if(sum !=0) {
                placeholder_part.push_back(sum);
            }
            placeholder_part.push_back(0);
            sum=0;
        }
    }

    for(int i = 0; i < placeholder_part.size(); i++){
        if(placeholder_part[i] != 0){
            mini.push_back(placeholder_part[i]);

        } else{
            placeholder.insert(placeholder.end(),mini);
            mini.clear();
        }
    }

    return placeholder;
}

vector<vector<int>> ga_board_to_vector(int size1, int boardSize, vector<int> boardContent){
    int sum = 0;
    int size_counter = 0;
    vector<vector<int>> placeholder;
    vector<int> placeholder_part;
    vector<int> mini;
    for(int i = 0; i < boardContent.size(); i++){
        size_counter+=1;
        if(boardContent[i] == 1){
            sum+=1;
        } else {
            if(sum != 0){
                placeholder_part.push_back(sum);
            }
            sum=0;
        }
        if (size_counter%2 == 0){
            if(sum !=0) {
                placeholder_part.push_back(sum);
            }
            placeholder_part.push_back(0);
            sum=0;
        }
    }

    for(int i = 0; i < placeholder_part.size(); i++){
        if(placeholder_part[i] != 0){
            mini.push_back(placeholder_part[i]);

        } else{
            placeholder.insert(placeholder.end(),mini);
            mini.clear();
        }
    }

    return placeholder;
}

vector<int> reverse_board(solved_Puzzle_t &test){
    vector<int> reverse_board;
    for(int i=0; i < test.size_row; i++){
        for(int j=0; j < test.size_row*test.size_column; j+=test.size_row){
            reverse_board.push_back(test.board[i+j]);
            cout << test.board[i+j];
        }
    }
    return reverse_board;
}

vector<int> alternative_reverse_board(vector<int> board, solved_Puzzle_t &test){
    vector<int> reverse_board;
    for(int i=0; i < test.size_column; i++){
        for(int j=0; j < pow(test.size_column,2); j+=test.size_row){
            reverse_board.push_back(board[i+j]);
        }
    }
    return reverse_board;
}

int count_incorrect_lines(solved_Puzzle_t &solutionBoard){
    using namespace std;
    int sum = 0;
    int full_size = solutionBoard.size_column * solutionBoard.size_row;
    auto reversed_board = reverse_board(solutionBoard);
    vector<vector<int>> column_line = board_to_vector(solutionBoard.size_column, solutionBoard.board);
    vector<vector<int>> row_line = board_to_vector(solutionBoard.size_row, reversed_board);
    for(int i = 0; i < full_size; i++){
        if(solutionBoard.row_lines[i] != row_line[i]){
            sum+=1;
        }
        if(solutionBoard.column_lines[i] != column_line[i]){
            sum+=1;
        }
    }

    return sum;
}


double evaluate(solved_Puzzle_t &solvedPuzzle) {
    return count_incorrect_lines( solvedPuzzle);
}

vector<int> convert(int x) {
    vector<int> ret;
    while(x) {
        if (x&1)
            ret.push_back(1);
        else
            ret.push_back(0);
        x>>=1;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}

solved_Puzzle_t generate_random_solution(const solved_Puzzle_t &p) {
    using namespace  std;
    static random_device rd;
    static mt19937 mt(rd());
    uniform_int_distribution<int> distr(0,1);
    solved_Puzzle_t rand_sol = p;
    for (int i = 0; i < p.board.size(); i++) {
        if (p.board[i] <= 1) {
            auto new_board = p;
            rand_sol.board[i] = distr(mt);
        }
    }
    return rand_sol;
}

vector<vector<int>> argument_to_vector(string arg){
    vector<vector<int>> placeholder;
    vector<int> mini;
    int z;
    for (int i = 0; i < arg.length(); ++i) {
        if (arg[i] != '.') {
            if (arg[i] != ',') {
                z = (int)arg[i] - 48;
                mini.push_back(z);
            }
        } else if (arg[i] == '.') {
            placeholder.insert(placeholder.end(), mini);
            mini.clear();
        }
    }
    placeholder.insert(placeholder.end(), mini);
    mini.clear();
    return placeholder;
};

vector<int> board_gen(int size1, int size2){
    vector<int> board;
    random_device rd;
    std::mt19937 mt(rd());
    for (int i = 0; i < size1*size2; i++) {
        std::uniform_int_distribution<int> random_point_selector(0,1);
        int random_point = random_point_selector(mt);
        board.push_back(random_point);
    }
    return board;
}

void draw_chart(vector<int> iters, vector<int> grades, vector<double> times){

}