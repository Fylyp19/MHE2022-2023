//
// Created by Filip on 29.11.2022.
//

#include "../base_functions.h"
#include "../base_for_puzzles.h"

void brute_force(solved_Puzzle_t &test, bool c_t, bool c_c, bool a, bool q, bool c_i, bool g){
    clock_t start;
    double duration;
    start = clock();
    int n = 0;
    int z = 0;
    vector<int> diagram;
    int x = pow(2,test.size_row*test.size_column)-1;
    for(; x >= 1; x--) {
        test.board.clear();
        auto newBoard = convert(x);
        while (newBoard.size() != test.size_row * test.size_column) {
            newBoard.insert(newBoard.begin(), 0);
        };
        test.board = newBoard;
        if ((n % 1) == 0) {
            if (evaluate(test) < test.size_row * test.size_column) {
                cout << n << " : zle linijki-" << evaluate(test) << endl << test << endl;
                z++;
            }
        }
        diagram.push_back(evaluate(test));
        if (evaluate(test) == 0) {
            z++;
            break;
        }
        n++;
    }
    if(c_t == true) {
        duration = (clock() - start) / (double) CLOCKS_PER_SEC;
        cout << "Proces trwal: " << duration << " sekund" << endl;
    }
    if(c_c == true){
        cout << "Dane do Wykresu:" << endl;
        for (double i: diagram) {
            cout << i;
        }
        cout << endl;
    }
    if(a == true){
        cout << "Odpowiedz: " << endl;
        cout << test << endl;
    }
    if(q == true){
        cout << "Jakosc: " << evaluate(test) << endl;
    }
    if(c_i == true){
        cout << "Liczba iteracji: " << n << endl;
    }
    if(g == true){
        cout << "Wykonanie funkcji: " << z << endl;
    }
}