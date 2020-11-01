#include<bits/stdc++.h>
using namespace std;
const int maxn = 4005;

int n;
int delta;
int L[maxn];
int R[maxn];
int f[maxn][maxn];
typedef pair<int,int> ii;
ii trace[maxn][maxn];
int maxdis = 1;
int id,idy;
int ans[maxn];
int cnt = 0;


void io()
{
    freopen("LIONDANCE.INP","r",stdin);
    freopen("LIONDANCE.OUT","w",stdout);
}

void Enter()
{
    scanf("%d%d",&n,&delta);
    for(int i=1; i<=n; ++i)
        scanf("%d",&L[i]);
    for(int i=1; i<=n; ++i)
        scanf("%d",&R[i]);
}


void Solve()
{
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
    {
        if(L[i] == R[j])
            f[i][j] = 1;
        trace[i][j] = ii(0,0);
    }
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
    {
        if(L[i] != R[j]) continue;
        for(int k = i-1; k>=1; --k)
            for(int h = j-1; h>=1; --h)
        {
            if(L[k] != R[h]) continue;
            if(abs(L[k] - L[i]) <= delta)
            {
                if(f[k][h] + 1 > f[i][j])
                {
                    f[i][j] = f[k][h] + 1;
                    trace[i][j] = ii(k,h);
                }
                if(f[k][h] + 1 == f[i][j])
                {
                    if(L[k] > L[trace[i][j].first])
                    {
                        trace[i][j] = ii(k,h);
                    }
                }
            }
        }
       // cout<<i<<" "<<j<<" "<<trace[i][j].first<<" "<<trace[i][j].second<<" "<<f[i][j]<<endl;
    }
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
        {
            if(f[i][j] > maxdis)
            {
                maxdis = f[i][j];
                id = i;
                idy = j;
            }
        }
    int k  = id;
    int h = idy;
    cout<<maxdis<<endl;
    while(trace[id][idy].first != 0 && trace[id][idy].second != 0)
    {
        ans[++cnt] = L[id];
        k = trace[id][idy].first;
        h = trace[id][idy].second;
        id = k;
        idy = h;
    }
    ans[++cnt] = L[id];
    for(int i=cnt; i>=1; --i)
        printf("%d ",ans[i]);
}

int main()
{
    io();
    Enter();
    Solve();
}
