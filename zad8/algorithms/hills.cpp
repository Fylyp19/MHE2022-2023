//
// Created by Filip on 29.11.2022.
//

#include "../base_functions.h"
#include "../base_for_puzzles.h"

vector<vector<int>> generate_neighbours(solved_Puzzle_t &p){
    vector<vector<int>> neighbours;
    auto backup_board = p.board;
    int board_size = p.size*p.size;
    vector<int> new_board = backup_board;
    for(int i = 0; i < board_size; i++){
        if(new_board[i] == 0){
            new_board[i] = 1;
            neighbours.push_back(new_board);
            new_board = backup_board;
        } else if (new_board[i] == 1){
            new_board[i] = 0;
            neighbours.push_back(new_board);
            new_board = backup_board;
        }
    }
    return neighbours;
}

solved_Puzzle_t generate_neighbours_solution(solved_Puzzle_t &p){
    int i_lines = count_incorrect_lines(p);
    auto copy_of_p = p;
    auto neighbours = generate_neighbours(p);
    for(int i = 0; i <neighbours.size(); i++) {
        auto new_p = p;
        for (int j = 0; j < neighbours[i].size(); j++){
            new_p.board[j] = neighbours[i][j];
        }
        int i_new_lines = count_incorrect_lines(new_p);
        if(i_new_lines < i_lines){
            p = new_p;
        }
    }
    if(p.board == copy_of_p.board){
        cout << "Zablokowalem sie" << endl;
        std::exit(0);
    }
    return p;
};

solved_Puzzle_t generate_random_neighbours_solution(solved_Puzzle_t &p){
    random_device rd;
    std::mt19937 mt(rd());
    auto neighbours = generate_neighbours(p);
    int neighbours_count = neighbours.size();
    std::uniform_int_distribution<int> random_point_selector(0,neighbours_count-1);
    int random_point = random_point_selector(mt);
    for (int i =0; i < neighbours[random_point].size(); i++){
        p.board[i] = neighbours[random_point][i];
    }
    return p;
};

void det_hill_solution(solved_Puzzle_t &test, int iters, bool c_t, bool c_c, bool a, bool q, bool c_i, bool g) {
    int n = 0;
    int z = 0;
    clock_t start;
    double duration;
    start = clock();
    vector<int> diagram;
    for(int i = 0; i <iters; i++){
        test = generate_neighbours_solution(test);
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


void rand_hill_solution(solved_Puzzle_t &test, int iters, bool c_t, bool c_c, bool a, bool q, bool c_i, bool g) {
    int n = 0;
    int z = 0;
    clock_t start;
    double duration;
    start = clock();
    vector<int> diagram;
    for(int i = 0; i <iters; i++){
        test = generate_random_neighbours_solution(test);
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