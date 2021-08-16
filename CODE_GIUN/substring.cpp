#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 4e5 + 7;
using namespace std;

ll n , k , cnt[30] = {0} , tmp = 1 , ans = 0;
string s ;

ll STN(char c)
{
    return c - 'a';
}

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> k ;
    cin >> s;
    cnt[STN(s[0])] = 1;
    ll right = 0 ;
    for (int left = 0 ; left < s.size() ; left++)
    {
        while(right < (int) s.size() - 1 && ((!cnt[STN(s[right + 1])] && tmp + 1 <= k) || cnt[STN(s[right + 1])]))  
        {
            if (cnt[STN(s[++right])]) tmp += 0;
            else tmp += 1;
            cnt[STN(s[right])]++;
        }
        if (tmp == k) ans = max (ans , right - left + 1);
        if (right == s.size() - 1) break;
        while(tmp == k) 
        {
            if (cnt[STN(s[++left])]) tmp -= 0;
            else tmp -= 1;
            cnt[STN(s[left])]--;
        }
        left--;
    }
    cout << ans;
}
