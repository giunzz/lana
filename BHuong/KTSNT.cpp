#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
#define ballolo freopen("giun.inp","r",stdin) , freopen("giun.inp","r",stdin) ; 

bool check (ll n)
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
ll n ;
int main()
{
    ballolo;
    giuncute;
    cin >> n ;
    if (check(n) == true) cout << 1;
    else cout << 0 ;
}