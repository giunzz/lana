#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 4e5 + 7;
using namespace std;

ll n , k , cnt[maxn] = {0} , tmp = 0 , ans = 0;
string s ;
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> k ;
    cin >> s;
    ll l = 0 ;
    for (int r = 0 ; r < (int)s.size() ; r++)
    {
        if (cnt[(int)s[r]] == 0)  tmp++ ;
        cnt[(int)s[r]]++;
        while (tmp > k)
        {
            if (cnt[(int)s[l]] == 1)  --tmp;
            cnt[(int)s[l]]--;
            l++;
        }
        if (tmp == k) ans = max(ans , r-l+1);
        //cerr << l << " " << r << " " << ans << endl;
    }
    cout << ans;
}
