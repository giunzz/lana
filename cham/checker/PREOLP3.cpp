#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
#pragma GCC optimize("Ofast")
ll n , m, v[1008], w[1008], l[1008][1008]  ,t; 
using namespace std;
int main()
{

    giuncute;
    freopen("preolp3.INP","r",stdin);
    freopen("preolp3.OUT","w",stdout);
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (ll i = 1 ; i <= n ; i++) cin >> v[i]  >> w[i];
        for (int i = 0 ; i <= n ; i++) 
            for (int j = 0 ; j <= m ; j++) l[i][j] = 0;
        for (int i = 1 ; i <= n ; i++)
        {
            for (int j = 1 ; j <= m ; j++)
            {
                if (w[i] > j) l[i][j] = l[i-1][j];
                else if (i >= 2 ) l[i][j] = max (l[i - 1][j] , l[i - 2][j - w[i]] + v[i]);
                else l[i][j] = max(l[i][j],v[1]);
            }
        }
        cout << l[n][m] << endl;
    }   
}