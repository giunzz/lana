#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pd pair<double,double>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 4e5 + 7;
using namespace std;

ll a[maxn],G = 1,F , n ;
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) cin >> a[i] , G *= a[i];
    F = (a[1] * a[2] )/__gcd(a[1] , a[2]);
    for(int i = 3; i <= n; i++) F = (F * a[i])/__gcd(F,a[i]);    
    if (G / F > 0 ) cout << G/F;
    else cout << "impossible";
}