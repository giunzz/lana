#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

#define sqr(x) ((x) * (x))
#define llint long long

using namespace std;

const int MAXN  =   5000 + 10;
int n, arr[MAXN], F[MAXN][MAXN];
vector< int > adj[MAXN];

void Read()
{
    cin>> n;
    FOR(i, 1, n) cin>> arr[i];
    int u, v;
    FOR(i, 1, n - 1){
        cin>> u >> v;
        adj[u].push_back(v);
    }
}
void direct(int u)
{   //cout<< u <<'\n';
    if (adj[u].size() < 1){
        F[u][0] = arr[u];
        F[u][1] = abs(arr[u] - 1);
        return;
    }
    if (adj[u].size() < 2){
        int v = adj[u][0];
        direct(v);
        FOR(i, 0, n)
            F[u][i] = min(F[u][i], F[v][i] + abs(arr[u] - i));
        return;
    }
    int v1 = adj[u][0], v2 = adj[u][1];
    direct(v1);
    direct(v2);

    FOR(i, 1, n){
            FOR(j, 0, i)
                    F[u][i] = min(F[u][i], F[v1][j] + F[v2][i - j]+ abs(i - arr[u ]));
    }
}
int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("Tree.inp","r",stdin);
    freopen("Tree.out","w",stdout);
    Read();

    memset(F, 0x3c, sizeof F);
    int ans = F[0][0];

    direct(1);

    FOR(i, 1, n) ans = min(ans, F[1][i]);
    cout<< ans;
}
