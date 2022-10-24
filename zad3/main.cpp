#include <iostream>
#include <vector>

struct puzzle_t{
    int size; //Musi być jeden wspólny rozmiar
    std::vector<int> board; //Board służy jako pseudo tablica dla dwóch ciągów
};

struct solved_Puzzle_t{
    int size; //rozmiar w pionie i poziomie
    std::vector<int> horizontal_lines; // pozioma linia decyzyjna o zaznaczeniu
    std::vector<int> vertical_lines; // pionowa linia decyzyjna o zaznaczeniu
    std::vector<int> board; // tablica na której weryfikujemy rozwiązanie
};

using solution_t = puzzle_t;
using answer_t = solved_Puzzle_t;

std::ostream &operator<<(std::ostream &o, const solution_t &puzzle){
    using namespace std;

    o << " ";

    for(int i = 0; i < puzzle.size; i++){
        o << "\t" << puzzle.board[i];
    }
    o << std::endl;


    for (int y = 0; y < puzzle.size; y++){
        o << puzzle.board[y+puzzle.size];
        for (int x = 0; x < puzzle.size ; x++){
            //Placeholder wydrukowo-wizualizacyjny, wynik nie jest poprawny
            auto &val = puzzle.board[y*puzzle.size+x];
            o << "\t" <<((val>0));
        }
        o << std::endl;
    }
    return o;
}

std::ostream &operator<<(std::ostream &o, const answer_t &puzzle){
    using namespace std;

    o << " ";

    for(int i = 0; i < puzzle.size; i++){
        o << "\t" << puzzle.horizontal_lines[i];
    }
    o << std::endl;

    for (int i = 0; i < puzzle.size; i++){
        o << puzzle.vertical_lines[i];
        for (int x = 0; x < puzzle.size ; x++){
            //Placeholder wydrukowo-wizualizacyjny, wynik nie jest poprawny
            auto &val = puzzle.board[i*puzzle.size+x];
            o << "\t" <<((val>0));
        }
        o << std::endl;
    }
    return o;
}

int is_correct_line(const solved_Puzzle_t &puzzle){

}
int count_inconsistent(const solved_Puzzle_t &puzzle) {
    int error = 0;
    for (int x = 0; x < puzzle.size; x++){
                int count = 0;
                error += 0;
        }
    return error;
}

double evaluate(const solved_Puzzle_t &solvedPuzzle) {
    return count_inconsistent(solvedPuzzle);
}
bool next_solution(solved_Puzzle_t &puzzle) {
    int i = 0;
    for (; i < puzzle.board.size(); i++) {
        if (puzzle.board[i] == 0) {
            puzzle.board[i] = -1;
            break;
        } else if (puzzle.board[i] == -1) {
            puzzle.board[i] = 0;
        }
    }
    return (i != puzzle.board.size());
}


int main() {
    using namespace std;
    puzzle_t nono{
        5,
        //Na wizualizacji lepiej widać jakie znaczenie ma tu board
        {5, 4, 3, 2, 1,
         5, 4, 3 ,2, 1 }

    };
    std::cout << nono;

    cout << endl;
    cout << endl;

    puzzle_t nono_bigger{
            10,
            //Na wizualizacji lepiej widać jakie znaczenie ma tu board
            {10,9,8,7,6,5,4,3,2,1,
             10,9,8,7,6,5,4,3,2,1}

    };
    std::cout << nono_bigger;

    cout << endl;
    cout << endl;

    solved_Puzzle_t test{
        10,
        {10,9,8,7,6,5,4,3,2,1},
        {10,9,8,7,6,5,4,3,2,1},
        {1,1,1,1,1,1,1,1,1,1,
         1,1,1,1,1,1,1,1,1,0,
         1,1,1,1,1,1,1,1,0,0,
         1,1,1,1,1,1,1,0,0,0,
         1,1,1,1,1,1,0,0,0,0,
         1,1,1,1,1,0,0,0,0,0,
         1,1,1,1,0,0,0,0,0,0,
         1,1,1,0,0,0,0,0,0,0,
         1,1,0,0,0,0,0,0,0,0,
         1,0,0,0,0,0,0,0,0,0}};

    std::cout << test;

    int n = 0;
    while (next_solution(test)) {
        if ((n % 10000) == 0) {
            //cout << n << " : " << evaluate(test) << endl << test << endl;
        }
        if (evaluate(test) == 0) {
            //cout << test << endl;
            break;
        }
        n++;
    }
    return 0;
}

//Brudnopis
