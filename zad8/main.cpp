#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "algorithms/random.h"
#include "algorithms/brute.h"
#include "algorithms/hills.h"
#include "algorithms/tabu.h"
#include "algorithms/annealing.h"
#include "base_for_puzzles.h"
#include "base_functions.h"

using namespace std;


void func(string name, int iters ,int tabu, solved_Puzzle_t &puzzle, bool c_t, bool c_c,
          bool a, bool q, bool c_i, bool g){
    if(name == "brute"){
        brute_force(puzzle, c_t, c_c, a, q, c_i, g);
    } else if (name == "random"){
        random_solution(puzzle, iters, c_t, c_c, a, q, c_i, g);
    } else if (name == "hill1"){
        det_hill_solution(puzzle, iters, c_t, c_c, a, q, c_i, g);
    } else if (name == "hill2"){
        rand_hill_solution(puzzle, iters, c_t, c_c, a, q, c_i, g);
    } else if (name == "tabu"){
        solved_Puzzle_t tabu_puzzle = tabu_search(puzzle, iters, tabu, c_t, c_c, c_i, g);
        if(a == true){
            cout << "Odpowiedz: " << endl;
            cout << tabu_puzzle << endl;
        }
        if(q == true){
            cout << "Jakosc: " << evaluate(tabu_puzzle) << endl;
        }
    } else if (name == "annealing"){
        solved_Puzzle_t annealing_puzzle = annealing(puzzle,iters, c_t, c_c, c_i, g);
        if(a == true){
            cout << "Odpowiedz: " << endl;
            cout << annealing_puzzle << endl;
        }
        if(q == true){
            cout << "Jakosc: " << evaluate(annealing_puzzle) << endl;
        }
    }
}

bool yes_or_no(string x){
    if(x == "y"){
        return true;
    } else {
        return false;
    }
}

int main(int argc, char **argv){
    using namespace std;

    cout << "Funkcja: " << argv[1] << " Liczba Iteracji: " << argv[2] << " Dlugosc tablicy: " << argv[3] << endl;

    string func_name = argv[1];
    int iterations = atoi(argv[2]);
    int size = atoi(argv[3]);
    string row_arr = argv[4];
    string column_arr = argv[5];
    int tabu = atoi(argv[6]);
    bool count_time = yes_or_no(argv[7]);
    bool convergent_curve = yes_or_no(argv[8]);
    bool answer = yes_or_no(argv[9]);
    bool quality = yes_or_no(argv[10]);
    bool count_iterations = yes_or_no(argv[11]);
    bool grade = yes_or_no(argv[12]);



    vector<vector<int>> row_test = argument_to_vector(row_arr);
    vector<vector<int>> column_test = argument_to_vector(column_arr) ;

    vector<int> board_test = board_gen(size);

    solved_Puzzle_t test{
            size,
            row_test,
            column_test,
            board_test
    };


    func(func_name, iterations, tabu, test, count_time, convergent_curve,
         answer, quality, count_iterations, grade);

    //Sekcja Przeglądu po każdej możliwej iteracji
    //brute_force(test);

    // annealing 10000 3 2.1,1.3 2.1,1.3 100 y y y y y y
    // annealing 10000000 5 2,2.2,2.3.1.1 2,1.2.1.3.4 1000 y n y y y y

    //Randomowe rozwiązanie
    //cout << random_solution(test) << endl;

    return 0;
}

/*
    vector<vector<int>> row_test3 = {{2},{1,1},{3}};
    vector<vector<int>> column_test3 = {{2},{1,1},{3}};
    vector<int> board_test3 = {1,1,1,
                               1,0,1,
                               1,1,0};

    vector<int> board_test_free_zero = {0,0,0,
                                        0,0,0,
                                        0,0,0};
*/