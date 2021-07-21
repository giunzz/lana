#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
const ll maxn = 3e3 +  7;
ll t , n , a[maxn][maxn];
using namespace std;

bool check (ll a[maxn][maxn] , ll h , ll c )
{
    ll s = 0 ;
    if (h < 1 || c < 1) return false;
    for (int j = 1 ; j <= h ; j++) s += a[c][j];
    if (s % 2 == 0) return true;
    else 
    {
        s = 0;
        for (int i = 1 ; i <= c ;i++) s+= a[i][h];
        if (s % 2 == 0) return true;
    }
    return false;
}
int main()
{
    giuncute;
    freopen("AC4.inp" , "r",stdin);
    freopen("AC4.out", "w" ,stdout);
    cin >> t;
    while(t--)
    {
        cin >> n ;
        for (int i = 1 ; i <= 4 ; i++)
            for (int j = 1 ; j <= 4 ; j++) cin >> a[i][j];
        ll p = 1 , c = 4 , h = 4;
        while (check(a , h , c) == true )
        {
            if (p == 1) p = 2;
            else p = 1;
            ll s = 0 ;
            for (int j = 1 ; j <= h ; j++) s += a[c][j];
            if (s % 2 == 0) c--;
            else 
            {
                s = 0;
                for (int i = 1 ; i <= c ;i++) s+= a[i][h];
                if (s % 2 == 0) h--;
            }
        }
        if (p == 1) cout << "Dau" << endl;
        else cout << "Bun" << endl;
    }
}