#include<bits/stdc++.h>
#define ll long long
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
#pragma GCC optimize("Ofast")
ll n , w, a[1000], b[1000], l[108][(int) 1e5+7] ={0};

using namespace std;
int main()
{

    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> w;
    for (ll i = 1 ; i <= n ; i++) cin >> a[i] ;
    for (int i = 1 ; i <= n ; i++) l[0][i] = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= w ; j++)
        {
            if (a[i] > j) l[i][j] = l[i-1][j];
            else l[i][j] = max (l[i - 1][j] , l[i - 1][j - a[i]] + a[i]);
        }
    }
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= w ; j++)
        {
            cerr << l[i][j] << " ";
        }
        cerr << endl;
    }
    
    cout << l[n][w] << endl;
    int i = n , j = w , c[2005]={0};
    do
    {
        if (a[i] > j) i--;
        while (l[i][j] == l[i-1][j])i--;
        c[i] = 1;
        j -= a[i] , i--;
    }
    while (i >= 0 && j >= 0)
    for (int i = 1 ; i <= n ; i++)
    {
        if (c[i] == 1) cout << 
    }
        
        if (l[i][j] ==  l[i - 1][j - a[i]] + a[i] ) 
        {
            cerr << l[i][j] << " " << l[i-1][j-a[i]] << endl;
            cout << a[i] << " " ;
            i-- , j = j - a[i];
        }
        else i--;
    }   

}