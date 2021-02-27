#include <bits/stdc++.h>
using namespace std;

ifstream test;
ifstream code;

int main(){
    int s1, s2;
    test.open("");
    code.open("");
    while (test >> s1 && code >> s2){
        if (s1 != s2) {
            cout << "WRONG";
            return 0;
        }
    }
    cout << "ACCEPT";
}