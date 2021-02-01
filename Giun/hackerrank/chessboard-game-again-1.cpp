#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a> 
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(CASE, read(), 1)
#define Fname "f"
using namespace std;

void openFile(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

inline ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

ll g[17][17], dx[] = {-2, -2, 1, -1}, 
dy[] = {1, -1, -2, -2};

ll dfs(ll x, ll y){
    if(x < 1 or y < 1 or x > 15 or y > 15) return -1;
    if(g[x][y] != -1) return g[x][y];
    vec(ll) s;
    lp(i, 0, 3){
        ll nx = x + dx[i], ny = y + dy[i];
        s.push_back(dfs(nx, ny));
    }
    ll mex = 0;
    while(find(s.begin(), s.end(), mex) != s.end()) 
        ++mex;
    return g[x][y] = mex;
}

void init(){
    memset(g, -1, sizeof(g));
    lp(i, 1, 15) lp(j, 1, 15) 
        if(g[i][j] == -1) dfs(i, j);
}

void sol(){
    ll ans = 0;
    lpd(i, read(), 1) ans ^= read();
    if(ans) cout << "First\n";
    else cout << "Second\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // openFile();
    init();
    lp(i, 1, 15) {
        lp(j, 1, 15) cout << g[i][j] << ' ';
        cout << endl;
    }
   // EACHCASE sol();
}
