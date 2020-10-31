#include<bits/stdc++.h>
using namespace std;
#define fi(i,x,y) for(int i=x; i<=y; ++i)
#define fd(i,x,y) for(int i=x; i>=y; --i)
#define N 85
#define M 35

typedef long long ll;
int m,n,k,u,v,p,q,o,l;
const ll inf = 1000000000000000000;
ll a[N][N],f[N][N],fa[N][N];
ll ans,Mp;

void io()
{
    freopen("TABLE.inp", "r", stdin);
    freopen("TABLE.out", "w", stdout);
}

void Solve(int o,int l)
{
    fi(i,u,p)
        fi(j,v,q) f[i][j] = -inf;
    f[u][v] = a[u][v];
    fi(i,u,p)
    {
        fi(j,v,q)
        {
            if (i <= p) f[i+1][j] = max(f[i+1][j],f[i][j]+a[i+1][j]);
            if (i+1 == o && j == l) f[i+1][l] = -inf;
            if (j <= q) f[i][j+1] = max(f[i][j+1],f[i][j]+a[i][j+1]);
            if (i == o && j+1 == l) f[i][j+1] = -inf;
        }
    }
    ans = min(ans,f[p][q]);
}

void Sub1()
{
    ans = inf;
    Solve(1,1);
    fi(i,u,p)
        fi(j,v,q)
        {
            if (i == u && j == v) continue;
            if (i == p && j == q) continue;
            Solve(i,j);
        }
    cout << ans << endl;
}

void Sub2()
{
    int id1=u,id2=v;
    ll P = -inf;
    ans = inf;
    fi(i,u,p)
    {
        fi(j,v,q)
        {
            if (i == u && j == v) continue;
            if (i == p && j == q) continue;
            if (P < a[i][j])
            {
                P = a[i][j];
                id1 = i; id2 = j;
            }
        }
    }
    Solve(id1,id2);
    cout << ans << endl;
}

int main()
{
    io();
    cin >> m >> n >> k;
    fi(i,1,m)
        fi(j,1,n) scanf("%lld",&a[i][j]);
    fi(i,1,m)
    {
        fi(j,1,n)
        {
            if (i < m) fa[i+1][j] = max(fa[i][j]+a[i+1][j],fa[i+1][j]);
            if (j < n) fa[i][j+1] = max(fa[i][j]+a[i][j+1],fa[i][j+1]);
        }
    }
    if (m <= 30 && n <= 30 && k <= 30)
    {
    fi(i,1,k)
    {
        scanf("%d%d%d%d",&u,&v,&p,&q);
        Sub1();
    }
    }
    fi(i,1,k)
    {
        scanf("%d%d%d%d",&u,&v,&p,&q);
        Sub2();
    }
}
