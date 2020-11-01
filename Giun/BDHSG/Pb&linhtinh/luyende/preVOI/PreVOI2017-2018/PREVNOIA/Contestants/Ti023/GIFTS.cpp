#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int nmax = 2e6 + 50;
ll n,a[nmax],s[nmax],maxx1[nmax],maxx2[nmax],f[nmax],k;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("GIFTS.inp","r",stdin);
    freopen("GIFTS.out","w",stdout);
    cin >> n >> k;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=n;i++)
        s[i] = s[i-1] + a[i];
    for(int i=k;i<=n;i++)
        f[i] = s[i] - s[i-k];
    for(int i=0;i<=n*2;i++)
    {
        maxx1[i] = -1e15 - 50;
        maxx2[i] = -1e15 - 50;
    }
    for(int i=k;i<=n;i++)
        maxx1[i] = max(maxx1[i-1],f[i]);
    for(int i=n;i>=k;i--)
        maxx2[i] = max(maxx2[i+1],f[i]);
    ll kq = 1e15 + 50;
    for(int i=k;i<=n;i++)
    {
        ll t = max(maxx1[i-k],maxx2[i+k]);
        kq = min(kq,t);
    }
    cout << kq;

    return 0;
}
