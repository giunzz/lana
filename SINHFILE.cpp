//DONE
#include <bits/stdc++.h>
#define path "DKH\\i.inp"
#define path1 "DKH\\o.out"
using namespace std;
//char fol[50] = "codelearn";
//char fil[50] = "test.cpp";
//const char* path = strcat("", strcat(strcat("", fol), strcat("\\", fil)));

int main(){
    ofstream fi, fi1;
    fi.open(path, ios::out);
    fi1.open(path1, ios::out);
    cerr << fi.is_open() << endl;
    cerr << fi1.is_open() << endl;
    fi.close();
    fi1.close();
}