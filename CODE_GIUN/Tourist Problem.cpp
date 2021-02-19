#include <bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long 

ll n , a[(int)2e5+7]  , s1 = 0 , s2 = 0 , kq = 0;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n ; i++) cin >> a[i],s1 += a[i];
    for (int i = 1 ; i <= n ; i++)
    {
        s2 += a[i]*(i-1)-kq;
        kq += a[i];
    }
    ll sum = s1+ s2*2, uc = __gcd(sum,n);
    sum /= uc;
    n /= uc;
    cout << sum << " " << n ;
}