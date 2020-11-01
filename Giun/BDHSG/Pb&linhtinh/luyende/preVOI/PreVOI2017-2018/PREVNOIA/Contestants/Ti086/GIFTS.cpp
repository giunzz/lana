#include<bits/stdc++.h>
using namespace std;
#define NAME "GIFTS"
const int maxn = 1e6 + 5;
int a[maxn];
long long f[maxn];
long long IT[4*maxn];
int n,k;
long long tmp;
long long ans = 1e18;

void io()
{
    freopen(NAME".inp","r",stdin);
    freopen(NAME".out","w",stdout);
}

void Update(int id, int l, int r, int i)
{
    if((i < l)||(r < i)) return;
    if((l == r))
    {
        IT[id] = f[i];
        return;
    }
    int m = (l+r)/2;
    Update(id*2,l,m,i);
    Update(id*2+1,m+1,r,i);
    IT[id] = max(IT[id*2],IT[id*2+1]);
}

void Get(int id, int l, int r, int i, int j)
{
    if((l > j)||(r < i)) return;
    if((l >= i)&&(r <= j))
    {
        tmp = max(IT[id],tmp);
        return;
    }
    int m = (l+r)/2;
    Get(id*2,l,m,i,j);
    Get(id*2+1,m+1,r,i,j);
}

void Input()
{
    scanf("%d%d",&n,&k);
    for(int i = 1; i <= n; ++i)
        scanf("%d",&a[i]);
}

void Solve()
{
    for(int i = 1; i <= n; ++i)
    {
        if(i > n - k + 1) break;
        for(int j = i; j <= i + k - 1; ++j)
            f[i] += (long long) a[j];
    }
    for(int i = 1; i <= n - k + 1; ++i)
        Update(1,1,n - k + 1,i);
    //for(int i = 1; i <= 4*n; ++i) cout<<IT[i]<<" ";
    for(int i = 1; i <= n - k + 1; ++i)
    {
        tmp = 0;
        Get(1,1,n - k + 1,1,i - k);
        Get(1,1,n - k + 1,i + k,n - k + 1);
        ans = min(ans,tmp);
    }
    printf("%lld",ans);
}

int main()
{
    io();
    Input();
    Solve();
}
