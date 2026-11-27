#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

int main() {
    const string fileName = "grades.txt";
    const string tempName = "temp_grades.txt";

    ofstream outFile(fileName);
    if (outFile.fail()) {
        cout << "Error: Unable to open " << fileName << " for writing." << endl;
        return 1;
    }

    cout << "Enter 5 integer grades:" << endl;
    for (int i = 0; i < 5; i++) {
        int g;
        cin >> g;
        outFile << g << endl;
    }
    outFile.close();
    ifstream inFile(fileName);
    if (inFile.fail()) {
        cout << "Error: Unable to open " << fileName << " for reading." << endl;
        return 1;
    }

    cout << "\nGrades in file:" << endl;
    int grade;
    while (inFile >> grade) {
        cout << grade << endl;
    }

    if (inFile.bad() || (!inFile.eof() && inFile.fail())) {
        cout << "Error: Invalid data or read failure occurred." << endl;
        inFile.close();
        return 1;
    }
    inFile.close();
    int gradeToDelete;
    cout << "\nEnter a grade to delete: ";
    cin >> gradeToDelete;

    ifstream srcFile(fileName);
    ofstream tempFile(tempName);

    if (srcFile.fail() || tempFile.fail()) {
        cout << "Error: Unable to open files for updating." << endl;
        srcFile.close();
        tempFile.close();
        return 1;
    }

    int currentGrade;
    while (srcFile >> currentGrade) {
        if (currentGrade != gradeToDelete) {
            tempFile << currentGrade << endl;
        }
    }

    if (srcFile.bad() || (!srcFile.eof() && srcFile.fail())) {
        cout << "Error: Failed while reading grades during deletion." << endl;
        srcFile.close();
        tempFile.close();
        remove(tempName.c_str());
        return 1;
    }

    srcFile.close();
    tempFile.close();
    if (remove(fileName.c_str()) != 0) {
        cout << "Error: Could not delete original file " << fileName << "." << endl;
        return 1;
    }

    if (rename(tempName.c_str(), fileName.c_str()) != 0) {
        cout << "Error: Could not rename temporary file to " << fileName << "." << endl;
        return 1;
    }

    cout << "Success: Grade " << gradeToDelete << " deleted and " << fileName << " updated." << endl;
    return 0;
}
