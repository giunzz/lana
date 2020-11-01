#include <bits/stdc++.h>

using namespace std;

const int maxn=311;
const long long oo=1e18+11;

int n, m, k, u, v, p, q, banr, banc;
long long a[maxn][maxn], res, dp[maxn][maxn];

long long slv(int i, int j)
{
    if (i>p || j>q) return -oo;
    if (i==banr && j==banc) return -oo;
    if (i==p && j==q) return a[p][q];
    if (dp[i][j]!=-1) return dp[i][j];
    long long cur;
    cur=max(slv(i, j+1)+a[i][j], slv(i+1, j)+a[i][j]);
    return dp[i][j]=cur;
}

int main()
{
    freopen("TABLE.INP", "r", stdin);
    freopen("TABLE.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin>>a[i][j];
    while (k--)
    {
        cin>>u>>v>>p>>q;
        res=oo;
        for (int i=u; i<=p; i++)
            for (int j=v; j<=q; j++)
            {
                if (i==u && j==v) continue;
                if (i==p && j==q) continue;
                banr=i; banc=j;
                memset(dp, -1, sizeof(dp));
                res=min(res, slv(u, v));
            }
        cout<<res<<"\n";
    }
    return 0;
}
