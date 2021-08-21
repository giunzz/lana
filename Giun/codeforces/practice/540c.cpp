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

cll mxn = 503, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
ll n, m, a[mxn][mxn];
bool d[mxn][mxn], ok = 0;
pp(ll, ll) s, t;

void dfs(ll u, ll v){
    lp(i, 0, 3){
        if(a[u + dx[i]][v + dy[i]]){
            a[u + dx[i]][v + dy[i]] = 0;
            dfs(u + dx[i], v + dy[i]);
        }
        if(u + dx[i] == t.first && v + dy[i] == t.second){
            ok = 1;
        }
    }
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m;
    lp(i, 1, n) lp(j, 1, m){
        char c;
        cin >> c;
        a[i][j] = (c == '.');
    }
    cin >> s.first >> s.second >> t.first >> t.second;
    ll cnt = 0;
    lp(i, 0, 3) if(a[t.first + dx[i]][t.second + dy[i]] || (t.first + dx[i] == s.first && t.second + dy[i] == s.second)) ++cnt;
    if(a[t.first][t.second] && cnt < 2){
        cout << "NO";
        return 0;
    }
    d[s.first][s.second] = 1;
    dfs(s.first, s.second);
    if(ok) cout << "YES";
    else cout << "NO";
}