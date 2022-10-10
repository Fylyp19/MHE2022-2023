#include <iostream>
#include <fstream>
#include "../json.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using json = nlohmann::json;

int main(int argc, char **argv) {
    string file_name = argv[1];
    std::ifstream file(file_name);
    json configData = json::parse(file);

    string s = configData["text"];

    unsigned int i, j;
    int w = configData["w"];
    int h = configData["h"];

    //first line
    for(j = 0; j < w; ++j)
        cout << '*';
    cout << endl;

    //empty text above text
    if(h%2 != 1) {
        for (i = 1; i < h/2-1; ++i) {
            cout << '*';
            for (j = 1; j < w - 1; ++j) {
                cout << ' ';
            }
            cout << '*' << endl;
        }
    } else {
        for (i = 1; i < h/2; ++i) {
            cout << '*';
            for (j = 1; j < w - 1; ++j) {
                cout << ' ';
            }
            cout << '*' << endl;
        }
    }


    // printing text on the center
    unsigned int empty_chars((w - s.size()) / 2);
    cout << '*';
    for(j = 0; j < empty_chars-1; ++j) {
        cout << ' ';
    }
    cout << s;
    for(j = empty_chars + s.size() + 1; j < w; ++j) {
        cout << ' ';
    }
    cout << '*' << endl;

    //empty space under text
    for(i = 1; i < h/2; ++i) {
        cout << '*';
        for(j = 1; j < w - 1; ++j) {
            cout << ' ';
        }
        cout << '*' << endl;
    }

    //last line
    for(j = 0; j < w; ++j)
        cout << '*';
    cout << endl;


    return 0;
}