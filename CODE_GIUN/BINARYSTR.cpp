#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 1e6 + 7;
const ll oo = 1e18 + 7 ;
using namespace std;
ll t ;
string s;
int main()
{
    giuncute;
    freopen("BINARYSTR.inp","r",stdin);
    freopen("BINARYSTR.out","w",stdout);
    cin >> t ; 
    while (t--)
    {
        cin >> s;
        ll l = INT_MAX , cru = 0 , r = INT_MIN;
        ll ok = 0 ;
        for (ll i = 0 ; i < s.size() ; i++)
        {
            if (s[i] == '1') cru++ , l = min(l , i) , r = max(r , i) , ok = 1;
        }
        if (!ok) cout << -1 << endl;
        else cout << (r - l + 1) - cru << endl;
    }
}