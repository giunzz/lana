#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
ll n , w, a[1008], b[1008], l[1008][1008] ={{0}};
using namespace std;
int main()
{

    giuncute;
    freopen("CAYKHE.inp","r",stdin);
    freopen("CAYKHE.out","w",stdout);
    cin >> n >> w;
    for (ll i = 1 ; i <= n ; i++) cin >> a[i]  >> b[i];
    for (int i = 1 ; i <= n ; i++) l[0][i] = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= w ; j++)
        {
            if (b[i] > j) l[i][j] = l[i-1][j];
            else l[i][j] = max (l[i - 1][j] , l[i - 1][j - b[i]] + a[i]);
        }
    }
    vector<ll> vt;
    cout << l[n][w] << endl;
    ll i = n , j = w , d = 0;
    while ( i >= 1 && j >= 1)
    {
        if (l[i][j] == l[i-1][j-b[i]] + a[i]) vt.push_back(i) , j=j-b[i], i-- , d++;
        else  i--;
    }
    cout << d << " ";
    for (int i = vt.size()-1 ; i >= 0 ; i--) cout << vt[i] << " ";
}