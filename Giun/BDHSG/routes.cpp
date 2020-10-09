#include<bits/stdc++.h>
#define ll long long
#define cll const ll
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
using namespace std;

void file(const string s){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen((s + ".inp").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

cll maxn = 407;
ll n, m, t[maxn][maxn] = {0}, res[maxn];
vec(ll) d[2][maxn];

inline void init(){
    ll u, v;
    cin >> n >> m;
    lp(i, 1, m){
        cin >> u >> v;
        t[u][v] = 1;
        t[v][u] = 1;
        d[0][u].push_back(v);
        d[0][v].push_back(u);
    }
    lp(i, 1, n){
        lp(j, i + 1, n){
            if(!t[i][j]) {
                d[1][i].push_back(j);
                d[1][j].push_back(i);
            }
        }
    }
}

bool dd[maxn];

ll dj(bool stt){
    memset(dd, 0, sizeof(dd));
    memset(res, 0, sizeof(res));
    queue<ll> q;
    ll u;
    q.push(1);
    dd[1] = 1;
    while(q.size()){
        u = q.front();
        q.pop();
        for(ll v : d[stt][u]){
            if(dd[v]) continue;
            dd[v] = 1;
            res[v] = res[u] + 1;
            q.push(v);
        }
    }
    return res[n];
}

int main(){
    file("routes");
    init();
    cout << max(dj(0), dj(1));
}
