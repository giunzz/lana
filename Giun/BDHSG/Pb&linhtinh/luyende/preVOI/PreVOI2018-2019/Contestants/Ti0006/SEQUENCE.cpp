#include <bits/stdc++.h>
#define FOR(i,j,k) for(int i = j; i <= k; i ++)
#define FORD(i,j,k) for(int i = j; i >= k; i --)
#define maxn 3005
using namespace std;
vector < int > res, res1[maxn], res2[maxn];
int n, m, a[maxn], b[maxn], k;
vector < int > F[maxn][maxn], S[maxn][maxn];
bool sosanh(vector < int > x, vector < int > y)
{
    int dd = x.size();
    if(dd == 0)
        return 1;
    for(int i = 0; i < dd; i ++)
    {
        if(x[i] < y[i])
            return 0;
        else if(x[i] > y[i])
            return 1;
    }
    return 0;
}
void solve()
{
    FOR(i,1,n) F[i][1].push_back(a[i]);
    FOR(dd,2,n)
    {
        FOR(i,dd,n)
        {
            F[i][dd] = F[i-1][dd-1];
            FORD(j,i-2,dd-1)
            {
                if(sosanh(F[i][dd], F[j][dd-1]))
                {
                    F[i][dd].clear();
                    F[i][dd] = F[j][dd-1];
                }
            }
            F[i][dd].push_back(a[i]);
            if(i == dd)
                res1[dd] = F[i][dd];
            else if(sosanh(res1[dd], F[i][dd]))
            {
                res1[dd].clear();
                res1[dd] = F[i][dd];
            }
        }
    }
    FOR(i,1,m) S[i][1].push_back(b[i]);
    FOR(dd,2,m)
    {
        FOR(i,dd,m)
        {
            S[i][dd] = S[i-1][dd-1];
            FORD(j,i-2,dd-1)
            {
                if(sosanh(S[i][dd], S[j][dd-1]))
                {
                    S[i][dd].clear();
                    S[i][dd] = S[j][dd-1];
                }
            }
            S[i][dd].push_back(a[i]);
            if(i == dd)
                res2[dd] = S[i][dd];
            else if(sosanh(res2[dd], S[i][dd]))
            {
                res2[dd].clear();
                res2[dd] = S[i][dd];
            }
        }
    }
    FOR(i,1,min(n,k))
    {
        int j = k - i;
        if(j > m)
            continue;
        vector < int > ss;
        int i1 = 0, i2 = 0;
        while(i1 < res1[i].size() && i2 < res2[j].size())
        {
            if(res1[i][i1] > res2[j][i2])
            {
                ss.push_back(res2[j][i2]);
                i2 ++;
            }
            else
            {
                ss.push_back(res1[i][i1]);
                i1 ++;
            }
        }
        while(i1 < res1[i].size())
        {
            ss.push_back(res1[i][i1]);
            i1 ++;
        }
        while(i2 < res2[j].size())
        {
            ss.push_back(res2[j][i2]);
            i2 ++;
        }
        if(sosanh(res, ss))
        {
            res.clear();
            FOR(ii,0,ss.size()-1) res.push_back(ss[ii]);
        }
    }
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("SEQUENCE.inp","r",stdin);
    freopen("SEQUENCE.out","w",stdout);
    cin >> n >> m >> k;
    FOR(i,1,n) cin >> a[i];
    FOR(i,1,m) cin >> b[i];
    solve();
    for(int i = 0; i < res.size(); i ++)
    {
        cout << res[i] << " ";
    }
}
