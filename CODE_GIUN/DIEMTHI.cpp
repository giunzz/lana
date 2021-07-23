#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
const ll oo = 1e9 + 7;
ll s , k , n , f[25][207] , a[25][25];
using namespace std;
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> s >> k >> n;
    for (ll j = 0 ; j < n; j++) 
        for (ll i = 0 ; i < k ; i++ ) cin >> a[i][j];

    for (ll j = 0 ; j < n; j++)
    {
        for (ll i = 0 ; i < k ; i++ ) cerr << a[i][j] << " ";
    cerr << endl;
    }
    for (int i = 0 ; i <= k ; i++)
    {
        for (int j = 0 ; j <= s ; j++)
        if ( i == 0 && j == 0) f[i][j] = 0 ;
        else if (i == 0 || j == 0) f[i][j] = oo;
        else 
        {
            f[i][j] = oo;
            for (int x = 0 ; x < n ; x++) 
            if( a[i-1][x] < f[i][j] && a[i-1][x] <= j && f[i-1][j-a[i-1][x]] <= a[i-1][x] ) f[i][j] = a[i-1][x];
        }
    }
    if (f[k][s] == oo) cout << "NO";
    else 
    {
        stack <ll> ans;
        while (s != 0)
        {
            ans.push(f[k][s]);
            s -= f[k--][s];
        }
        cout << "YES" << endl;
        while (!ans.empty()) cout << ans.top() << " " , ans.pop();
    }
}
