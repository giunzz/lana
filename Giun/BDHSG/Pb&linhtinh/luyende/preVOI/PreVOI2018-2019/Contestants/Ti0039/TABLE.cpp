//TNA
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define nmax 350
#define mmax 100005
#define oo 1000000007
#define pii pair<int, int>
#define ll long long
#define Task "TABLE"

using namespace std;
typedef pair<pii, int> piii;
int m, n, c[nmax][nmax], k, u, v, p, q, d[nmax][nmax], cnt = 0, dmax, kq;
bool avail[nmax][nmax];
pii tr[nmax][nmax], a[mmax];

void query(){
    cnt = 0;
    pii t = tr[p][q];
    while(t != MP(u, v)){
        a[++cnt] = t;
        t = tr[t.F][t.S];
    }
}

int dx[10] = {0, 1};
int dy[10] = {1, 0};
void DFS(pii s, int d){
    if(s == MP(p, q)){
        if(d > dmax){
            query();
            dmax = d;
        }
        return;
    }
    for(int i = 0; i < 2; i++){
        int x = s.F + dx[i], y = s.S + dy[i];
        if(x <= p && y <= q){
            tr[x][y] = s;
            DFS({x, y}, d + c[x][y]);
        }
    }
}

void DFS2(pii s, int d){
    if(s == MP(p, q)){
        dmax = max(dmax, d);
        return;
    }
    for(int i = 0; i < 2; i++){
        int x = s.F + dx[i], y = s.S + dy[i];
        if(x <= p && y <= q && !avail[x][y]) DFS2({x, y}, d + c[x][y]);
    }
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> m >> n >> k;
    for(int i = 1;i <= m; i++)
        for(int j = 1;j <= n; j++)
        cin >> c[i][j];
    while(k--){
        cin >> u >> v >> p >> q;
        dmax = 0; kq = 2e9;
        DFS({u, v}, c[u][v]);
        for(int i = 1;i <= cnt; i++){
            int x = a[i].F, y = a[i].S;
            avail[x][y] = 1;
            dmax = 0;
            DFS2({u, v}, c[u][v]);
            kq = min(kq, dmax);
            avail[x][y] = 0;
        }
        cout << kq << '\n';
    }
    return 0;
}
