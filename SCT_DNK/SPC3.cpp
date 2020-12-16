#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
using namespace std;
ll n ,  t  , k , a[200008] , cnt[200008] ={0};
int main()
{
    freopen("SPC3.inp","r",stdin);
    freopen("SPC3.out","w",stdout);
    cin >> t;
    while (t--)
    {
        ll ans = 0;
        cnt[0] = 0;
        cin >> n >> k ;
        for (ll i = 1 ; i <= n ; i++)
        {
            cin >> a[i];
            if (a[i] == 0) cnt[i] = cnt[i-1]+1;
            else cnt[i] = cnt[i-1];
          //  cerr << cnt[i] << " ";
        }
        for (ll i = 1 ; i <= n ; i++)
        {
            if(cnt[i] - k <= 0) ans = max(ans, i);
            else ans = max(ans, (i - (lower_bound(cnt, cnt + i + 1, cnt[i] - k) - cnt)) );
        }
        cout << ans << endl;
    }
}