#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
#define ballolo freopen("giun.inp","r",stdin) , freopen("giun.inp","r",stdin) ; 

bool check (ll x)
{
    if (x < 2) return false;
    else
    {
        for (int i = 2 ; i*i <= x ; i++)
        {
            if (x % i == 0) return false;
        }
    return true;
    }
}
ll n ;
int main()
{
    giuncute;
    ballolo;
    cin >> n;
    ll k = n ;
    while ( kt(k) == false) k++;
    cout << k;
    return 0;
}

