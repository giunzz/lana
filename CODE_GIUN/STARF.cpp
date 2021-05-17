#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
#pragma GCC optimize("Ofast")
ll n , w, a[(int) (1e4+7) ], b[(int) (1e4+7)], l[(int)(1e4+7)][(int) (1e4+7)] ={{0}};

using namespace std;
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> w;
    for (ll i = 1 ; i <= n ; i++) cin >> a[i];
    for (ll i = 1 ; i <= w ; i++) cin >> b[i]
    for (ll i = 1 ; i <= w ; i++)
        if (i > a[1]) l[1][i] = b[1];
        else l[1][i] = 0;
    for (ll i = 1 ; i <= n ; i++)
    {
        for (ll j = 1 ; j <= w ; j++)
        {
            if (a[i] > j) l[i][j] = l[i-1][j];
            else l[i][j] = max (l[i - 1][j] , l[i - 1][j - a[i]] + b[i]);
        }
    }  
    cout << l[n][w] << endl;
}
