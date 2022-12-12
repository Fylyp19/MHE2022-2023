//
// Created by Filip on 29.11.2022.
//

#include "../base_functions.h"
#include "../base_for_puzzles.h"

std::random_device rd;
std::mt19937 mtt(rd());

solved_Puzzle_t annealing(const solved_Puzzle_t &puzzle, int iterations, bool c_t, bool c_c, bool c_i, bool g,
                          bool show_progress = false,
                          std::function<double(int)> T = [](int k){return 1000.0/(k+1);}) {
    int k = 0;
    int z = 0;
    vector<double> times_vector;
    vector<int> iterations_vector;
    clock_t start;
    double duration;
    start = clock();
    vector<int> diagram;
    using namespace std;
    auto s = generate_random_solution(puzzle);
    auto best_so_far = s;
    cerr << "annealing..." << endl;
    for (; k < iterations; k++) {
        iterations_vector.push_back(k);
        //if (show_progress == false) {
        //    cout << k << " " << evaluate(s) << " " << evaluate(best_so_far) << endl;
        //}
        auto t = s.generate_neighbor_almost_normal();
        if (evaluate(t) < evaluate(s)) {
            s = t;
            z+=2;
            if (evaluate(s) < evaluate(best_so_far)) {
                best_so_far = s;
                z+=2;
            }
        } else {
            uniform_real_distribution<double> u(0.0,1.0);
            double v = exp(abs(evaluate(t) - evaluate(s))/T(k));
            if (u(mtt) < v) {
                s = t;
            }
        }
        diagram.push_back(evaluate(best_so_far));

        if(evaluate(best_so_far) == 0 ){
            z++;
            break;
        }
        duration = (clock() - start) / (double) CLOCKS_PER_SEC;
        times_vector.push_back(duration);
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
    if(c_i == true){
        cout << "Liczba iteracji: " << k << endl;
    }
    if(g == true){
        cout << "Wykonanie funkcji: " << z << endl;
    }
    if(c_c == true && c_t == true && c_i == true){
        cout << iterations_vector.size() << " " << diagram.size() << " " << times_vector.size() << endl;
        //draw_chart(iterations_vector,diagram,times_vector);
    }
    return best_so_far;
}