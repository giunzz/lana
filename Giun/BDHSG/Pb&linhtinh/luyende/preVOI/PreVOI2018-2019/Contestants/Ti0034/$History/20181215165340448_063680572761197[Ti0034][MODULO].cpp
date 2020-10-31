#include <bits/stdc++.h>

using namespace std;
#define fname "MODULO"
#define For(i, a, b) for(int i = a; i <= b; i++)
#define FOr(i, a, b) for(int i = a; i < b; i++)
#define FOR(i, a, b) for(int i = a; i >= b; i--)
typedef int64_t ll;
int exits, n, m;
vector <int> ans;
ll s, a, b, k, mod, pw10;
void Try(const int &x){
    if (exits) return;
    if (x > n){
        ll temp = s%mod;
        if (temp == k){
            For (i, 1, n) cout << ans[i];
            exits = 1;
        }
        return;
    }
    s = s*10+a;
    ans[x] = a;
    Try(x+1);
    s -= a; s/=10;
    s = s*10+b;
    ans[x] = b;
    Try(x+1);
    s -= b; s/=10;
}
map <ll, vector<int> > M;
void try1(const int &x){
    if (x > m){
        ll temp = (s*pw10)%mod;
        if (M.find(temp) == M.end()){
            M[temp] = ans;
        }
        return;
    }
    s = s*10+a;
    ans[x] = a;
    try1(x+1);
    s -= a; s/=10;
    s = s*10+b;
    ans[x] = b;
    try1(x+1);
    s -= b; s/=10;
}
void try2(const int &x){
    if (exits) return;
    if (x > n){
        ll temp = (k-s%mod+mod)%mod;
        if (M.find(temp) != M.end()){
            exits = 1;
            vector <int> tg = M[temp];
            For (i, 1, m) cout << tg[i];
            For (i, m+1, n) cout << ans[i];
        }
        return;
    }
    s = s*10+a;
    ans[x] = a;
    try2(x+1);
    s -= a; s/=10;
    s = s*10+b;
    ans[x] = b;
    try2(x+1);
    s -= b; s/=10;
}
int main(){
    if (fopen(fname".inp", "r")){
        freopen (fname".inp", "r", stdin);
        freopen (fname".out", "w", stdout);
    }
    cin >> a >> b >> n >> k;
    ans.resize(n+1);
    mod = 1;
    For (i, 1, n) mod = mod*2;
    if (n <= 20){
        Try(1);
        if (!exits) cout << -1;
        return 0;
    }
    m = n/2;
    pw10 = 1;
    For (i, 1, n-m) pw10 = (pw10*10)%mod;
    try1(1);
    try2(m+1);
}
