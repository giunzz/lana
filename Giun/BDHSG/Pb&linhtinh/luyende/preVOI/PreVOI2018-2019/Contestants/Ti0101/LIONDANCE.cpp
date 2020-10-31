#include<bits/stdc++.h>
using namespace std;
#define NAME "LIONDANCE"
#define fi first
#define se second
const int maxn = 4e3 + 5;
typedef pair<int,int> ii;
int a[maxn];
int b[maxn];
int d[maxn];
int f[maxn][maxn];
int t[maxn];
int ans[maxn];
int n,delta,k;

void io()
{
    freopen(NAME".inp","r",stdin);
    freopen(NAME".out","w",stdout);
}

void Input()
{
    scanf("%d%d",&n,&delta);
    for(int i = 1; i <= n; ++i) scanf("%d",&a[i]);
    for(int i = 1; i <= n; ++i) scanf("%d",&b[i]);
}

void Work()
{
    for(int i = 1; i <= k; ++i) t[i] = a[d[i]];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= k; ++j) f[i][j] = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(b[i] == t[1]) f[i][1] = 1;
        else f[i][1] = f[i - 1][1];
    }
    for(int i = 1; i <= k; ++i)
    {
        if(b[1] == t[i]) f[1][i] = 1;
        else f[1][i] = f[1][i - 1];
    }
    for(int i = 2; i <= n; ++i)
        for(int j = 2; j <= k; ++j)
        {
            f[i][j] = max(f[i - 1][j],max(f[i][j - 1],f[i - 1][j - 1]));
            if(b[i] == t[j]) f[i][j] = max(f[i][j],f[i - 1][j - 1] + 1);
        }
    if(f[n][k] != k) return;
    else
    {
        for(int i = 2; i <= k; ++i) if(abs(t[i] - t[i - 1]) > delta) return;
        for(int i = 1; i <= k; ++i)
            if(ans[i] < t[i])
            {
                for(int j = 1; j <= k; ++j) ans[j] = t[j];
                return;
            }
        return;
    }
}

void Solve()
{
    for(int i = 1; i <= n; ++i)
    {
        if(a[i] == b[1]) f[i][1] = 1;
        else f[i][1] = f[i - 1][1];
    }
    for(int i = 1; i <= n; ++i)
    {
        if(a[1] == b[i]) f[1][i] = 1;
        else f[1][i] = f[1][i - 1];
    }
    for(int i = 2; i <= n; ++i)
        for(int j = 2; j <= n; ++j)
        {
            f[i][j] = max(f[i - 1][j],max(f[i][j - 1],f[i - 1][j - 1]));
            if(a[i] == b[j]) f[i][j] = max(f[i][j],f[i - 1][j - 1] + 1);
        }
    k = f[n][n];
    long long n_1 = 1;
    long long k_1 = 1;
    long long tmp_1 = 1;
    for(int i = 1; i <= n; ++i)
        n_1 = n_1*i;
    for(int i = 1; i <= k; ++i)
        k_1 = k_1*i;
    for(int i = 1; i <= n-k;++i)
        tmp_1 = tmp_1*i;
    long long tmp = n_1/(k_1*tmp_1);
    for(int i = 1; i <= k; ++i)
        d[i] = i;
    for(int i = 1; i <= tmp; ++i)
    {
        Work();
        for(int j = k; j >= 1; --j)
            if(d[j] != n-k+j)
            {
                d[j]++;
                for(int h = j+1; h <= k; ++h)
                    d[h] = d[h-1] + 1;
                break;
            }
    }
    printf("%d\n",k);
    for(int i = 1; i <= k; ++i) printf("%d ",ans[i]);
}

int main()
{
    io();
    Input();
    Solve();
}
