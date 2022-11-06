#include <iostream>
#include <vector>
#include <valarray>
#include <random>
#include <string>
#include <ctime>

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
    int &get(const int x, const int y) {
        return board[y * size + x];
    }
    int get(const int x, const int y) const {
        if ((x < 0) || (x >= size) || (y < 0) || (y >= size)) throw std::invalid_argument("out of board");
        return board.at(y * size + x);
    }
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
        //cout << boardContent[i] << " ";
        //cout << size_counter << " ";
        if(boardContent[i] == 1){
            sum+=1;
            //cout << sum << endl;
        } else {
            if(sum != 0){
                placeholder_part.push_back(sum);
            }
            sum=0;
            //cout << sum << endl;
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

int count_inconsistent(solved_Puzzle_t &puzzle) {
    int error = 0;
    int count = count_incorrect_lines( puzzle);
    error += count;
    return error;
}

double evaluate(solved_Puzzle_t &solvedPuzzle) {
    return count_inconsistent(solvedPuzzle);
}

bool next_solution(solved_Puzzle_t &puzzle) {
    int i = 0;
    for (; i < puzzle.board.size(); i++) {

        //puzzle.board[i] = (rand()%2);

        if (puzzle.board[i] == 0) {
            puzzle.board[i] = 1;
            break;
        } else if (puzzle.board[i-1] == 1) {
            puzzle.board[i] = 0;
        }
    }
    for(int i = 0; i < puzzle.board.size(); i++){
        //cout << puzzle.board[i];
    }

    return (i != puzzle.board.size());
}

/*{vector<int> next_solution_test(solved_Puzzle_t &puzzle) {
    int i = 0;
    for (; i < puzzle.board.size(); i++) {

        //puzzle.board[i] = (rand()%2);

        if (puzzle.board[i] == 0) {
            puzzle.board[i] = 1;
            break;
        } else if (puzzle.board[i-1] == 1) {
            puzzle.board[i] = 0;
        }
    }
    for(int i = 0; i < puzzle.board.size(); i++){
        //cout << puzzle.board[i];
    }

    return (i != puzzle.board.size());
}*/

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


    std::cout << endl;

    cout << endl;

    vector<vector<int>> row_test10 = {{1,5},{2,1,1,2},{2,1,1,2},{2,3,1},{2,3,2},{2,1,1,2},{2,1,1,1},{5,2},{5,2},{6}};
    vector<vector<int>> column_test10 = {{4},{6},{5},{3},{10},{1,2,3},{10},{1,1},{3,2,3},{8}};
    vector<int> board_test10 = {1,1,1,1,0,0,0,0,0,0,
                              0,1,1,1,1,1,1,0,0,0,
                              0,0,0,0,1,1,1,1,1,0,
                              0,0,0,0,0,0,0,1,1,1,
                              1,1,1,1,1,1,1,1,1,1,
                              1,0,0,1,1,0,0,1,1,1,
                              1,1,1,1,1,1,1,1,1,1,
                              1,0,0,0,0,0,0,0,0,1,
                              1,1,1,0,1,1,0,1,1,1,
                              0,1,1,1,1,1,1,1,1,0};


    solved_Puzzle_t test10{
        10,
        row_test10,
        column_test10,
        board_test10
    };

    vector<vector<int>> row_test5 = {{2,2},{2,2},{3},{1},{1}};
    vector<vector<int>> column_test5 = {{2,2},{2},{1},{3},{4}};
    vector<int> board_test5 = {1,1,0,1,1,
                              1,1,0,0,0,
                              0,0,1,0,0,
                              1,1,1,0,0,
                              1,1,1,1,0};
    solved_Puzzle_t test{
            5,
            row_test5,
            column_test5,
            board_test5
    };

    vector<vector<int>> row_test = {{3},{1,1},{2}};
    vector<vector<int>> column_test = {{3},{1,1},{2}};
    vector<int> board_test3 = {1,1,1,
                              1,0,1,
                              1,1,0};

    vector<int> board_test = {0,0,0,
                              0,0,0,
                              0,0,0};
    solved_Puzzle_t test4{
            3,
            row_test,
            column_test,
            board_test
    };

    std::cout << test << endl;



    /*int n = 0;
    while (next_solution(test)) {
        if ((n % 1) == 0) {
            if(evaluate(test)<2) {
                //cout << n << " : " << evaluate(test) << endl << test << endl;
            }
        }
        if (evaluate(test) == 0) {
            //cout << n << " : " << evaluate(test) << endl << test << endl;
            break;
        }
        n++;
    }*/


    //Sekcja Przeglądu po każdej możliwej iteracji
    int n = 0;
    int x = pow(2,test.size*test.size)-1;
    for(; x >= pow(2,test.size*test.size-1); x--){
        test.board.clear();
        auto newBoard = convert(x);
        test.board = newBoard;
        if ((n % 1) == 0) {
            if(evaluate(test)<test.size*test.size) {
                cout << n << " : " << evaluate(test) << endl << test << endl;
            }
        }
        if (evaluate(test) == 0) {
            cout << n << " : " << evaluate(test) << endl << test << endl;
            break;
        }
        n++;
    }


    // Print all binary strings

    return 0;
}
