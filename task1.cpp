#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string name;
    int id;
    float grade;
    cout << "enter full name:" << endl;
    getline(cin,name);
    cout<<"enter id";
    cin>>id;
    cout<<"enter grade";
    cin>>grade;
    ofstream file("student.txt");
    file<<"name:"<<name<<endl;
    file<<"id:"<<id<<endl;
    file<<"grade:"<<grade<<endl;
    file.close();
    return 0;
}
