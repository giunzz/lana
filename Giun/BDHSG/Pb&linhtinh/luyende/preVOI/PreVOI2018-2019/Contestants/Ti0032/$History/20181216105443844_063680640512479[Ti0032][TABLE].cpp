//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 105
#define pb push_back
#define oo 100000000000007
#define int long long
#define DoNothing "TABLE"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int m, n, k, a[mn][mn], f[mn][mn], F[mn][mn][mn][mn];



void DOIT()
{
    memset(F, -40);

    forr(i, 1, m)
        forr(j, 1, n)
            F[i][j][i- 1][j]= F[i][j][i][j- 1]= 0;

    forr(i, 1, m)
        forr(j, 1, n)
        {
            forr(u, i, m)
            forr(v, j, n)
                F[i][j][u][v]= max(F[i][j][u- 1][v], F[i][j][u][v- 1])+ a[u][v];
        }
    while(k--)
    {
        int u, v, p, q, res= oo;
        cin>> u>> v>> p>> q;
        forr(i, u, p)
            forr(j, v, q)
            {
                if((i== u&& j== v)|| (i== p&& j== q)) continue;
                int ans= -oo;
                forr(_i, 1, i- 1)
                    ans= max(ans, F[u][v][_i][j+ 1]+ F[_i][j+ 1][p][q]- a[_i][j+ 1]);
                forr(_i, i, j- 1)
                    ans= max(ans, F[u][v][i+ 1][_i]+ F[i+ 1][_i][p][q]- a[i+ 1][_i]);
                res= min(res, ans);
            }
        cout<< res<< "\n";
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> m>> n>> k;

    forr(i, 1, m)
    forr(j, 1, n)
    cin>> a[i][j];

    DOIT();

    return 0;
}
