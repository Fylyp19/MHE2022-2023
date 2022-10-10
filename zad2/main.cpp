#include <iostream>
#include <vector>

struct puzzle_t{
    int size; //Musi być jeden wspólny rozmiar
    std::vector<int> board; //Board służy jako pseudo tablica dla dwóch ciągów
};

using solution_t = puzzle_t;

std::ostream &operator<<(std::ostream &o, const solution_t &puzzle){
    //int vertical_line[puzzle.size]; Na przyszłość
    //int horizontal_line[puzzle.size];
    using namespace std;

    o << "#";

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

int main() {
    puzzle_t nono{
        5,
        //Na wizualizacji lepiej widać jakie znaczenie ma tu board
        {5, 4, 3, 2, 1,
               5, 4, 3 ,2, 1 }

    };
    std::cout << nono;
    std::cout << std::endl;
    std::cout << std::endl;
    puzzle_t nono_bigger{
            10,
            //Na wizualizacji lepiej widać jakie znaczenie ma tu board
            {10,9,8,7,6,5,4,3,2,1,
             10,9,8,7,6,5,4,3,2,1}

    };
    std::cout << nono_bigger;
    return 0;
}

//Brudnopis

/*std::ostream &operator<<(std::ostream &o, const solution_t &puzzle){
    using namespace std;
    for (int y = 0; y < puzzle.height; y++){
        for (int x = 0; x < puzzle.width; x++){
            auto &val = puzzle.board[y*puzzle.width+x];
            o << "\t" <<((val>0));
        }
        o << std::endl;
    }
    return o;
}*/