#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t , n , a[1000] ;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("wc2.inp","r",stdin);
    freopen("wc2.ans","w",stdout);
    cin >> t;
    while (t--)
    {
        cin >> n >> a[1];
        ll x = a[1], ans = 0, ok = 0; 
        if (a[1] > 15) cout << 15 << endl, ok = 1;
        for (int i = 2 ; i <= n ; i++) 
        {
            cin >> a[i] ;
            if (x + 15 < a[i]) ans = x+15;
            else x = a[i];
        }
        if (ok == 0)
        {
            if (ans == 0 && a[n] + 15 >  90) cout << 90 << endl;
            else if (ans == 0 ) cout << a[n]+15 << endl;
            else cout << ans << endl;
        }
    }
}