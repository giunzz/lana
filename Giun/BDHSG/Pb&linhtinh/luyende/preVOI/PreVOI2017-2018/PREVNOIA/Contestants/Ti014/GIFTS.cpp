#include <bits/stdc++.h>
#define ft first
#define sd second
#define maxn 1000006
#define mod
#define PI 3.14159265
#define MP make_pair
#define PB push_back
#define heap priority_queue
#define Bjerg "GIFTS"
using namespace std;
long long sum[maxn],matr[maxn],masau[maxn];
long n,k;
long long ans=100000000000009;
void nhap()
{
    cin >> n >> k;
    long x;
    for(long i=1;i<=n;++i)cin >> x, sum[i]=sum[i-1]+x;
    for(long i=k;i<=n;++i)
    {
        matr[i]=max(matr[i-1],sum[i]-sum[i-k]);
    }
    for(long i=n-k+1;i>=1;--i)
    {
        masau[i]=max(masau[i+1],sum[i+k-1]-sum[i-1]);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(Bjerg".inp","r",stdin);
    freopen(Bjerg".out","w",stdout);
    nhap();
    for(long i=k;i<=n;++i)
    {
        ans=min(ans,max(matr[i-k],masau[i+1]));
    }
    cout << ans;
    return 0;
}
