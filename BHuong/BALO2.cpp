#include<bits/stdc++.h>
#define ll long long
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
#pragma GCC optimize("Ofast")
ll n , w, a[1008], b[1008], l[1008][1008] ={{0}};

using namespace std;
int main()
{

    giuncute;
    freopen("balo2.inp","r",stdin);
    freopen("balo2.out","w",stdout);
    cin >> n >> w;
    for (ll i = 1 ; i <= n ; i++) cin >> a[i]  >> b[i];
    for (int i = 1 ; i <= n ; i++) l[0][i] = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= w ; j++)
        {
            if (a[i] > j) l[i][j] = l[i-1][j];
            else l[i][j] = max (l[i - 1][j] , l[i - 1][j - a[i]] + b[i]);
        }
    }   
    cout << l[n][w] << endl;
}