#include<stdio.h>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
ll n , m ;
int  main()
{
    freopen("SQUARE.inp","r",stdin);
    freopen("SQUARE.out","w",stdout);
    ios_base::sync_with_stdio(0) , cin.tie(0);
    cin >> n >> m ;
    ll l = 1 , r = 1 , cnt = 0 , x = 0 , y = 0 , cnt1 = 1;
    for (ll i = 1 ; i <= 2*n  ; i++)
    {
        if (i <= n) x = i , y = 1;
        else x = n , y = ++cnt1;
        if (l <= m && m <= r) break;
        l = r + 1, r = l + ( i < n ? ++cnt: -- cnt);
    }
    for (ll i = l ; i <= r ; i++)
    {
        if (i == m) 
        {
            cout << x << " " << y ;
            return 0;
        }
        else x-- , y++;
    }
}
