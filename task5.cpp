#include <iostream>
#include <fstream>
using namespace std;

int main() {
    char name[20];
    int id;
    float grade;
    char delim = '$';
    char choice = 'y';

    ofstream file("students.txt", ios::out | ios::app);

    while (choice == 'y' || choice == 'Y') {
        cout << "Enter student name: ";
        cin.ignore();
        cin.getline(name, 20);

        cout << "Enter student ID: ";
        cin >> id;

        cout << "Enter student grade: ";
        cin >> grade;

        file << name << ", " << id << ", " << grade << " " << delim << endl;

        cout << "Add another student? (y/n): ";
        cin >> choice;

        if (choice == 'n' || choice == 'N') {
            break;
        }
    }

    file.close();
    cout << "Records saved to students.txt successfully." << endl;

    return 0;
}
