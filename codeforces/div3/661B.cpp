#include<bits/stdc++.h>
using namespace std;
long long t , n , a[1000] , b[1000];
int main()
{ 
    ios_base::sync_with_stdio(0);cin.tie(0);
//    freopen("giun.inp","r",stdin);freopen("giun.out","w",stdout);
    cin >> t;
    while (t--)
    {
        cin >> n;
        long long  ma = INT64_MAX, mb = INT64_MAX, ans = 0;
        for (int i = 1 ; i <= n ; i++) cin >> a[i] , ma = min(ma,a[i]);
        for (int i = 1 ; i <= n ; i++) cin >> b[i] , mb = min(mb,b[i]);
        // tle
        /*int i = 1;
        while (i <= n)
        {
            if (ma < a[i] && mb < b[i]) a[i]-- , b[i]-- , ans++  ;
            else if (ma < a[i]) a[i]-- , ans++;
            else if (mb < b[i]) b[i] -- , ans++;
            if( a[i] == ma && b[i] == mb ) i++;
        }*/
        for (int i = 1; i <= n; ++i)
        {
			ans += max(a[i] - ma, b[i] - mb);
		}
        cout << ans << endl;
    }
}

