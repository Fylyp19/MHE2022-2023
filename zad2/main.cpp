#include <iostream>
#include <vector>

struct puzzle_t{
    int width;
    int height;
    std::vector<int> board;
};

using solution_t = puzzle_t;

std::ostream &operator<<(std::ostream &o, const solution_t &puzzle){
    using namespace std;
    for (int y = 0; y < puzzle.height; y++){
        for (int x = 0; x < puzzle.width; x++){
            auto &val = puzzle.board[y*puzzle.width+x];
            o << "\t" <<((val>0));
        }
        o << std::endl;
    }
    return o;
}

int main() {
    puzzle_t puzzle{
        5,
        5,
        {
            0,1,0,1,0,
            1,1,1,1,1,
            1,1,1,1,1,
            0,1,1,1,0,
            0,0,1,0,0
        }
    };
    std::cout << puzzle;
    return 0;
}
