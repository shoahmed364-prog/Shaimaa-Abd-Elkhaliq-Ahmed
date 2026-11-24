#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    fstream file;
    string fruit;
    file.open("fruit.txt",ios::in);
    while(getline(file,fruit)){
        cout << fruit << endl;
    }
    file.close();
    file.open("fruit.txt",ios::app);
    cout << "fresh fruits" << endl;
    file.close();

    return 0;
}
