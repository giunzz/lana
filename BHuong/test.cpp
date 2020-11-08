#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
#pragma GCC optimize("Ofast")
ll n , w, a[100000], b[100000], l[108][(int) 1e5+7] ={0};
int main()
{
    giuncute;
    cin >> n >> w;
    for (ll i = 1 ; i <= n ; i++) cin >> a[i] >> b[i];
    for (int i = 1 ; i <= n ; i++) l[0][i] = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= w ; j++)
        {
            if (a[i] > j) l[i][j] = l[i-1][j];
            else l[i][j] = max (l[i - 1][j] , l[i - 1][j  - a[i]]+b[i]);
        }
    }
    cout << l[n][w];
}