#include <bits/stdc++.h>
using namespace std;

ifstream test, code;
ofstream kq;

int main(){
    string s1, s2;
    test.open("Test00\\SPC4.out"); // cu phap (folder chua file out dung)\\(ten file output)
    code.open("spc4.out"); //ten file out can cham
    kq.open("kqspc4.out");
    while (test >> s1 && code >> s2){
        //cerr << s1 << " " << s2 << endl;
        if (s1 != s2) {
            kq << "WRONG";
        }
    }
    test >> s1;
    code >> s2;
    if (s1 == s2) kq << "ACCEPT";
    else kq << "WRONG";
}