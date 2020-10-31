#include <bits/stdc++.h>
#define forinc(i,a,b) for(int i=a , _b=b ; i<=_b ; ++i)
#define fordec(i,a,b) for(int i=a , _b=b ; i>=_b ; --i)
#define task "LIONDANCE"
#define getbit(x,i) ((x>>i)&1)
#define onbit(x,i) (x|(1<<i))
#define N 4005
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
int n,del,m=0,old[6*N],lim=1;
int a[N],b[N],lef[N],rig[N];
int nxa[N][4*N],nxb[N][4*N];
pair<int,pii> c[4*N];
void up(int i)
{
    int x=c[i].se.se,pos=c[i].se.fi;
    old[lim]=c[i].fi;
    if(pos>n) {b[pos-n]=lim;return;}
    if(!x) a[pos]=lim;
    if(x==1) lef[pos]=lim;
    if(x==2) rig[pos]=lim;
}
void ktao()
{
    sort(c+1,c+m+1);
    up(1);
    forinc(i,2,m)
    {
        if(c[i].fi!=c[i-1].fi) ++lim;
        up(i);
    }
    lef[0]=1;rig[0]=lim;
    fordec(i,n,0)
    {
        forinc(j,1,lim) nxa[i][j]=nxa[i+1][j],nxb[i][j]=nxb[i+1][j];
        nxa[i][a[i+1]]=i+1;
        nxb[i][b[i+1]]=i+1;
    }
}
int f[N][N],pre[N];
bool d[N][N];
int cal(int u,int v)
{
    if(d[u][v]) return f[u][v];
    d[u][v]=true;
    int tg=1,pos=0;
    forinc(i,lef[u],rig[u])
    if(nxa[u][i] && nxb[v][i])
    {
        int val = cal(nxa[u][i],nxb[v][i])+1;
        if(val>=tg) tg=val,pre[u]=nxa[u][i];
    }
    return f[u][v]=tg;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
    read(n); read(del);
    int x;
    forinc(i,1,n)
    {
        read(x);
        c[++m]={x,{i,0}};
        c[++m]={x+del,{i,2}};
        if(x-del>0) c[++m]={x-del,{i,1}};
        else lef[i]=1;
    }
    forinc(i,1,n) {read(x); c[++m]={x,{i+n,0}};}
    ktao();
    cout<<cal(0,0)-1<<"\n";
    int u=0;
    while(pre[u]!=0)
    {
        cout<<old[a[pre[u]]]<<" ";
        u=pre[u];
    }

}
