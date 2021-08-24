#include <direct.h>
#include<limits.h>
#include<iostream>
#include<fstream>
using namespace std;

void reduce(string &a){
    while(a.back() != '\\') a.pop_back();
}

int main() 
{
    char buff[PATH_MAX];
    _getcwd( buff, PATH_MAX );
    string cur(buff);
    string tmp = cur;
    reduce(cur);
    cur.pop_back();
    reduce(cur);
    cur += "answer\\answer00.txt";
    ifstream ciii;
    ciii.open(cur);
    string tmoo;
    while(ciii >> tmoo) cout << tmoo << '\n';
    return 0;
}