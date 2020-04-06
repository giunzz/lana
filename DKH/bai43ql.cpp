#include <bits/stdc++.h>

using namespace std;
string s, b;
int d[257] = {0};

void sol(int a){
    for (int i = 0; i < s.length(); i++){
        if (!d[s[i]]){
            b.push_back(s[i]);
            d[s[i]] = 1;
            if (a == s.length() - 1) cout << b << endl;
            else sol(a + 1);
            b.pop_back();
            d[s[i]] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("f.inp", "r", stdin);
    freopen("f.out", "w", stdout);
    cin >> s;
    sort(s.begin(), s.end());
    sol(0);
}