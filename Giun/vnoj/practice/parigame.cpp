#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "f"
using namespace std;

template <typename T> inline void Read(T &x){
    x = 0; char c;
    while(!isdigit(c = getchar()));
    do
    {
        x = x * 10 + c - '0';
    } while (isdigit(c = getchar()));
}

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void giuncute(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll mxn = 502;
ll n, g[mxn][mxn];
bool row[mxn][mxn] = {{0}}, col[mxn][mxn] = {{0}};

ll calc(ll i, ll j){
    if(~g[i][j]) return g[i][j];
    if(!i || !j || (row[i][j] & col[i][j])) return g[i][j] = 0;
    set<ll> s;
    if(!row[i][j]) s.insert(calc(i - 1, j));
    if(!col[i][j]) s.insert(calc(i, j - 1));
    g[i][j] = 0;
    for(auto &v : s) if(g[i][j] == v) ++g[i][j]; else break;
    return g[i][j];
}

void sol(){
    cin >> n;
    lp(i, 1, n) lp(j, 1, n){
        g[i][j] = -1;
        ll tmp;
        cin >> tmp;
        row[i][j] = (tmp + row[i][j - 1]) & 1;
        col[i][j] = (tmp + col[i - 1][j]) & 1;
    }
    cout << (calc(n, n) ? "YES\n" : "NO\n");
}

#define ONLINE_JUDGE
int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    EACHCASE sol();
}