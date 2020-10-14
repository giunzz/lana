#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
}

ll f[10][10] = {{0}}, a[10], b[10], p10[10]; //so luong digit [0, 10^i)

void init(){
    p10[0] = 1;
    lp(i, 1, 9) p10[i] = p10[i - 1] * 10;
    lp(j, 0, 9){
        ++f[1][j];
    }
    lp(i, 2, 8){
        f[i][0] = f[i - 1][0] * 10;
        lp(j, 1, 9){
            f[i][j] = f[i - 1][j] * 10 + 1;
        }
    }
}

void  solve(ll x, ll y){
    ll la = log10(x), lb = log10(y);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // OF();
    init();
    lp(i, 1, 8){ //10^i - 1
        lp(j, 0, 9) cerr << f[i][j] << ' ';
        cerr << endl;
    }
    ll x, y;
    // while(cin >> x >> y){
    //     if(x == y && !x) break;
    //     solve(x, y);
    // }
}