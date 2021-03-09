#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
#pragma GCC optimize("Ofast")
ll n , w, a[3008], b[3008], l[3008][3008] ={{0}};
using namespace std;
int main()
{
    giuncute;
    freopen("balo1.inp","r",stdin);
    freopen("balo1.out","w",stdout);
    cin >> n >> w;
    for (ll i = 1 ; i <= n ; i++) cin >> a[i] ;
    //for (int i = 1 ; i <= n ; i++) l[0][i] = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= w ; j++)
        {
            if (a[i] > j) l[i][j] = l[i-1][j];
            else l[i][j] = max (l[i - 1][j] , l[i - 1][j - a[i]] + a[i]);
        }
    }
    cout << l[n][w] << endl;
    int i = n , j = w ;
    vector<int> ans;
    while (i != 0 && j != 0 )
    {
        if (a[i] <= j && l[i][j] == l[i-1][j-a[i]] + a[i])  
        {
            ans.push_back(a[i]);
            j = j-a[i] ;
            i--;
        }
        else i--;
    }
    for (int i = ans.size()-1 ; i >= 0 ; i--) cout << ans[i] << " ";
}