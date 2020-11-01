#include <bits/stdc++.h>

using namespace std;
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Ford(i,a,b) fot(int i=a;i>=b;i--)
#define ii pair<int,int>
#define f first
#define s second
#define pb push_back
#define ll long long
#define TASK "TABLE"
const ll oo = 1e16+7 ;
const int N = 300+7 ;
int m,n,k ;
int a[N][N] ;
int u,v,p,q ;
ll f[N][N],maxn = oo ;
ii trace[N][N] ;
void Input()
{
    cin >> m >> n >> k ;
    For(i,1,m)
        For(j,1,n)
            cin >> a[i][j] ;
    return ;
}
ll calculate(int x,int y)
{
    ll cal[N][N] ;
    cal[x-1][y]=cal[x][y-1]=0 ;
    for(int i=x;i<=p;i++)
        for(int j=y;j<=q;j++)
            cal[i][j] = max(cal[i-1][j],cal[i][j-1])+a[i][j] ;
    return cal[p][q] ;
}
void Process()
{
    vector<ii> g ;
    int s = p ;
    int t =q ;
    while(s!=u || t!=v)
    {
        int i = s,j=t ;
        s= trace[i][j].f ;
        t= trace[i][j].s ;
        if(s !=u || t!=v )
        g.pb({s,t}) ;
    }
    ll save = -1 ;
    int c = trace[u][v].f ;
    int d = trace[u][v].s ;
    for(int i=0;i<g.size();i++)
    {
        s= g[i].f ;
        t= g[i].s ;
        save = a[s][t] ;
        a[s][t] = -oo ;
        maxn=min(maxn,calculate(u,v)) ;
        a[s][t]=save ;
    }
    cout << maxn << "\n" ;
}
void sub1()
{
    For(i,1,k)
    {
        cin >> u >> v >> p >> q ;
        f[u-1][v]=f[u][v-1]=0 ;
            For(i,1,m)
            {
                For(j,1,n)
                {
                    if(f[i-1][j] > f[i][j-1]){
                        f[i][j] = f[i-1][j]+a[i][j] ;
                        trace[i][j] = {i-1,j} ;
                }
                else{
                    f[i][j] = f[i][j-1]+a[i][j] ;
                    trace[i][j] = {i,j-1} ;
                    }
                }
            }
            Process() ;
    }
}
int main()
{
    freopen(TASK".INP","r",stdin) ;
    freopen(TASK".OUT","w",stdout) ;
    ios_base::sync_with_stdio(0) ;
    cin.tie(NULL) ;
    Input() ;
    sub1() ;
    return 0;
}
