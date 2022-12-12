//
// Created by Filip on 28.11.2022.
//

#include "../base_functions.h"
#include "../base_for_puzzles.h"

void random_solution(solved_Puzzle_t &test, int iters, bool c_t, bool c_c, bool a, bool q, bool c_i, bool g) {
    int n = 0;
    int z = 0;
    clock_t start;
    double duration;
    start = clock();
    vector<int> diagram;
    for(int i = 0; i <iters; i++){
        diagram.push_back(evaluate(test));
        test = generate_random_solution(test);
        if ((n % 1) == 0) {
            if (evaluate(test) < test.size * test.size) {
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
