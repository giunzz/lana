#include <bits/stdc++.h>
#define mn 105
#define int long long
using namespace std;
int n,m,k,a[mn],b[mn];
vector<int> f[mn][mn][3];
vector<int> x,y;
vector<int> res;
int ii;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("sequence.inp","r",stdin);
    freopen("sequence.out","w",stdout);
    cin>>m>>n>>k;
    for(int i=1;i<=m;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    for(int t=1;t<=k;t++)
    {
        ii=1-ii;
        for(int i=1;i<=min(m,t);i++)
        {
            f[i][0][0].clear();
            f[i][0][1].clear();
            for(int j=1;j<=i;j++)
            {
            f[i][0][0].push_back(a[j]);
            f[i][0][1].push_back(a[j]);
            }
        }
        for(int i=1;i<=min(n,t);i++)
        {
            f[0][i][0].clear();
            f[0][i][1].clear();
            for(int j=1;j<=i;j++)
            {

            f[0][i][0].push_back(b[j]);
            f[0][i][1].push_back(b[j]);
            }
        }
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
        if(i+j==t)
        {
            x=f[i-1][j][1-ii];
            x.push_back(a[i]);
            y=f[i][j-1][1-ii];
            y.push_back(b[j]);
            f[i][j][ii]=min(x,y);
        }
    }
    res.resize(k);
    for(int i=0;i<k;i++)
        res[i]=100000;
     for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        if(i+j==k)
        res=min(f[i][j][ii],res);
    for(auto i:res)
        cout<<i<<" ";
    return 0;
}
