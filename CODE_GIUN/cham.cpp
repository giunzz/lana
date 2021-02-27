#include <bits/stdc++.h>
using namespace std;

ifstream test;
ifstream code;

int main(){
    char s1, s2;
    test.open("photo\\test8\\photo.out");
    code.open("photo.out");
    while (test >> s1 && code >> s2){
        if (s1 != s2) {
            cout << "WRONG";
            return 0;
        }
    }
    cout << "ACCEPT";
}