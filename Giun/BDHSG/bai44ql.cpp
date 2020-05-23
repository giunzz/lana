#include <bits/stdc++.h>

using namespace std;
int n;
string s;

void sol(int a){
    for (char i = 'A'; i <= 'B'; i++){
        if (a > 0 && s[a - 1] == 'B' && i == 'B') continue;
        s.push_back(i);
        if ((int)s.length() == n) cout << s << endl;
        else sol(a + 1);
        s.pop_back();
    }
}

int main(){
    freopen("bai44ql.inp", "r", stdin);
    freopen("bai44ql.out", "w", stdout);
    cin >> n;
    sol(0);
}