#include <bits/stdc++.h>

using namespace std;
int n;
string s;

void sol(int a){
    for (int i = 'A'; i <= 'B'; i++){
        if (s[a - 1] == 'B' && i == 'B' && a > 0) continue;
        s.push_back(i);
        if (s.length() == n) cout << s << endl;
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