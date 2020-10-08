#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
#define ballolo freopen("bai1.inp","r",stdin),freopen("bai1.out","w",stdout);
ll n ;
bool kt(ll x)
{
    if (x < 2) return false;
    for (ll i = 2 ; i*i <= x ; i++)
    {
        if ( x % i == 0) return false;
    }
    return true;
}
int main()
{
    giuncute;
    ballolo;
    cin >> n;
    if (kt(n) == true) cout << "YES";
    else cout << "NO";
} 