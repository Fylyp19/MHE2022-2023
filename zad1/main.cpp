#include <iostream>
#include <vector>
#include <fstream>
#include "C:\Users\Filip\CLionProjects\zad1\json.hpp"

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using json = nlohmann::json;

int main() {
    vector<string> strings;
    //cout << "Enter string: ";
    std::ifstream file("config.json");
    json configData = json::parse(file);
    cout << configData["w"] << endl;

    for(;;) {
        string s = configData["text"];
        s = configData["text"]
        strings.push_back(s);

        if(getchar() == '\n')
            break;
    }
    /*
    unsigned int n, m, i, j;
    cout << "Enter size: ";
    cin >> n;
    cout << "Enter size: ";
    cin >> m;

    // assuming strings.size() < n
    unsigned int empty_lines_around_text((n - strings.size()) / 2);
    cout << "empty_lines_around_text = " << empty_lines_around_text << endl;

    // first horizontal row of stars
    for(j = 0; j < n; ++j)
        cout << '*';
    cout << endl;

    for(i = 1; i < empty_lines_around_text; ++i) {
        cout << '*';
        for(j = 1; j < m - 1; ++j) {
            cout << ' ';
        }
        cout << '*' << endl;
    }

    //here we do the actual printing of the strings
    for(i = 0; i < strings.size(); ++i) {
        string s = strings[i];

        // once again, assuming the size of each string is < n
        unsigned int empty_chars_around_string((n - s.size()) / 2);
        cout << '*';
        for(j = 0; j < empty_chars_around_string; ++j)
            cout << ' ';
        cout << s;
        for(j = empty_chars_around_string + s.size() + 1; j < n - 1; ++j)
            cout << ' ';
        cout << '*' << endl;
    }

    for(i = empty_lines_around_text + strings.size() + 1; i < n; ++i) {
        cout << '*';
        for(j = 1; j < n - 1; ++j) {
            cout << ' ';
        }
        cout << '*' << endl;
    }
    // last horizontal line of '*' (we close the square)
    for(j = 0; j < n; ++j)
        cout << '*';
    cout << endl;

    */
    return 0;
}