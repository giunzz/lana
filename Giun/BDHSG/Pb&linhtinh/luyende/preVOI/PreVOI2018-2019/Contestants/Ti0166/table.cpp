#include <bits/stdc++.h>
#define fto(i,a,b) for(int i=a; i<=b; ++i)
#define fdto(i,a,b) for(int i=a; i>=b; --i)
#define pb push_back
#define ll long long
#define maxn 301
#define st first
#define nd second
#define pii pair<int,int>
#define Tshiro "table"

using namespace std;

void read(int &n)
{
    n=0;
    int ch=getchar(), sign=1;
    while (ch<'0' || ch>'9')
    {
        if (ch=='-') sign=-1;
        ch=getchar();
    }
    while (ch>='0' && ch<='9')
    {
        n=n*10+ch-'0';
        ch=getchar();
    }
    n*=sign;
}

const int oo = 1e9+7;

int m, n, k;
int a[maxn][maxn];
int b[maxn][maxn];
int tx[2]={0,1};
int ty[2]={1,0};
int u, v, p, q, s, t;
int minn;

int bfs(int x1,int y1)
{
    fto(i,1,m)
    fto(j,1,n) b[i][j]=0;
    fto(i,u,p)
    fto(j,v,q)
    {
        if (i-1==x1 && j==y1)
        {
            if (i!=0 && j-1!=0) b[i][j]=b[i][j-1]+a[i][j];
        }
        else if (i==x1 && j-1==y1)
        {
            if (i-1!=0 && j!=0) b[i][j]=b[i-1][j]+a[i][j];
        }
        else b[i][j]=max(b[i-1][j]+a[i][j],b[i][j-1]+a[i][j]);
    }
    return b[p][q];
}

void sub1()
{
    while(k--)
    {
        minn=1e9;
        read(u);read(v);read(p);read(q);
        fto(j,u,p)
        fto(z,v,q)
        if ((j==u && z==v) || (j==p && z==q)) continue;
        else minn=min(minn,bfs(j,z));
        cout << minn << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen(Tshiro".inp", "r", stdin);
    freopen(Tshiro".out", "w", stdout);
    read(m);read(n);read(k);
    fto(i,1,m)
    fto(j,1,n)
        read(a[i][j]);
    sub1();
    return 0;
}
