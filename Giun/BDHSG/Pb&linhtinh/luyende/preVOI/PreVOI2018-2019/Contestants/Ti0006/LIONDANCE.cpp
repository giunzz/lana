#include <bits/stdc++.h>
#define FOR(i,j,k) for(int i = j; i <= k; i ++)
#define FORD(i,j,k) for(int i = j; i >= k; i --)
#define maxn 4005
#define mp make_pair
#define f first
#define s second
using namespace std;
int a[maxn], b[maxn], n, t;
int F[maxn][maxn];
int c[maxn], dem = 0;
int S[maxn], d[maxn][maxn];
pair < int, int > truy[maxn][maxn];
pair < int, int > truyres;
int res;
int u, v;
void BFS(int val)
{
    queue < pair<int, int > > qu;
    qu.push(mp(u,v));
    while(qu.size())
    {
        int x = qu.front().f;
        int y = qu.front().s;
        qu.pop();
        if(F[x-1][y] == val && d[x-1][y] == 0)
        {
            d[x-1][y] = 1;
            qu.push(mp(x-1,y));
        }
        if(F[x][y-1] == val && d[x][y-1] == 0)
        {
            d[x][y-1] = 1;
            qu.push(mp(x,y-1));
        }
        if(F[x-1][y-1] == val-1 && F[x-1][y] == val-1 && F[x][y-1] == val-1)
        {
            if(S[val] < a[x] && abs(a[x] - S[val+1]) <= t || val == F[n][n])
            {
                S[val] = a[x];
                u = x-1;
                v = y-1;
            }
        }
    }
}
void sub12()
{
    FOR(i,1,n)
    {
        FOR(j,1,n)
        {
            if(a[i] == b[j])
            {
                FORD(x,i-1,0)
            {
                FORD(y,j-1,0)
                {
                    if(a[x] == b[y] && abs(a[x] - a[i]) <= t)
                    {
                        if(F[i][j] < F[x][y] + 1)
                        {
                            F[i][j] = F[x][y] + 1;
                            truy[i][j] = mp(x,y);
                        }
                        else if(F[i][j] == F[x][y]+1)
                        {
                            if(a[truy[i][j].f] < a[x])
                            {
                                F[i][j] = F[x][y] + 1;
                                truy[i][j] = mp(x,y);
                            }
                        }
                    }
                }
            }
            }
            if(res < F[i][j])
            {
                res = F[i][j];
                truyres = mp(i,j);
            }
        }
    }
    int x = truyres.f;
    int y = truyres.s;
    while(truyres != mp(0,0))
    {
        c[++dem] = a[truyres.f];
        truyres = truy[truyres.f][truyres.s];
    }
    cout << dem << "\n";
    FORD(i,dem,1) cout << c[i] << " ";
}
void sub3()
{
    FOR(i,1,n)
    {
        FOR(j,1,n)
        {
            if(a[i] == b[j]) F[i][j] = F[i-1][j-1] + 1;
            else F[i][j] = max(F[i-1][j], F[i][j-1]);
        }
    }
    res = F[n][n];
    u = n;
    v = n;
    while(res)
    {
        BFS(res);
        res --;
    }
    cout << F[n][n] << "\n";
    FOR(i,1,F[n][n]) cout << S[i] << " ";
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("LIONDANCE.inp","r",stdin);
    freopen("LIONDANCE.out","w",stdout);
    cin >> n >> t;
    FOR(i,1,n)
    {
        cin >> a[i];
    }
    FOR(i,1,n)
    {
        cin >> b[i];
    }
    if(n <= 100)
    {
        sub12();
    }
    else
    {
        sub3();
    }
}
