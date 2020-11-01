// /*Hoàng Thái Thụy*/ //
#include <bits/stdc++.h>
#define nmax 501
#define task "TABLE"
#define oo 1e9 + 7
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vct;
int n, m, k, a[nmax][nmax], z[nmax][nmax];
bool avail[1000000009];
int dx[2] = {0, 1};
int dy[2] = {1, 0};
struct edge{
    int U, V, C;
    edge(){}
    edge(int U, int V, int C): U(U), V(V), C(C){}
    edge(const edge &e): U(e.U), V(e.V), C(e.C){}
};
bool cmp(edge a, edge b){
    return a.C < b.C;
}
void BFS(int c, int d, int a, int b){
    cout << 0 << endl;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
        cin >> a[i][j];
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            z[i][j] = max(a[i][j], max(z[i][j - 1], z[i -1][j]));
    for (int i = 1; i <= k; i++){
        int u, v, p, q;
        cin >> u >> v >> p >> q;
        BFS(u, v, p, q);
    }
}
