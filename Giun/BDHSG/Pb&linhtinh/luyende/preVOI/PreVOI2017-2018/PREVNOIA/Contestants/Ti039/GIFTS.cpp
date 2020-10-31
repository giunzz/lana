#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int a[1000005],n,k,Log[1000005];
long long f[1000005],rmq[1000005][20];
void Enter()
{
    cin >> n >> k;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=k;i++) f[1]+=a[i];
    for (int i=2;i<=n-k+1;i++) f[i]=f[i-1]-a[i-1]+a[i+k-1];
}
void Init()
{
    for (int i=2;i<=1000000;i++) Log[i]=Log[i/2]+1;
    for (int i=1;i<=n-k+1;i++) rmq[i][0]=f[i];
    for (int i=1;(1<<i)<=n;i++)
    {
        for (int j=1;j+(1<<i)-1<=n;j++)
        {
            rmq[j][i]=max(rmq[j][i-1],rmq[j+(1<<(i-1))][i-1]);
        }
    }
}
long long getmax(int x,int y)
{
    if (x>y) return 0;
    int j=Log[y-x+1];
    return max(rmq[x][j],rmq[y-(1<<j)+1][j]);
}
void Solve()
{
    long long kq=1e18;
    for (int i=1;i<=n-k+1;i++)
    {
        long long res=max(getmax(1,i-k),getmax(i+k,n-k+1));
        kq=min(kq,res);
    }
    cout << kq;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("GIFTS.INP","r",stdin);
    freopen("GIFTS.OUT","w",stdout);
    Enter();
    Init();
    Solve();
}
