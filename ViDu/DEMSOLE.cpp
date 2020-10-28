#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
#define ballolo freopen("demsole.inp","r",stdin),freopen("demsole.out","w",stdout);
#pragma GCC optimize("Ofast")
ll n, x  , d = 0;
int main()
{
    giuncute;
    //ballolo;
    cin >> n;
    for (ll i = 1 ; i <= n ; i++)
    {
        cin >> x;
        if (x % 2 != 0) d++;
    }
    cout << d;
}

