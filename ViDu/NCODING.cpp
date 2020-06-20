#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0)
const string tenfile = "NCODING ";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
string s ;
int n , k ;
int main()
{
    giuncute;
    balabalo;
    cin >> n >> k ;
    cin >> s;
    for (int i = k ; i < n ; i++ ) cout << s[i];
    for (int i = 0 ; i < k ; i++ ) cout << s[i];
    //s = s.substr(k, n-k  ) + s.substr(0 , k ) ;
    //cout << s;
    return 0;
}