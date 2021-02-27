#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0)
const string tenfile = "NCODING";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
string s ;
int n , k ;
int main()
{
    giuncute;
    balabalo;
    cin >> n >> k ;
    cin >> s;
    k = k % n;
    s = s.substr(n-k, k) + s.substr(0 , n-k ) ;
    cout << s;
    return 0;
}