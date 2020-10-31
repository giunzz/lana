#include<bits/stdc++.h>
#define For(i,a,b) for(int i =a;i<=b;i++)
#define Forr(i,a,b) for(int i = a;i>=b;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define maxn 305
#define INF 1e18
#define ll long long
#define Bit(x,i) ((x>>i) & 1)
using namespace std;

int m,n,k;
long long a[maxn][maxn],f[305][305];

void Io()
{
    freopen("TABLE.INP","r",stdin);
    freopen("TABLE.OUT","w",stdout);
}

void Read()
{
    scanf("%d%d%d",&m,&n,&k);
    For(i,1,m)
        For(j,1,n)
            scanf("%d",&a[i][j]);
}

ll solvesub1(int u,int v,int p,int q,int x,int y)
{
    For(i,u-1,p+1)
        For(j,v-1,q+1) f[i][j] = -INF;

    if(x == u && y == v) f[u][v] = 0;
    else f[u][v] = a[u][v];
    For(i,u,p)
        For(j,v,q){
            if(i == x && j == y) continue;
            if(i-1 >= u) f[i][j] = max(f[i][j],f[i-1][j] + a[i][j]);
            if(j-1 >= v)f[i][j] = max(f[i][j],f[i][j-1] + a[i][j]);
        }
    if(p == x && q == y) f[p][q] = max(f[p-1][q],f[p][q-1]);
    return f[p][q];
}

void Subtask1()
{
    For(g,1,k){
        int u,v,p,q;
        scanf("%d%d%d%d",&u,&v,&p,&q);
        ll ans = solvesub1(u,v,p,q,p+1,q+1);
        For(i,u,p){
            if((p-u)*(q-v) >=10000) break;
            For(j,v,q){
                if(i == u && j == v) continue;
                if(i == p && j == q) continue;
                ans = min(ans,solvesub1(u,v,p,q,i,j));
                //cerr<<i<<' '<<j<<' '<<ans<<endl;
            }
        }
        printf("%lld\n",ans);
    }
}

void Solve()
{
    Subtask1();
}

int main()
{
    Io();
    Read();
    Solve();
}
