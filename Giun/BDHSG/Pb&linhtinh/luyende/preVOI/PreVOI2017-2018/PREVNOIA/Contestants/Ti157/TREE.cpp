#include <bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define ii pair<int, int>
#define mod 1e9+7;
#define HANH "TREE"
using namespace std;
const int MOD=2e9;
int n, a[5005], s[5005][5005], d[5005], u, v, maxx[5005];
vector <int> f[5005], con[5005];
void dfs(int h)
{
    d[h]=1;
    if(f[h].size()==1)
    {
        s[h][0]=a[h];
        s[h][1]=abs(a[h]-1);
        maxx[h]=1;
        return;
    }
    for(int i=0; i<f[h].size(); ++i)
    {
        int k=f[h][i];
        if(!d[k])
        {
            con[h].push_back(k);
            dfs(k);
        }
    }
    if(con[h].size()==1)
    {
        int h1=con[h][0];
        maxx[h]=maxx[h1];
        for(int i=0; i<=maxx[h]; ++i) s[h][i]=s[h1][i]+abs(a[h]-i);
        return;
    }
    int h1=con[h][0];
    int h2=con[h][1];
    maxx[h]=maxx[h1]+maxx[h2];
    for(int i=0; i<=maxx[h]; ++i)
    {
        for(int j=0; j<=i; ++j)
            s[h][i]=min(s[h][i], s[h1][j]+s[h2][i-j]+abs(a[h]-i));
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    freopen(HANH".inp", "r", stdin);
    freopen(HANH".out", "w", stdout);
    cin >>n;
    for(int i=1; i<=n; ++i) cin >>a[i];
    for(int i=1; i<n; ++i)
    {
        cin >>u >>v;
        f[u].push_back(v);
        f[v].push_back(u);
    }
    memset(s, 60, sizeof(s));
    dfs(1);
    int kq=MOD;
    for(int i=0; i<=maxx[1]; ++i) if(s[1][i]>=0) kq=min(kq, s[1][i]);
    cout <<kq;
}
