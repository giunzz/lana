#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll  k, n ;
ll gt (ll x)
{
    ll a = 1;
    for (int  i = 1 ; i <= x ; i++) a*=i;
    return a;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("chank.inp","r",stdin);
    freopen("chank.out","w",stdout);
    cin >> n >> k ;
    cout << gt(n) / gt(n-k) ;
}
