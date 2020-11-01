#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    char c;
    int res,neg=1;
    c=getchar();
    if(c=='-') {neg=-1;c=getchar();}
    res=c-'0';
    for(c=getchar();c>='0' && c<='9';c=getchar()) res=res*10+c-'0';
    return neg*res;
}
void write(int x)
{
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int m,n,k;
int a[310][310],f[310][310];
int xuli(int x,int y,int u,int v,int r,int t)
{
    int i,j;
    memset(f,0,sizeof f);
    for(i=x;i<=u;i++)
    for(j=y;j<=v;j++)
    {
        if(i==r && j==t) continue;
        f[i][j]=a[i][j]+max(f[i-1][j],f[i][j-1]);
    }
    if(f[u][v]!=0) return f[u][v];
    return 1e9;
}
int main()
{
    #define file "table"
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int i,j,t,x,y,u,v,res;
    cin>>m>>n>>k;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++) cin>>a[i][j];
    for(t=1;t<=k;t++)
    {
        res=1e9;
        cin>>x>>y>>u>>v;
        for(i=x;i<=u;i++)
            for(j=y;j<=v;j++) res=min(res,xuli(x,y,u,v,i,j));
        cout<<res<<endl;
    }
    return 0;
}
