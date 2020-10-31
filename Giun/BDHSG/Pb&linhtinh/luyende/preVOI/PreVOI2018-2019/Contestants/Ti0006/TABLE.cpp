#include <bits/stdc++.h>
#define FOR(i,j,k) for(int i = j; i <= k; i ++)
#define maxn 1005
using namespace std;
int n, m, k;
long long a[maxn][maxn];
long long F[maxn][maxn];
long long F1[maxn][maxn], F2[maxn][maxn];
long long run(int x, int y, int u, int v, int p, int q)
{
    F[u-1][v-1] = 0;
    FOR(i,u,p) F[i][v-1] = 0;
    FOR(i,v,q) F[u-1][i] = 0;
    FOR(i,u,p)
    {
        FOR(j,v,q)
        {
            if(i == x && j == y) continue;
            else if(i-1 == x && j == y) F[i][j] = F[i][j-1] + a[i][j];
            else if(i == x && j-1 == y) F[i][j] = F[i-1][j] + a[i][j];
            else F[i][j] = max(F[i-1][j], F[i][j-1]) + a[i][j];
        }
    }
    return F[p][q];
}
void sub1()
{
    long long sum = 0;
    FOR(i,1,n)
    {
        FOR(j,1,m)
        {
            cin >> a[i][j];
            sum += a[i][j];
        }
    }
    FOR(i,1,k)
    {
        int u, v, p, q;
        long long res = sum + 1000000000;
        cin >> u >> v >> p >> q;
        FOR(x,u,p)
        {
            FOR(y,v,q)
            {
                if(x == p && y == q) continue;
                if(x == u && y == v) continue;
                res = min(res, run(x,y,u,v,p,q));
            }
        }
        cout << res << "\n";
    }
}
void sub2()
{
    FOR(i,1,n)
    {
        FOR(j,1,m)
        {
            cin >> a[i][j];
        }
    }
    FOR(i,1,k)
    {
        int u, v, p, q;
        cin >> u >> v >> p >> q;
        F1[u-1][v-1] = 0;
        F2[u-1][v-1] = 0;
        FOR(i,u,p)
        {
             F1[i][v-1] = 0;
             F2[i][v-1] = 0;
        }
        FOR(i,v,q)
        {
            F1[u-1][i] = 0;
            F2[u-1][i] = 0;
        }
        FOR(i,u,p)
        {
            FOR(j,v,q)
            {
                F1[i][j] = max(F1[i-1][j], F1[i][j-1]) + a[i][j];
                if(i >= u+1 && j >= v+1) F2[i][j] = max(min(F2[i-1][j], F2[i][j-1]),F1[i-1][j-1] + min(a[i-1][j], a[i][j-1])) + a[i][j];
            }
        }
        cout << F2[p][q] << "\n";
    }
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("TABLE.inp","r",stdin);
    freopen("TABLE.out","w",stdout);
    cin >> n >> m >> k;
    if(n <= 30 && m <= 30 && k <= 30)
    {
        sub1();
    }
    else
    {
        sub2();
    }
}
