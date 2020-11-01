#include <bits/stdc++.h>

using namespace std;
int m,n,k,a[3000],b[3003],c[6006];
bool f[3000];
string o="";
string o1="";
string s[100];
string s1[100];
void dfs(int u,int k,int v)
{
    if(k==v)
    {
        if(s[v]>o) s[v]=o;
        return;
    }
    for(int i=u;i<=m;i++)
        if(f[i]==true)
        {
            string c=o;
            f[u]=false;
            o=o+(char)(a[i]+48);
            dfs(i+1,k+1,v);
            f[u]=true;
            o=c;
        }
}
void dfs1(int u,int k,int v)
{
    if(k==v)
    {
        if(s1[v]>o1) s1[v]=o1;
        return;
    }
    for(int i=u;i<=n;i++)
        if(f[i]==true)
        {
            string c=o1;
            f[u]=false;
            o1=o1+(char)(b[i]+48);
            dfs1(i+1,k+1,v);
            f[u]=true;
            o1=c;
        }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("SEQUENCE.INP","r",stdin);
    freopen("SEQUENCE.OUT","w",stdout);
    cin >> m >> n >> k;
    for(int i=1;i<=m;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    for(int i=1;i<=m;i++)
    {
        for(int i=1;i<=m;i++) f[i]=true;
        s[i]="9";
        dfs(1,0,i);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) f[j]=true;
        s1[i]="9";
        dfs1(1,0,i);
    }
    string kq="a";
    for(int i=m;i>=1;i--)
    {
        string c="";
        if(s[i].length()+s1[k-i].length()==k)
        {
            for(int j=0;j<i;j++) c=c+s[i][j];
            for(int j=0;j<k-i;j++) c=c+s1[k-i][j];
            if(c<kq) kq=c;
        }
    }
    for(int i=0;i<k;i++) cout << kq[i]<<" ";
    return 0;
}
