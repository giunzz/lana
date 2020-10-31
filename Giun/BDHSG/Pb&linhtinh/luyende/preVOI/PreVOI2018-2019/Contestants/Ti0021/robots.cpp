using namespace std;
#include <bits/stdc++.h>

typedef long long ll;
typedef pair<int, int> cp;

#define forinc(i, a, b) for (int i = a; i <= b; i++)
#define fordec(i, a, b) for (int i = a; i >= b; i--)
#define fi first
#define se second
#define LanHT "robots"
#define mp make_pair

const int maxn = 1001, maxm = 2000, base = 1e9 + 7, tx[4] = {0, 0, 1, -1}, ty[4] = {1, -1, 0, 0};
int u, n, cl[maxm + 123][maxm + 123], l[maxm + 123][maxm + 123], xd[maxm + 123][maxm + 123], res = 0;
cp a[10005];

queue<cp> q;
void bfs(){
    forinc(i, 1, u) {
        cl[a[i].fi][a[i].se] = 1;
        q.push(mp(a[i].fi, a[i].se));
    }
    while (!q.empty()){
        int u = q.front().fi, v = q.front().se;
        q.pop();
        forinc(t, 0, 3){
            int i = u + tx[t], j = v + ty[t];
            if (i > 0 && j > 0 && i <= maxm && j <= maxm && !cl[i][j]){
                l[i][j] = l[u][v] + 1;
                q.push(mp(i, j));
                cl[i][j] = 1;
            }
        }
    }
}
int d, c;
queue<cp> p;
void dfs(){
    p.push(mp(d, c)); cl[d][c] = 1;
    res = max(res, l[d][c]);
    while (!p.empty()){
        int u = p.front().fi, v = p.front().se;
        if (xd[u][v] == n) return;
        p.pop();
        forinc(t, 0, 3){
            int i = u + tx[t], j = v + ty[t];
            if (i > 0 && j > 0 && i <= maxm && j <= maxm && !cl[i][j]){
                res = max(res, l[i][j]);
                p.push(mp(i, j));
                cl[i][j] = 1; xd[i][j] = xd[u][v] + 1;
            }
        }
    }
}


void Input(){
    cin >> u >> n;
    forinc(i, 1, u){
        cin >> a[i].fi >> a[i].se;
        a[i].fi += maxn;
        a[i].se += maxn;
    }
    cin >> d >> c;
    d += maxn; c += maxn;
    bfs();
    memset(cl, 0, sizeof(cl));
    dfs();
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen(LanHT".inp", "r", stdin);
    freopen(LanHT".out", "w", stdout);
    Input();
}
