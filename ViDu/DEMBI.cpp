#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0)
const string tenfile = "DEMBI";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

int n , x, y;

int main()
{
    balabalo;
    giuncute;
    cin >> n ;
    y = ( 2 * n ) / 5;
    x = n - y;
    if ( 2*x == 3*y ) cout << x << " " << y;
    else cout << -1;
    return 0;
}