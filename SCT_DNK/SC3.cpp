#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
using namespace std;
ll n ,  t  , k , a[200008] , cnt[200008] ={0};
int main()
{
    freopen("SC3.inp","r",stdin);
    freopen("SC3.out","w",stdout);
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
            cerr << cnt[i] << " ";
        }
        cerr << endl;
        for (ll i = 1 ; i <= n ; i++)
        {
            cerr << cnt[i] << " ";
            ll x = cnt[i]-k ;
            if (x <= 0) ans = max(ans,i);
            else 
            {
                ll l = 1 , r = i , vt ;
                while (l <= r)
                {
 //                   cerr << 1 << endl;
                    ll mid = (l+r)/2;
                    if (x == cnt[mid] )
                    {
                        vt = mid;
                        cerr << endl <<  ans << " ";
                        break;
                    }
                    if (cnt[mid] > x) r = mid - 1;
                    if (cnt[mid] > x) l = mid + 1;
                }
            }
        }
        cerr << endl;   
        cout << ans << endl;
    }
}