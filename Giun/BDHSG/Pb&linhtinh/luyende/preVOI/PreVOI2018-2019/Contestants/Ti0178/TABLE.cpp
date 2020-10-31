// ILTH
// PreVnoi 2018 ^^
// 16-12-2018
#include<bits/stdc++.h>

using namespace std;
const int PMTH = 1005;
long long dP[PMTH][PMTH], m, n, k, a[PMTH][PMTH];

int upd(long long &ans, long long val)
{
    ans = min(ans, val);
    return 0;
}

int Tsolve(int u, int v, int p, int q)
{
    vector<pair<int, int> > trace;
    for(int i=u; i<=p; i++)
        for(int j=v; j<=q; j++) dP[i][j] = INT_MIN;
    dP[u][v] = a[u][v];
    for(int i=u+1; i<=p; i++)
        dP[i][v] = dP[i-1][v] + a[i][v];
    for(int j=v+1; j<=q; j++)
        dP[u][j] = dP[u][j-1] + a[u][j];
    for(int i=u+1; i<=p; i++)
        for(int j=v+1; j<=q; j++)
            dP[i][j] = max(dP[i-1][j],dP[i][j-1]) + a[i][j];

    long long i=p, j=q;
    while (i>=u&&j>=v)
    {
        trace.push_back(make_pair(i,j));
        if (dP[i-1][j]==(dP[i][j]-a[i][j])) i--;
        else j--;
    }
    long long ans = LLONG_MAX;
    for(pair<int, int> val : trace)
    {
        if (((val.first==u)&&(val.first==v))||((val.first==p)&&(val.second==q))) continue;
        dP[u][v] = a[u][v];
        for(int i=u+1; i<=p; i++)
        {
            if ((val.first!=i)||(val.second!=v)) dP[i][v] = dP[i-1][v] + a[i][v];
            else dP[i][v] = 0;
        }
        for(int j=v+1; j<=q; j++)
        {
            if ((val.first!=u)||(val.second!=j)) dP[u][j] = dP[u][j-1] + a[u][j];
            else dP[u][j] = 0;
        }
        for(int i=u+1; i<=p; i++)
            for(int j=v+1; j<=q; j++)
            {
                if ((val.first!=i)||(val.second!=j))
                    dP[i][j] = max(dP[i-1][j],dP[i][j-1]) + a[i][j];
                else
                    dP[i][j] = 0;
            }
        upd(ans, dP[p][q]);
    }

    cout << ans << "\n";
    return 0;
}

int Tenter()
{
    int u,v,p,q;
    cin >> m >> n >> k;
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++) cin >> a[i][j];

    while (k--)
    {
        cin >> u >> v >> p >> q;
        Tsolve(u,v,p,q);
    }
}

int main()
{
    freopen("TABLE.INP","r",stdin);
    freopen("TABLE.OUT","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Tenter();

    return 0;
}
