#include <bits/stdc++.h>
#define forinc(i,a,b) for(int i=a , _b=b ; i<=_b ; ++i)
#define fordec(i,a,b) for(int i=a , _b=b ; i>=_b ; --i)
#define task "SEQUENCE"
#define getbit(x,i) ((x>>i)&1)
#define onbit(x,i) (x|(1<<i))
#define N 3005
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
int n,m,k,lim=0,old[N];
int a[N],b[N];
int sa[N][N],sb[N][N];
int dd[N],mx,val=0;
pii f[2*N];
void up(int u)
{
    old[lim]=f[u].fi;
    int pos=f[u].se;
    if(pos<=n) a[pos]=lim;else b[pos-n]=lim;
}
void ktao()
{
    sort(f+1,f+n+m+1);
    forinc(i,1,n+m)
    {
        if(f[i].fi!=f[i-1].fi) ++lim;
        up(i);
    }
    fordec(i,n,1)
    {
        ++dd[a[i]];
        forinc(j,1,lim) sa[i][j]=sa[i][j+1];
        ++sa[i][a[i+1]];
    }
    fordec(i,m,1)
    {
        ++dd[b[i]];
        forinc(j,1,lim) sb[i][j]=sb[i][j+1];
        ++sb[i][b[i+1]];
    }
    forinc(i,1,lim)
    {
        if(val+dd[i]==k)
        {
            mx=i+1;
            val=0; break;
        }
        if(val+dd[i]>k)
        {
            val=k-val;
            mx=i; break;
        }
        val+=dd[i];
    }
}
void xuli()
{
    int u=1,v=1;
    while(u<=n && v<=m)
    {
        if(a[u]>mx) { ++u;continue;}
        if(b[v]>mx) { ++v;continue;}
        if(a[u]<b[v]) { cout<<old[a[u++]]<<" "; continue;}
        if(b[v]<a[u]) { cout<<old[b[v++]]<<" "; continue;}
        if(sa[u][mx]+sb[v-1][mx]>=val) { ++u; continue;}
        else {cout<<old[a[u++]]<<" ";--val; continue;}
        if(sa[u-1][mx]+sb[v][mx]>=val) { ++v; continue;}
        else { cout<<old[b[v++]]<<" ";--val; continue;}
    }
    while(u<=n)
    {
        if(a[u]>mx) {++u; continue;}
        if(a[u]<mx) { cout<<old[a[u++]]<<" "; continue;}
        if(sa[u][mx]>=val) { ++u; continue;}
        else {cout<<old[mx]<<" "; ++u; --val; continue;}
    }
    while(v<=m)
    {
        if(b[v]>mx) {++v; continue;}
        if(b[v]<mx) { cout<<old[b[v++]]<<" "; continue;}
        if(sb[v][mx]>=val) { ++v; continue;}
        else {cout<<old[mx]<<" "; ++v; --val; continue;}
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
    read(n); read(m); read(k);
    int x;
    forinc(i,1,n) read(x),f[i]={x,i};
    forinc(i,1,m) read(x),f[n+i]={x,i+n};
    ktao();
    xuli();

}
