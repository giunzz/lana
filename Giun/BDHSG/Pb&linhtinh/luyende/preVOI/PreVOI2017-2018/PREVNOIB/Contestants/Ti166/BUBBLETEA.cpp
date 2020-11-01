#include <bits/stdc++.h>
#define forr(i,a,b) for( int i=(a);i<=(b);++i)
#define ford(i,a,b) for( int i=(a);i>=(b);--i)
#define f first
#define s second
#define ll long long
#define pii pair<int,int>
#define task "BUBBLETEA"

using namespace std;

const long long mod=1e9+7;
const long sun=1e6 ;
int n,k,id[sun],h[sun],dad[sun][20],m=18 ;
ll d[sun] ;
vector<pair<int,ll> > a[sun] ;
pair<int,int> b[sun] ;
bool kt[sun] ;
ll ans ;

int getint()
{
   int ww = 0; char cc = getchar();
   while (cc > '9' || cc < '0') cc = getchar();
   while (cc >= '0' && cc <= '9') { ww = ww * 10 + cc - '0'; cc = getchar(); }
   return ww;
}

ll getll()
{
   ll ww = 0; char cc = getchar();
   while (cc > '9' || cc < '0') cc = getchar();
   while (cc >= '0' && cc <= '9') { ww = ww * 10 + cc - '0'; cc = getchar(); }
   return ww;
}

int getbit(int bit,int id)
{
    return bit>>id&1;
}

void dfs(long u)
{
    for(auto pi:a[u])
    {
        long v=pi.f;
        if (v==dad[u][0]) continue;
        h[v]=h[u]+1;
        d[v]=d[u]+pi.s;
        dad[v][0]=u;
        forr(j,1,m)
            dad[v][j]=dad[dad[v][j-1]][j-1];
        dfs(v);
    }
}

long lca(long u,long v)
{
    if (h[u]<h[v]) swap(u,v);
    long res=h[u]-h[v];
    ford(i,m,0)
    if ((res>>i)&1==1) u=dad[u][i];
    if (u==v) return u;
    ford(i,m,0)
    if (dad[u][i]!=dad[v][i])
    {
        u=dad[u][i];
        v=dad[v][i];
    }
    return dad[u][0];
}

void buffalo()
{
    dfs(1);
    forr(i,1,k) b[i]={-h[id[i]],i};
    sort(b+1,b+k+1);
    forr(i,1,k-1)
    if (i%2==1)
    {
        int u=id[b[i].s];
        int v=id[b[i+1].s];
        int z=lca(u,v);
        ans=max(ans,d[u]+d[v]-2*d[z]);
    }
    cout<< ans;
}

void input()
{
    n=getint();
    k=getint();
    forr(i,1,k)
    {
        id[i]=getint();
    }
    forr(i,1,n-1)
    {
        int u,v;ll z;
        u=getint();
        v=getint();
        z=getll();
        if (k==n) ans=max(ans,z);
        a[u].push_back({v,z});
        a[v].push_back({u,z});
    }
    if (k==n)
    {
        cout<< ans;
    }else buffalo();
}

void output()
{

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    freopen( task".inp" , "r" , stdin );
    freopen( task".out" , "w" , stdout );
    input();
    output();
    return 0;
}
