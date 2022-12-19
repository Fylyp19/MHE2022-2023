 //
// Created by Filip on 29.11.2022.
//

#include "../base_functions.h"
#include "../base_for_puzzles.h"


solved_Puzzle_t tabu_search(const solved_Puzzle_t &puzzle, int iterations, int tabu_size, bool c_t, bool c_c, bool c_i, bool g, bool show_progress = false) {
    int n = 0;
    int z = 0;
    clock_t start;
    double duration;
    start = clock();
    vector<int> diagram;
    using namespace std;
    list<solved_Puzzle_t> tabu_list;
    tabu_list.push_back(puzzle.generate_random_solution_t());
    auto best_so_far = tabu_list.back();
    for (; n < iterations; n++) {
        //if (show_progress == false) {
        //    cout << n << " " << evaluate(tabu_list.back()) << " " << evaluate(best_so_far)<< endl;
        //}
        vector<solved_Puzzle_t> neighbors;
        for (auto e : tabu_list.back().generate_neighbours_t()) {
            //bool found =(std::find(tabu_list.begin(), tabu_list.end(), e) != tabu_list.end());
            //if (!found) neighbors.push_back(e);
        }
        if (neighbors.size() == 0) {
            cerr << "we ate our tail :/" << endl;
            break;
        }
        tabu_list.push_back(*std::min_element(
                neighbors.begin(), neighbors.end(),
                [](auto l, auto r) { return evaluate(l) < evaluate(r); }));
        if (evaluate(tabu_list.back()) <= evaluate(best_so_far)) {
            best_so_far = tabu_list.back();
            z+=2;
        }
        diagram.push_back(evaluate(best_so_far));
        if (tabu_list.size() > tabu_size) tabu_list.pop_front();
        if(evaluate(best_so_far) == 0 ){
            z++;
            break;
        }
    }
    if(c_t == true) {
        duration = (clock() - start) / (double) CLOCKS_PER_SEC;
        cout << "Proces trwal: " << duration << " sekund" << endl;
    }
    if(c_c == true){
        cout << "Dane do Wykresu:" << endl;
        for (double i: diagram) {
            cout << " " <<  i;
        }
        cout << endl;
    }
    if(c_i == true){
        cout << "Liczba iteracji: " << n << endl;
    }
    if(g == true){
        cout << "Wykonanie funkcji: " << z << endl;
    }
    return best_so_far;
}