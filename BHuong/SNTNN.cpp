#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
#define ballolo freopen("SNTNN.inp","r",stdin) , freopen("SNTNN.out","w",stdout) ;
#pragma GCC optimize("Ofast")
ll n ;
inline bool checksnt (ll x)
{
    if (x < 2) return false;
    else
    {
        for (ll i = 2 ; i*i <= x ; i++)
        {
        if (x % i == 0) return false;
        }
    }
    return true;
}
int main()
{
    giuncute;
    ballolo;
    cin >> n;
    while ( checksnt(n) == false) n++;
    cout << n;
    return 0;
}

