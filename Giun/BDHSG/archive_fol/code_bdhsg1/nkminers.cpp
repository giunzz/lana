#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 1e5 + 7;
ll n, f[maxn][2] = {{0}}, d[maxn][3][2] = {{{0}}};
string s;
vec(ll) p;

ll sol(ll pos, ll q){
    if(pos == -1) return 0;
    if(f[pos][q] != -1) return f[pos][q];
    ll tmp = 0;
    f[pos][q] = max(sol(pos - 1, 0), sol(pos - 1, 1));
    if(pos == 0){
        d[pos][p[pos]][q] = 1;
        ++tmp;
    }
    else{
        // if(!d[pos - 1][p[pos]][q]) ++tmp, d[pos][p[pos]][q] = 1;
        // else ++tmp;
        // lp(i, 1, 2){
        //     if(d[pos - 1][(p[pos] + i) % 3][q]) ++tmp;
        //     d[pos][(p[pos] + 1) % 3][q] = d[pos - 1][(p[pos] + 1) % 3][q];
        // }
        lp(i, 0, 2) d[pos][i][q] = d[pos - 1][i][q];
        ++d[pos][p[pos]][q], ++tmp;
        lp(i, 1, 2){
            if(d[pos - 1][(p[pos] + i) % 3][q]) ++tmp;
            d[pos][(p[pos] + 1) % 3][q] = 
            d[pos - 1][(p[pos] + 1) % 3][q] - (pos > 1) ? d[pos - 2][(p[pos] + 1) % 3][q] : 0; 
        }
    }
    f[pos][q] += tmp;
    return f[pos][q];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n >> s;
    for(char c : s){
        if(c == 'M') p.push_back(0);
        else if(c == 'F') p.push_back(1);
        else p.push_back(2);
    }
    // lp(i, 0, n - 1) cerr << p[i] << ' ';
    memset(f, -1, sizeof(f));
    cout << max(sol(p.size() - 1, 0), sol(p.size() - 1, 1));
}