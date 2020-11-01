#include<bits/stdc++.h>
#define maxn 5005
using namespace std;

int n, a[maxn], c[maxn][maxn], dd[maxn][maxn], k, cmin;
vector<int> P[maxn];

void DFS(int u)
{
    for(int i=0;i<P[u].size();i++)
    {
        int v = P[u][i];
        DFS(v);
        if(P[u].size()==1)
        {
            for(int i=0;i<=k;i++)
            {
                if(dd[v][i])
                {
                    c[u][i] = c[v][i] + fabs( a[u] - i );
                    dd[u][i] = 1;
                }
            }
        }
    }
    //
    if(P[u].size()==0)
    {
        c[u][0] = a[u];
        c[u][1] = fabs(a[u] - 1);
        dd[u][0] = 1;
        dd[u][1] = 1;
    }

    //
    if(P[u].size()==2)
    {
        int x = P[u][0];
        int y = P[u][1];
        for(int i=0;i<=k;i++)
        {
            if(dd[x][i])
            for(int j=0;j<=k;j++)
            {
                if(dd[y][j])
                {
                    if(dd[u][i+j]==0) c[u][i+j] = c[x][i] + c[y][j] + (int)fabs(a[u] - i - j);
                    else c[u][i+j] = min(c[u][i+j], c[x][i] + c[y][j] + (int)fabs(a[u] - i - j));
                    dd[u][i+j]=1;
                }
            }
        }
    }
}

int mu(int k)
{
    if(k==0) return 1;
    int m = mu(k/2);
    if(k%2==0) return m*m;
    else return m*m*2;
}

int main()
{
    freopen("TREE.inp","r",stdin);
    freopen("TREE.out","w",stdout);
    scanf("%d", &n);
    cmin = 1000000009;
    for(int i=1;i<=n;i++) scanf("%d", &a[i]);
    for(int i=1;i<n;i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        P[u].push_back(v);
    }
    k = log2(n);
    k = mu(k+1);
    DFS(1);
    for(int i=0;i<=k;i++)
        if(dd[1][i]) cmin = min(cmin, c[1][i]);
    cout << cmin;
}
