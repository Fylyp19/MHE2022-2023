#include <iostream>
#include <vector>
#include <random>
#include <string>

using namespace std;

struct puzzle_t{
    int size; //Musi być jeden wspólny rozmiar
    vector<vector<int>>  row_lines; // pozioma linia decyzyjna o zaznaczeniu
    vector<vector<int>> column_lines; // pionowa linia decyzyjna o zaznaczeniu
};

struct solved_Puzzle_t{

    int size; //rozmiar w pionie i poziomie
    vector<vector<int>>  row_lines; // pozioma linia decyzyjna o zaznaczeniu
    vector<vector<int>> column_lines; // pionowa linia decyzyjna o zaznaczeniu
    vector<int> board; // tablica na której weryfikujemy rozwiązanie
};


using answer_t = solved_Puzzle_t;


std::ostream &operator<<(std::ostream &o, const answer_t &puzzle){
    using namespace std;
    o << " " << "\t";

    for (int i = 0; i < puzzle.row_lines.size(); i++)
    {

        for (int j = 0; j < puzzle.row_lines[i].size(); j++){
            o << puzzle.row_lines[i][j];
            if(j != puzzle.row_lines[i].size()-1){
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


vector<int> reverse_board(solved_Puzzle_t &test){
    vector<int> reverse_board;
    for(int i=0; i < test.size; i++){
        for(int j=0; j < pow(test.size,2); j+=test.size){
            reverse_board.push_back(test.board[i+j]);
        }
    }
    return reverse_board;
};

int count_incorrect_lines(solved_Puzzle_t &solutionBoard){
    using namespace std;
    int sum = 0;
    auto reversed_board = reverse_board(solutionBoard);
    vector<vector<int>> column_line = board_to_vector(solutionBoard.size, solutionBoard.board);
    vector<vector<int>> row_line = board_to_vector(solutionBoard.size, reversed_board);
    for(int i = 0; i < solutionBoard.size; i++){
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

int main() {
    using namespace std;


    vector<vector<int>> row_test3 = {{2},{1,1},{3}};
    vector<vector<int>> column_test3 = {{2},{1,1},{3}};
    vector<int> board_test3 = {1,1,1,
                              1,0,1,
                              1,1,0};

    vector<int> board_test_free_zero = {0,0,0,
                                        0,0,0,
                                        0,0,0};
    solved_Puzzle_t test{
            3,
            row_test3,
            column_test3,
            board_test_free_zero
    };

    /*
    vector<vector<int>> row_test4 = {{1},{3},{2},{3}};
    vector<vector<int>> column_test4 = {{1},{3},{3},{1,1}};
    vector<int> board_test4 = {0,0,0,0,
                               0,0,0,0,
                               0,0,0,0,
                               0,0,0,0};

    solved_Puzzle_t test{
            4,
            row_test4,
            column_test4,
            board_test4
    };*/

    std::cout << test << endl;


    //Sekcja Przeglądu po każdej możliwej iteracji
    int n = 0;
    int x = pow(2,test.size*test.size)-1;
    for(; x >= 1; x--){
        test.board.clear();
        auto newBoard = convert(x);
        while (newBoard.size() != test.size*test.size){
            newBoard.insert(newBoard.begin(), 0);
        };
        test.board = newBoard;
        if ((n % 1) == 0) {
            if(evaluate(test)<test.size*test.size) {
               cout << n << " : zle linijki-" << evaluate(test) << endl << test << endl;
            }
        }
        if (evaluate(test) == 0) {
            break;
        }
        n++;
    }
    return 0;
}
