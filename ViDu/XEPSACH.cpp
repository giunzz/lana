#include<bits/stdc++.h>
using namespace std;
const string tenfile = "XEPSACH";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
int n , a[300005] ;
int main()
{
    balabalo;
    giuncute;
    cin >> n ;
    int s = n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i] ;
    for (int i = n ; i >= 1 ; i--) if ( a[i] == s ) s--;
    cout << s;
    return 0;

}
