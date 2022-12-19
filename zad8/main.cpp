#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <memory>
#include <sstream>
#include <iterator>
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
using fitness_f = std::function<double(const chromosome_t &, solved_Puzzle_t)>;
using term_condition_f = std::function<bool(const population_t &, const std::vector<double> &)>;
using selection_f = std::function<int(const std::vector<double> &)>;
using crossover_f = std::function<std::vector<chromosome_t>(const std::vector<chromosome_t> &, double)>;
using mutation_f = std::function<chromosome_t(const chromosome_t, double)>;

population_t genetic_algorithm(solved_Puzzle_t puzzle,
                                population_t initial_population,
                               fitness_f fitness,
                               term_condition_f term_condition,
                               selection_f selection, double p_crossover,
                               crossover_f crossover, double p_mutation,
                               mutation_f mutation) {
    using namespace std;
    uniform_real_distribution<double> uniform(0.0, 1.0);
    auto population = initial_population;
    vector<double> population_fit(population.size());
    //transform(population.begin(), population.end(), population_fit.begin(),fitness);
    for(int i = 0; i < population_fit.size(); i++){
        population_fit[i] = fitness(population[i], puzzle);
    }
    while (!term_condition(population, population_fit)) {
        vector<int> parents_indexes(population.size());
        population_t new_population(population.size());
        // calculate fitness
        transform(population_fit.begin(), population_fit.end(),
                  parents_indexes.begin(),
                  [&](auto e) { return selection(population_fit); });
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
        //std::transform(population.begin(), population.end(), population_fit.begin(),
        //               fitness);
        for(int i = 0; i < population_fit.size(); i++){
            population_fit[i] = fitness(population[i], puzzle);
        }
    }
    return population;
};

vector<int> reverse_geno(vector<int> geno){
    int geno_size = sqrt(geno.size());
    vector<int> reverse_board;
    for(int i=0; i < geno_size; i++){
        for(int j=0; j < pow(geno_size,2); j+=geno_size) {
            reverse_board.push_back(geno[i + j]);
        }
    }
    return reverse_board;
}
void print_vector_for_ga(vector<int> a){
    for(int i: a){
        cout << i;
    }
    cout << " ";
}

double count_correct_lines(vector<int> board, solved_Puzzle_t puzzle){
    using namespace std;
    int sum = 0;
    auto reversed_board = reverse_geno(board);
    vector<vector<int>> column_line = board_to_vector(puzzle.size, board);
    vector<vector<int>> row_line = board_to_vector(puzzle.size, reversed_board);
    for(int i = 0; i < puzzle.size; i++){
        if(puzzle.row_lines[i] == row_line[i]){
            sum+=1;
        }
        if(puzzle.column_lines[i] == column_line[i]){
            sum+=1;
        }
    }
    return sum;
}

double fitness_function(const chromosome_t &chromosome, solved_Puzzle_t puzzle){
    auto geno = chromosome;
    return /*1.0 / (1.0 + */count_correct_lines(geno, puzzle)/*)*/;
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
    auto result = genetic_algorithm(test, population, fitness_function,
            [&iterations, &test](auto a, auto b) {
                static int i = 0;
                i++;
                cout << i << ": ";
                for(int i = 0; i < a.size(); i++){
                    cout << " " << fitness_function(a[i], test) << " ";
                }
                cout << endl;
                return i >= iterations;
            },
            selection_roulette, 0.1, crossover_one_point, 0.01, probabilistic_mutation);

    for(int i = 0; i < result.size(); i++){
        test.board = result[i];
        cout << test << endl;
        count_incorrect_lines(test);
    }


    return 0;
}
