#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
const int nmax=5005;
struct data{int gt,c,child[3],s;} a[nmax];
int m=0,id[nmax],x[33];
ll res=LLONG_MAX;


ll calc(int i)
{
    if (a[i].c==0)
    {
        a[i].s=x[id[i]];
        return a[i].s;
    }
    a[i].s=0;
    for (int j=1;j<=a[i].c;j++)
        a[i].s+=calc(a[i].child[j]);
    return a[i].s;
}
void xuli()
{
    calc(1);
    ll ans=0;
    for (int i=1;i<=n;i++)
        ans+=abs(a[i].gt-a[i].s);
    res=min(res,ans);
}
void Try(int i)
{
    for (int j=0;j<=1;j++)
    {
        x[i]=j;
        if (i==m) xuli();
        else if (i<m) Try(i+1);
    }
}
void sub1()
{
    for (int i=1;i<=n;i++) if (a[i].c==0) id[i]=++m;
    Try(1);
    cout<<res;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("tree.inp","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i].gt;
    for (int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        a[u].c++;
        a[u].child[a[u].c]=v;
    }
    sub1();
    return 0;
}
