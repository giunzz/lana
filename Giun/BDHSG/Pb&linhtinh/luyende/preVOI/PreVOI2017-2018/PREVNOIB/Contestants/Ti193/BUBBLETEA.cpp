#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int n,k;
int a[50001],tr[50001];
vector<ii> g[50001];
int ans,db;
void khoitao()
{
    freopen("BUBBLETEA.INP","r",stdin);
    freopen("BUBBLETEA.OUT","w",stdout);
}
void dong()
{
    fclose(stdin);
    fclose(stdout);
}
void nhap()
{
    cin>>n>>k;
    db=-1;
    int p1,p2,p3;
    for(int i=1;i<=k;i++)
    cin>>a[i];
    for(int i=1;i<=n-1;i++)
    {
        cin>>p1>>p2>>p3;
        g[p1].push_back(ii(p3,p2));
        g[p2].push_back(ii(p3,p1));
        db=max(db,p3);
    }
}
void dfs(int  u)
{
    tr[u]=1;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i].second;
        if(tr[v]!=1) {ans=max(ans,g[u][i].first);dfs(v);}
    }
}
void xuli()
{
    int p1;
    ans=-1;
    int dem=0;
    if(k==n)
    {
        ans=-1;
        for(int i=1;i<=n;i++)
            if(g[i].size()==1)
        {
           p1=i;
           dem++;
        }
        if(dem>2) {cout<<-1;return;}
        else
        {
           cout<<db;
           return;
        }

    }
    else cout<<-1;
}
int main()
{
    khoitao();
    nhap();
    xuli();
    dong();
}
