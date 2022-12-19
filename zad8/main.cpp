#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <sstream>
#include "algorithms/random.h"
#include "algorithms/brute.h"
#include "algorithms/hills.h"
#include "algorithms/tabu.h"
#include "algorithms/annealing.h"
#include "base_for_puzzles.h"
#include "base_functions.h"

std::random_device rd;
std::mt19937_64 rd_generator(rd());
using chromosome_t = std::vector<int>;
using population_t = std::vector<chromosome_t>;
using fitness_f = std::function<double(const chromosome_t &)>;
using term_condition_f = std::function<bool(const population_t &, const std::vector<double> &)>;
using selection_f = std::function<int(const std::vector<double> &)>;
using crossover_f = std::function<std::vector<chromosome_t>(const std::vector<chromosome_t> &, double)>;
using mutation_f = std::function<chromosome_t(const chromosome_t, double)>;

population_t genetic_algorithm(population_t initial_population,
                               fitness_f fitness,
                               term_condition_f term_condition,
                               selection_f selection, double p_crossover,
                               crossover_f crossover, double p_mutation,
                               mutation_f mutation) {
    using namespace std;
    uniform_real_distribution<double> uniform(0.0, 1.0);
    auto population = initial_population;
    vector<double> population_fit(population.size());
    transform(population.begin(), population.end(), population_fit.begin(),fitness);
    int switcher_iter = 0;
    while (!term_condition(population, population_fit)) {
        vector<int> parents_indexes(population.size());
        population_t new_population(population.size());
        // calculate fitness
        transform(population_fit.begin(), population_fit.end(),
                  parents_indexes.begin(),
                  [&](auto e) { return selection(population_fit); });
        switcher_iter++;
        // perform crossover operations
        for (int i = 0; i < parents_indexes.size() - 1; i += 2) {
            vector<chromosome_t> offspring = {population[parents_indexes[i]], population[parents_indexes[i + 1]]};
            if (uniform(rd_generator) < p_crossover) {
                offspring = crossover(offspring, p_crossover);
            }
            new_population[i] = offspring[0];
            new_population[i + 1] = offspring[1];
        }
        for (auto &chromosome : new_population) {
            chromosome = mutation(chromosome, p_mutation);
        }
        population = new_population;
        std::transform(population.begin(), population.end(), population_fit.begin(),
                       fitness);
    }
    return population;
};

std::string v_to_str(std::vector<int> v) {
    using namespace std;
    stringstream ss;
    copy(v.begin(), v.end(), std::ostream_iterator<int>(ss, ""));
    string s = ss.str();
    return s.substr(0, s.length());
}

std::string bi_str_to_dec_str(std::string s){
    using namespace std;
    unsigned long long dec_numb = stoull(s,0,2);
    return to_string(dec_numb);
}

std::vector<double> geno_to_feno(const chromosome_t &chromosome){
    using namespace std;
    vector<int> geno = chromosome;
    vector<double> d;

    std::size_t const half_size = geno.size() / 2;
    std::vector<int> f_v(geno.begin(), geno.begin() + half_size);
    std::vector<int> s_v(geno.begin() + half_size, geno.end());



    string f_s = bi_str_to_dec_str(v_to_str(f_v));
    //cout << f << endl;
    string s_s = bi_str_to_dec_str(v_to_str(s_v));
    //cout << f_f_int << endl;

    double f = stod(f_s);
    double s = stod(s_s);


    d.push_back(f);
    d.push_back(s);

    return d;
}

double eggholder(double x1, double x2) {

    double term1 = -(x2+47) * sin(sqrt(abs(x2+x1/2+47)));
    double term2 = x1 * sin(sqrt(abs(x1-(x2+47))));
    return term1 - term2;
}

double fitness_function(const chromosome_t &chromosome) {
    using namespace std;
    double result;
    auto geno = chromosome;
    vector<double> feno = geno_to_feno(geno);
    double egg = eggholder(feno[0], feno[1]);
    result = abs((512 - abs(egg))) * 0.001;
    //cout << result << endl;
    return result;
}
std::vector<chromosome_t> crossover_one_point(std::vector<chromosome_t> parents, double pc) {
    using namespace std;
    uniform_int_distribution<int> locus(0,parents.at(0).size()-1);
    int a = locus(rd_generator);
    auto children = parents;
    for (int i = a; i < parents.at(0).size(); i++) {
        swap(children[0][i],children[1][i]);
    }
    return children;
}

std::vector<chromosome_t> generate_initial_population(int n) {
    std::vector<chromosome_t> ret(n);
    std::uniform_int_distribution<int> uniform(0, 1);
    std::transform(ret.begin(), ret.end(), ret.begin(), [&](auto e) {
        chromosome_t c(9);
        for (int i = 0; i < c.size(); i++) c[i] = uniform(rd_generator);
        return c;
    });
    return ret;
}

int selection_roulette(std::vector<double> fitnesses) {
    using namespace std;
    double sum_of_f;
    for(int i = 0; i < fitnesses.size(); i++){
        sum_of_f += fitnesses[i];
    }
    //cout << sum_of_f << endl;
    std::uniform_int_distribution<int> uniform(0, sum_of_f);
    double a = uniform(rd_generator);
    double offset_down;
    int pick = 0;
    for(int i = 0; i < fitnesses.size(); i++){
        offset_down += fitnesses[i];
        if(offset_down > a){
            pick = i;
            break;
        }
    }
    return pick;
}

chromosome_t probabilistic_mutation(const chromosome_t parent, double p_mutation) {
    using namespace std;
    uniform_real_distribution<double> uni(0.0, 1.0);
    chromosome_t child = parent;
    for(int i = 0; i < parent.size(); i++){
        if (uni(rd_generator) < p_mutation) {
            if(parent[i] == 0){
                child[i] = 1;
            } else if(parent[i] == 1){
                child[i] = 0;
            }
        }
    }
    return child;
}


int main(int argc, char **argv){
    using namespace std;

    int size1 = 3;
    vector<vector<int>> row_test1 = {{2},{1,1},{3}};
    vector<vector<int>> column_test1 = {{2},{1,1},{3}};
    vector<int> board_test1 = board_gen(3);

    solved_Puzzle_t test = {
            size1,
            row_test1,
            column_test1,
            board_test1
    };
    int iterations = 1000;

    population_t population = generate_initial_population(10);
    auto result = genetic_algorithm(
            population, fitness_function ,
            [&iterations](auto a, auto b) {
                static int i = 0;
                i++;
                return i >= iterations;
            },
            selection_roulette, 0.01, crossover_one_point, 0.001, probabilistic_mutation);
    test.board = result[0];
    cout << test;



    //Sekcja Przeglądu po każdej możliwej iteracji
    //brute_force(test);

    // annealing 10000 3 2.1,1.3 2.1,1.3 100 y y y y y y
    // annealing 10000000 5 2,2.2,2.3.1.1 2,1.2.1.3.4 1000 y n y y y y

    //Randomowe rozwiązanie
    //cout << random_solution(test) << endl;

    return 0;
}
/*
 * void func(string name, int iters ,int tabu, solved_Puzzle_t &puzzle, bool c_t, bool c_c,
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
}`
 bool yes_or_no(string x){
    if(x == "y"){
        return true;
    } else {
        return false;
    }
}
 */
/*
 * cout << "Funkcja: " << argv[1] << " Liczba Iteracji: " << argv[2] << " Dlugosc tablicy: " << argv[3] << endl;

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
 */
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