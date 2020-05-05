#include<bits/stdc++.h>
using namespace std;
const string tenfile = "GRID";
const long long mod =  1e9+7;
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
 
long long  n , t ;

int main()
{
    balabalo;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n ;
    t = ( ( ( n *n  % mod ) * ( ( n + 1) * ( n + 1) % mod )) % mod  * 512 ) % mod ;
    cout << t;
    return 0;
}

    

