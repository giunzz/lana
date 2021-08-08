#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
using namespace std;

ll n ; 

ll count1(ll u)
{
    return u == 0 ? 0 : count1(u >> 1) + (u & 1);
}

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    ll t = count1(n);
    cout << (ll) pow(2LL , t);
    return 0;
}