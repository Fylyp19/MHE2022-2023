#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <algorithm>
#include <ctime>
#include <list>

using namespace std;

struct solved_Puzzle_t{
    int size; //rozmiar w pionie i poziomie
    vector<vector<int>>  row_lines; // pozioma linia decyzyjna o zaznaczeniu
    vector<vector<int>> column_lines; // pionowa linia decyzyjna o zaznaczeniu
    vector<int> board; // tablica na której weryfikujemy rozwiązanie

    solved_Puzzle_t generate_random_solution_t() const;

    std::vector<solved_Puzzle_t> generate_neighbours_rand_t() const;

    bool next_solution();
};


using answer_t = solved_Puzzle_t;


std::ostream &operator<<(std::ostream &o, const answer_t &puzzle){
    using namespace std;
    o << " " << "\t";

    for (const auto & row_line : puzzle.row_lines)
    {

        for (int j = 0; j < row_line.size(); j++){
            o << row_line[j];
            if(j != row_line.size()-1){
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
}

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

solved_Puzzle_t brute_force(solved_Puzzle_t &test){
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

solved_Puzzle_t random_solution(solved_Puzzle_t &test, int iters) {
    int n = 0;
    for(int i = 0; i <iters; i++){
        test = generate_random_solution(test);
        if ((n % 1) == 0) {
            if (evaluate(test) < test.size * test.size) {
                cout << n << " : zle linijki-" << evaluate(test) << endl << test << endl;
            }
        }
        if (evaluate(test) == 0) {
            break;
        }
        n++;
    }
}

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

solved_Puzzle_t det_hill_solution(solved_Puzzle_t &test, int iters) {
    int n = 0;
    for(int i = 0; i <iters; i++){
        test = generate_neighbours_solution(test);
        if ((n % 1) == 0) {
            if (evaluate(test) < test.size * test.size) {
                cout << n << " : zle linijki-" << evaluate(test) << endl << test << endl;
            }
        }
        if (evaluate(test) == 0) {
            break;
        }
        n++;
    }
}


solved_Puzzle_t rand_hill_solution(solved_Puzzle_t &test, int iters) {
    int n = 0;
    for(int i = 0; i <iters; i++){
        test = generate_random_neighbours_solution(test);
        if ((n % 1) == 0) {
            if (evaluate(test) < test.size * test.size) {
                cout << n << " : zle linijki-" << evaluate(test) << endl << test << endl;
            }
        }
        if (evaluate(test) == 0) {
            break;
        }
        n++;
    }
}

vector<int> empty_board_gen(int size){
    vector<int> zero_board;
    for (int i = 0; i < size*size; i++) {
        zero_board.push_back(0);
    }
    return zero_board;
}

vector<int> board_gen(int size){
    vector<int> board;
    random_device rd;
    std::mt19937 mt(rd());
    for (int i = 0; i < size*size; i++) {
        std::uniform_int_distribution<int> random_point_selector(0,1);
        int random_point = random_point_selector(mt);
        board.push_back(random_point);
    }
    return board;
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

bool solved_Puzzle_t::next_solution() {
    solved_Puzzle_t &puzzle = *this;
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

solved_Puzzle_t solved_Puzzle_t::generate_random_solution_t() const {
    using namespace  std;
    const solved_Puzzle_t &p = *this;
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

bool operator==(solved_Puzzle_t l, solved_Puzzle_t r) {
    if (l.size != r.size) return false;
    for (unsigned i = 0; i < r.board.size(); i++) {
        if (l.board.at(i) != r.board.at(i)) return false;
    }
    return true;
}

void func(string name, int iters ,int tabu, solved_Puzzle_t &puzzle){
    if(name == "brute"){
        brute_force(puzzle);
    } else if (name == "random"){
        random_solution(puzzle, iters);
    } else if (name == "hill1"){
        det_hill_solution(puzzle, iters);
    } else if (name == "hill2"){
        rand_hill_solution(puzzle, iters);
    } else if (name == "tabu"){
        //solved_Puzzle_t tabu_puzzle = tabu_search(puzzle,iters,tabu);
        //cout << tabu_puzzle << endl;
        //cout << evaluate(tabu_puzzle) << endl;
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


    vector<vector<int>> row_test = argument_to_vector(row_arr);
    vector<vector<int>> column_test = argument_to_vector(column_arr) ;

    vector<int> board_test = board_gen(size);

    solved_Puzzle_t test{
            size,
            row_test,
            column_test,
            board_test
    };


    func(func_name, iterations, tabu, test);

    //Sekcja Przeglądu po każdej możliwej iteracji
    //brute_force(test);

    // hill1 10000 3 2.1,1.3 2.1,1.3
    // hill1 10000 5 2,2.2,2.3.1.1 2,1.2.1.3.4

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
