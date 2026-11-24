#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream file;

    file.open("welcome.txt", ios::out);
    file << "Hello Everybody";
    file.close();

    file.open("welcome.txt", ios::in | ios::out);

    file.seekp(10);
    file.put('o');
    file.put('n');
    file.put('e');

    file.close();

    file.open("welcome.txt", ios::in);

    char ch;
    while (file.get(ch))
    {
        cout << ch;
    }

    file.close();

    return 0;
}


