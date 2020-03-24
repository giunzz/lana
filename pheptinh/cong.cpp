#include <bits/stdc++.h>

using namespace std;
string a, b;

string cong(string a, string b){
    string s;
    while (a.length() != b.length()){
        if (a.length() > b.length()) b = "0" + b;
        else a = "0" + a;
    }
    int car = 0, dai = a.length() - 1, kq;
    //cerr << dai << endl << endl;
    while (dai >= 0){
        kq = 0;
        kq = (int)a[dai] + (int)b[dai] - 48 - 48 + car;
        //cerr << kq << endl;
        s = (char)(kq % 10 + 48) + s;
        car = kq / 10;
        --dai;
    }
    if (car != 0) s = (char)(car + 48) + s;
    return s;
}

int main(){
    freopen("cong.INP", "r", stdin);
    freopen("cong.OUT", "w", stdout);
    cin >> a >> b;
    cout << cong(a, b);
    return 0;
}
