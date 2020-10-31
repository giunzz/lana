#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <climits>

using namespace std;
#define int long long
#define uint unsigned long long
#define F1(i,i1,i2) for(int i=i1;i<=i2;i++)
#define F2(i,i1,i2) for(int i=i1;i>=i2;i--)
#define pb push_back
#define NMAX 5003

const int DMAX=(int)LONG_MAX*NMAX;

int n,a[NMAX];
int tong[NMAX],f[NMAX][NMAX];
vector<int> path[NMAX];

int readint()
{
    char c;
    do c=getchar();
    while (c<'0'||c>'9');
    int re=0;
    while (c>='0'&&c<='9')
    {
        re=re*10+c-'0';
        c=getchar();
    }
    return re;
}

void enter()
{
    n=readint();
    F1(i,1,n) a[i]=readint();
    F1(i,1,n-1)
    {
        int x=readint();
        int y=readint();
        path[x].pb(y);
    }
}

void dfs(int u)
{
    if (path[u].empty())
        tong[u]=1;
    else
    F1(i,0,path[u].size()-1)
    {
        int v=path[u][i];
        dfs(v);
        tong[u]+=tong[v];
    }
}

int tinh(int u,int p)
{
    if (p>tong[u] || p<0) return DMAX;
    if (f[u][p]!=-1) return f[u][p];
    if (path[u].empty()) return (abs(a[u]-p));
    int tmp=DMAX;
    if (path[u].size()==1) tmp=tinh(path[u][0],p);
    if (path[u].size()==2)
    {
        int v1=path[u][0];
        int v2=path[u][1];
        if (tong[v1]>tong[v2]) swap(v1,v2);
        F1(i,0,max(tong[v1],p))
        {
            int x1=tinh(v1,i);
            int x2=tinh(v2,p-i);
            tmp=min(tmp,x1+x2);
        }
    }
    tmp+=abs(a[u]-p);
    f[u][p]=tmp;
    return tmp;
}

void solve()
{
    dfs(1);
    F1(i,0,n)
    F1(j,0,n)
        f[i][j]=-1;
    int kq=DMAX;
    F1(i,0,tong[1])
    {
        int x=tinh(1,i);
        kq=min(kq,x);
    }
    cout<<kq;
}

main()
{
    ios::sync_with_stdio(0);
    freopen("tree.inp","r",stdin);
    freopen("tree.out","w",stdout);
    enter();
    solve();
}
