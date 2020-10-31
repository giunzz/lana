#include <bits/stdc++.h>
using namespace std;
const int N=4005;
int n,a[N],b[N],d,tr[2*N],f[2*N],kq,maxx;
vector<int>res,res1;
vector<int>ke[2*N];
void dfs(int u)
{
    for (int i=0; i<ke[u].size(); i++)
    {
        int v=ke[u][i];
        if (u>n && v<=n && v>tr[u] && f[v]<f[u]+1)
        {
            f[v]=f[u]+1;
            tr[v]=u;
            dfs(v);
        }
        if (u<=n && v>n && v>tr[u] && f[v]<f[u])
        {
            f[v]=f[u];
            tr[v]=u;
            dfs(v);
        }
    }
}
void trace()
{
    res1.clear();
    int i=n;
    while (i>=1 && maxx>0)
    {
        while (i>=1 && f[i]!=maxx) i--;
        res1.push_back(i);
        maxx--;
    }
    if (res1.size()>res.size())
    {
        res.clear();
        for (int i=0; i<res1.size(); i++)
            res.push_back(res1[i]);
        return;
    }
    for (int i=0; i<res1.size(); i++)
        if (res1[i]<res[i]) return;
    res.clear();
    for (int i=0; i<res1.size(); i++)
        res.push_back(res1[i]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("liondance.inp","r",stdin);
    freopen("liondance.out","w",stdout);
    cin >> n >> d;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) cin >> b[i];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
        {
            if (a[i]==b[j]) ke[n+j].push_back(i);
            if (abs(a[i]-b[j])<=d) ke[i].push_back(n+j);
        }
    for (int i=1; i<=n; i++)
    {
        for (int u=1; u<=2*n; u++) f[u]=tr[u]=0;
        dfs(n+i);
        maxx=0;
        for (int u=1; u<=n; u++) maxx=max(maxx,f[u]);
        if (maxx>=(int) (res.size()) ) trace();
    }
    cout << res.size() << endl;
    for (int i=res.size()-1; i>=0; i--)
        cout << a[res[i]] << " ";
}
