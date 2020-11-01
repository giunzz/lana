//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define Rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define For(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define maxn 305
#define MOD 1000000007
#define MaxC 1000000007ll
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define ll long long
#define Task "table"

using namespace std;

typedef int arr2int[maxn][maxn];
typedef ll arr2ll[maxn][maxn];

arr2int a, top, bot;
int m, n;

long long Solve(int u, int v, int p, int q){
    ll res = MaxC;
    for (int i = u; i <= p; i++) for (int j = v; j <= q; j++) top[i][j] = bot[i][j] = -MaxC;
    top[u][v] = a[u][v];
    for (int i = u; i <= p; i++)
        for (int j = v; j <= q; j++)
        {
            if (i > u) MAX(top[i][j], top[i-1][j] + a[i][j]);
            if (j > v) MAX(top[i][j], top[i][j-1] + a[i][j]);
        }
    bot[p][q] = a[p][q];
    for (int i = p; i >= u; i--)
        for (int j = q; j >= v; j--)
        {
            if (i < p) MAX(bot[i][j], bot[i+1][j] + a[i][j]);
            if (j < q) MAX(bot[i][j], bot[i][j+1] + a[i][j]);
        }

    for(int sum = u+v+1; sum < p+q; sum++){
        ll nhat = -MaxC, nhi = -MaxC;
        for (int i = u; i <= p; i++){
            int j = sum - i;
            if (j < v || j > q) continue;
            ll cur = top[i][j] + bot[i][j] - a[i][j];
            if (cur > nhat) {nhi = nhat; nhat = cur;}
                else if (cur > nhi) nhi = cur;
        }
        res = min(res, nhi);
    }
    return res;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    int ntest;
    cin >> m >> n >> ntest;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    while (ntest--){
        int u, v, p, q;
        cin >> u >> v >> p >> q;
        cout << Solve(u,v,p,q) << endl;
    }
    return 0;
}

