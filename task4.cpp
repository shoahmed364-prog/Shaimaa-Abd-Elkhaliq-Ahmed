#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Person {
    string name;
    int age;
};

int main() {
    int n;
    cout << "Enter number of persons: ";
    cin >> n;
    ofstream outFile("persons.txt");
    Person p;

    for (int i = 0; i < n; i++) {
        cout << "Enter person " << i + 1 << " name and age: ";
        cin >> p.name >> p.age;
        outFile << p.name << " " << p.age << endl;
    }
    outFile.close();

    ifstream inFile("persons.txt");
    vector<Person> v;
    Person temp;

    while (inFile >> temp.name >> temp.age) {
        v.push_back(temp);
    }
    inFile.close();


    if (v.size() > 0) {
        Person younger = v[0];
        Person older = v[0];

        for (int i = 1; i < v.size(); i++) {
            if (v[i].age < younger.age) {
                younger = v[i];
            }
            if (v[i].age > older.age) {
                older = v[i];
            }
        }

        ofstream resFile("results.txt");
        resFile << "Younger person: " << younger.name << " " << younger.age << endl;
        resFile << "Older person: " << older.name << " " << older.age << endl;
        resFile.close();

        cout << "Results saved successfully." << endl;
    }

    return 0;
}
