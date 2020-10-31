#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int m, n ,k;
int a[1000][1000],u[1000],v[1000],p[1000],q[1000];
long long mini , dp [1000][1000];
void repath (long long u , long long v,long long p, long long q)
{
    dp[u][v]=0;
    for (int i=u; i<=p; i++)
    {
        for (int j =v; j <= q ; j++)
        {
            if (j == v)
            {
                if (i > u)
                {
                dp [i][j] = dp[i-1][j] + a[i][j];
                }
                else dp[i][j] =a[i][j];
            }
            else
                if (i== u )
            {
                 if (j > v)
                {
                dp [i][j] = dp[i][j-1] + a[i][j];
                }
                else dp[i][j] =a[i][j];
            }
            else
            {
                if (dp[i-1][j] > dp[i][j-1])
                {
                    dp [i][j] = dp [i-1][j]+ a[i][j];
                }
                else
                {
                    dp[i][j] = dp[i][j-1] + a[i][j];
                }
            }

        }
    }
}
void tryy (int u,int v ,int p ,int q)
{
    int t; mini =10000000;
    for (int i = u; i <= p ; i++)
    {
        for (int j =v; j <= q ; j++)
        {
            if (i != u || j != v )
            if (i !=p || j !=q)
            {
                t =a[i][j];
                a[i][j] = -1000000;
                repath(u,v,p,q);
                mini = min (dp[p][q],mini);
                a[i][j] = t;
            }
        }
    }
    cout << mini<<endl ;
}
int main()
{
    freopen ("table.inp","r",stdin);
    freopen ("table.out","w",stdout);
    cin >> m >> n >> k;
    for (int i=1; i <= m ; i++)
        for (int j = 1 ; j <= n ;j++ )
    {
         cin >> a[i][j];
    }
    for (int i=1 ; i <= k ; i++)
    {
         cin >> u[i] >> v[i] >> p[i] >>q[i];
         tryy (u[i],v[i],p[i],q[i]);
    }
    return 0;
}
