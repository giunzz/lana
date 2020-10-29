#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
#define ballolo freopen("SIEUNTO.inp","r",stdin) , freopen("SIEUNTO.out","w",stdout) ;
#pragma GCC optimize("Ofast")
ll n , x;

bool checksnt (ll n)
{
    if (n < 2) return false;
    else
    {
        for (int i = 2 ; i*i <= n ; i++)
        {
        if (n % i == 0) return false;
        }
    return true;
    }
}

bool check (ll k)
{
    while (k != 0)
    {
        if (checksnt(k) == true) k/=10;
        else return false;
    }
 //   cerr << endl;
    return true;
}
int main()
{
    giuncute;
    ballolo;
    cin >> n ;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> x;
        if (check(x) == true) cout << 1;
        else cout << 0;
    }
}

