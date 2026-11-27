#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    ifstream input("names.txt");
    if (!input) {
        cout << "Unable to open the file" << endl;
        return 1;
    }

    string line;
    vector<string> names;

    while (getline(input, line)) {
        if (!line.empty()) {
            names.push_back(line);
        }
    }
    input.close();

    sort(names.begin(), names.end());

    cout << "Names sorted Successfully" << endl;
    for (int i = 0; i < names.size(); i++) {
        cout << names[i] << endl;
    }

    return 0;
}
