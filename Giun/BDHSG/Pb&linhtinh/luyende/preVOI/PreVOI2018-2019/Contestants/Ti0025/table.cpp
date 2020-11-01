#include <bits/stdc++.h>
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define FORD(i,j,k) for(int i=j;i>=k;i--)
#define pii pair<int,int >
#define F first
#define S second
#define mp make_pair
#define maxn 350
#define int long long
using namespace std;
const int oo=1e15+7;
int n,m,k;
int a[maxn][maxn];
int tv[maxn][maxn];
int dd[maxn][maxn];
int ch(int x,int y,int u, int v, int dx, int dy)
{
     int nho=a[dx][dy];
     if(dx==x&&dy==y) return oo;
     if(dx==u&&dy==v) return oo;
     a[dx][dy]=-oo;
     FOR(i,x,u)
     FOR(j,y,v)
     {
         dd[i][j]=max(dd[i-1][j],dd[i][j-1])+a[i][j];
     }
     a[dx][dy]=nho;
     int kq=dd[u][v];
     FOR(i,x,u)
     FOR(j,y,v)
     {
         dd[i][j]=0;
     }
     return kq;
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("table.inp","r",stdin);
    freopen("table.out","w",stdout);
    cin>>m>>n>>k;
    FOR(i,1,m)
    FOR(j,1,n)
    {
        cin>>a[i][j];
    }
    while(k--)
    {
        int x,y,u,v;
        cin>>x>>y>>u>>v;
        int re=oo;
        FOR(i,x,u)
        FOR(j,y,v)
        {
            if(dd[i-1][j]>dd[i][j-1]) dd[i][j]=dd[i-1][j]+a[i][j];
            else {dd[i][j]=dd[i][j-1]+a[i][j]; tv[i][j]=1;}
        }
        int i=u,j=v;
        while(1)
        {
             if(i!=u||j!=v) re=min(re,ch(x,y,u,v,i,j));
            if(tv[i][j]==1)  j--;
            else i--;
            if(i==x&&j==y) break;
        }
        cout<<re<<endl;
    }



}
