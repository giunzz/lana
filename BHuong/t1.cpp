#include <bits/stdc++.h>
using namespace std;
int n , t , a[(int) 1e5+7] , f[(int) 1e5+7]={0} ;
int main()
{
    ios_base::sync_with_stdio(0) , cin.tie(0);
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> t;
    while (t--)
    {
        cin >> n;
        f[0] = 0;
        int  ans = INT_MIN , ans1 = 0 , mi = 0;
        for (int i = 1 ; i <= n ; i++) 
        {
            cin >> a[i];
            if (a[i]+ans1 >= ans1) ans1 += a[i];
            f[i] = f[i-1] + a[i];
        }
        for (int i = 1 ; i <= n ; i++) 
        {
            ans = max(ans,f[i]-mi);
            mi = min(mi,f[i]);
        }
        if (ans == 0 ) cout << ans1 << " " << ans1 << endl;
        else if (ans1 == 0 ) cout << ans << " " << ans << endl;
        else cout <<  ans  << " " << ans1 << endl;
    }
}