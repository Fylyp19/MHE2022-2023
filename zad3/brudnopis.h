//Brudnopis

/*
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

int main() {
    int x = pow(2,9)-1;
    for(; x >= pow(2,8); x--){
        auto test = convert(x);
        for(int j = 0; j < test.size(); j++){
            cout << test[j];
        }
        cout << endl;
    }
}*/

/*
    vector<vector<int>> column_board = board_to_vector(test.size, test.board);

    for(int i = 0; i < column_board.size(); i++){
       cout << "{";
        for(int j = 0; j < column_board[i].size(); j++){
            cout << column_board[i][j];
            if(j != column_board[i].size() - 1){
                cout << ",";
            }
        }
        cout << "}";
    }

    cout << endl;

    vector<int> reversed_board =  reversing(test);


    vector<vector<int>> row_board = board_to_vector(test.size, reversed_board);

    for(int i = 0; i < row_board.size(); i++){
        cout << "{";
        for(int j = 0; j < row_board[i].size(); j++){
            cout << row_board[i][j];
            if(j != row_board[i].size() - 1){
                cout << ",";
            }
        }
        cout << "}";
    }
    */

/*
int sum = 0;
auto reversed_board = reverse_board(test);
vector<vector<int>> column_line = board_to_vector(test.size, test.board);
vector<vector<int>> row_line = board_to_vector(test.size, reversed_board);
for(int i = 0; i < test.size; i++){
    if(test.row_lines[i] != row_line[i]){
        sum+=1;
    }
    if(test.column_lines[i] != column_line[i]){
        sum+=1;
    }
}
cout << sum;*/

/*
    test.row_lines.clear();
    for(int i = 0; i < test.size; i++) {
        auto random_vector_int = binary_generator(test.size);
        test.row_lines.insert(test.row_lines.end(),random_vector_int);
    }
    for (int i=0; i < test.row_lines.size(); i++){
        for(int j=0; j < test.row_lines[i].size(); j++) {
            cout << test.row_lines[i][j];
        }
    }
    cout << endl;
    cout << test.row_lines.size();
    cout << endl;
    auto newVector = vector_to_board(test.row_lines);
    for (int i=0; i < newVector.size(); i++){
        cout << newVector[i];
    }
    test.row_lines = board_to_vector(newVector.size(),newVector);
    cout << test << endl;*/


/* do next solution
 * puzzle.row_lines.clear();
    puzzle.column_lines.clear();
    for(int j; j<puzzle.size; j++){
        puzzle.row_lines.insert(puzzle.row_lines.end(), binary_generator(puzzle.size));
        puzzle.column_lines.insert(puzzle.column_lines.end(), binary_generator(puzzle.size));
    }
     */

/*
 * vector<int> vector_to_board(vector<vector<int>> vector_of_vectors){
    vector<int> binary_vector;
    for(int i = 0; i < vector_of_vectors.size(); i++){
        for(int j = 0; j < vector_of_vectors.size(); j++ ) {
            binary_vector.push_back(vector_of_vectors[i][j]);
        }
    }
    return binary_vector;
}
 */

/*
 * std::vector<int> binary_generator(int length){
    using namespace std;
    mt19937 mersenne_engine {rd()};
    uniform_int_distribution<int> dist {0, 1};
    auto gen = [&dist, &mersenne_engine](){
        return dist(mersenne_engine);
    };
    vector<int> vec(length);
    generate(begin(vec), end(vec),gen);
    return vec;
}
 */

/*{vector<int> next_solution_test(solved_Puzzle_t &puzzle) {
    int i = 0;
    for (; i < puzzle.board.size(); i++) {

        //puzzle.board[i] = (rand()%2);

        if (puzzle.board[i] == 0) {
            puzzle.board[i] = 1;
            break;
        } else if (puzzle.board[i-1] == 1) {
            puzzle.board[i] = 0;
        }
    }
    for(int i = 0; i < puzzle.board.size(); i++){
        //cout << puzzle.board[i];
    }

    return (i != puzzle.board.size());
}*/

/*int n = 0;
    while (next_solution(test)) {
        if ((n % 1) == 0) {
            if(evaluate(test)<2) {
                //cout << n << " : " << evaluate(test) << endl << test << endl;
            }
        }
        if (evaluate(test) == 0) {
            //cout << n << " : " << evaluate(test) << endl << test << endl;
            break;
        }
        n++;
    }*/

/*
 * bool next_solution(solved_Puzzle_t &puzzle) {
    int i = 0;
    for (; i < puzzle.board.size(); i++) {
        if (puzzle.board[i] == 0) {
            puzzle.board[i] = 1;
            break;
        } else if (puzzle.board[i-1] == 1) {
            puzzle.board[i] = 0;
        }
    }
    for(int i = 0; i < puzzle.board.size(); i++){
    }

    return (i != puzzle.board.size());
}
 */