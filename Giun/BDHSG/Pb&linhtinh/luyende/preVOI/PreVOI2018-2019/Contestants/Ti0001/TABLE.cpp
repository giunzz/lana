#include <bits/stdc++.h>
#define forinc(i,a,b) for(int i=a , _b=b ; i<=_b ; ++i)
#define task "TABLE"
#define getbit(x,i) ((x>>i)&1)
#define onbit(x,i) (x|(1<<i))
#define N 305
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
using namespace std;
void read(int &X)
{
    X=0;
    char ch=getchar();
    bool w=false;
    while(ch<'0' || ch>'9')
    {
        if(ch=='-') w=true;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
    {
        //cout<<X<<" ";
        X=X*10+ch-'0';
        ch=getchar();
    }
    if(w) X=-X;
}
int n,m,a[N][N],k;
int c[2]={0,1};
int d[2]={1,0};
int u,v,p,q,tg;
void duyet(int x,int y,int g,int h,int val)
{
    if(x!=g || y!=h) val+=a[x][y];
    if(x==p && y==q) { tg=max(tg,val); return;}
    forinc(i,0,1)
    {
        int x_=x+c[i], y_=y+d[i];
        if(x_<=p && y_<=q) duyet(x_,y_,g,h,val);
    }
}
bool kt(int i,int j)
{
    if(i==u && j==v) return false;
    if(i==p && j==q) return false;
    return true;
}
void xuli()
{
    int res=2e9;
    read(u); read(v); read(p); read(q);
    forinc(i,u,p) forinc(j,v,q) if(kt(i,j))
    {
        tg=0;
        duyet(u,v,i,j,0);
        res=min(res,tg);
    }
    cout<<res<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
    read(m); read(n); read(k);
    forinc(i,1,m) forinc(j,1,n) read(a[i][j]);
    while(k--) xuli();
}
