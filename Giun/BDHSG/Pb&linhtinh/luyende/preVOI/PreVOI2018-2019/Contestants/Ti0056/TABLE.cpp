#include<bits/stdc++.h>
#define maxn 35
using namespace std;

typedef long long ll;

int n, m, k, gt[maxn][maxn];
ll F[maxn][maxn];

int main()
{
    freopen("TABLE.inp","r",stdin);
    freopen("TABLE.out","w",stdout);
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> gt[i][j];
        }
    }

    while(k--)
    {
        int u, v, p, q;
        cin >> u >> v >> p >> q;

        for(int i=u;i<=p;i++)
            for(int j=v;j<=q;j++) F[i][j] = -1e12+7;

        ll cmin = 1e12+7;

        for(int i=u;i<=p;i++)
        {
            for(int j=v;j<=q;j++)
            {
                if(i == u && j == v) continue;
                if(i == p && j == q) continue;

                for(int a=u;a<=p;a++)
                {
                    for(int b=v;b<=q;b++)
                    {
                        F[a][b] = -1e12;
                    }
                }

                F[u][v] = gt[u][v];

                for(int a=u;a<=p;a++)
                {
                    for(int b=v;b<=q;b++)
                    {
                        if(a > u && (a-1 != i || b != j)) F[a][b] = max(F[a][b], F[a-1][b] + gt[a][b]);
                        if(b > v && (a != i || b-1 != j)) F[a][b] = max(F[a][b], F[a][b-1] + gt[a][b]);
                    }
                }
                cmin = min(cmin, F[p][q]);

            }
        }
        cout << cmin << endl;
    }
}
