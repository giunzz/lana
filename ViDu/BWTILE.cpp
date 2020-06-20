#include<bits/stdc++.h>
using namespace std;
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

long long m , n , k , ans ;

int main()
{
    ios_base::sync_with_stdio(0) , cin.tie(0);
    balabalo;
    cin >> m >> n >> k ;
    ans = m*n  ;
    if ( ans )
    cout << ans;
    
}