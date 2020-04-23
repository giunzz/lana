#include <bits/stdc++.h>

using namespace std;
const int maxm = 500 + 7;
long long n, m, k, x, cs[maxm] = {0}, d[maxm] = {0};
string s, ma;

void change(){
    long long num = x - 1, vt = m;//, lt = 0, mu = pow(k, m);
    //while (mu * lt <= num) ++lt;
    //lt = num / mu;
    //num = num - mu * lt;
    //cerr << num << " " << lt << endl;
    while (vt != 0 && num != 0){
        cs[vt--] = num % k;
        //cerr << num % k << endl;
        num /= k;
    }
}

void enter(){
    long long dem = 0;
    cin >> n >> m >> k >> x;
    change();
    cin >> s;
    //cin.ignore();
    for (int i = 0; i < n; i++) {
        if (s[i] == '#') d[++dem] = i;
    }
    for (int i = 1; i <= m; i++){
        cin >> ma;
        sort(ma.begin(), ma.end());
        //cerr << ma << endl;
        s[d[i]] = ma[cs[i]]; 
        //cerr << cs[i] << endl;
    }
    cout << s;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("fword.inp", "r", stdin);
    freopen("fword.out", "w", stdout);
    enter();
    //for (int i = 1; i <= m; i++) cerr << cs[i] << " ";
}