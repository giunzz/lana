#include <bits/stdc++.h>

using namespace std;
string a, b, p;

string multi(string a, string b){
    while (a.length() < b.length()) b = "0" + b;
    while (a.length() > b.length()) a = "0" + a;
    int dai = a.length() - 1, t, car = 0;
    while (dai >= 0){
        t = ((int)a[dai] - 48) * ((int)b[dai] - 48) 
        p = (char)()
    }
}

int main(){
    freopen("nhan.INP", "r", stdin);
    freopen("nhan.OUT", "w", stdout);
    cin >> a >> b;
    cout << multi(a, b);
    return 0;
}