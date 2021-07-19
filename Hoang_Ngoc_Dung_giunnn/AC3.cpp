#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
const ll maxn = 100;
ll n , a[maxn][maxn] , t;
using namespace std;

int main()
{
    giuncute;
    freopen("AC3.inp" , "r",stdin);
    freopen("AC3.out", "w" ,stdout);
    cin >> t;
    while (t--)
    {
        for (int i = 1 ; i <= 3 ; i++)
            for (int j = 1 ; j <= 3 ; j++) a[i][j] = 0 ;
        ll ans = 0 , dem = 0 ;
        for (int i = 1 ; i <= 3 ; i++)
        {
            for (int j = 1 ; j <= 3 ; j++)
                if (i == 2 && j == 2) continue;
                else cin >> a[i][j];
        }
        if (a[1][1] + a[1][3] == 2*a[1][2]) dem++;
        if (a[1][1] + a[3][1] == 2*a[2][1]) dem++;
        if (a[3][3] + a[1][3] == 2*a[2][3]) dem++;
        if (a[3][3] + a[3][1] == 2*a[3][2]) dem++;
        for (int k = -10 ; k <= 10 ; k++)
        {
            ll ma = 0 ;
            a[2][2] = k;
            if (a[1][1] + a[3][3] == 2*a[2][2]) ma++;
            if (a[1][3] + a[3][1] == 2*a[2][2]) ma++;
            if (a[1][2] + a[3][2] == 2*a[2][2]) ma++;
            if (a[2][1] + a[2][3] == 2*a[2][2]) ma++;
            ans = max(ans ,dem + ma );
        }
        cout << ans  << endl;
    }
}