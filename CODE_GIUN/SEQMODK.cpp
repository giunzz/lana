#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
const ll maxn = 500007;
ll n , a[maxn] , ans = 0  , k , vt = 0  ,b[maxn];
using namespace std;
int main()
{
    giuncute;
    freopen("giun.inp" , "r",stdin);
    freopen("giun.out", "w" ,stdout);
    cin >> n >> k ;
    for (int i = 1 ; i <= n ;i++) cin >> a[i] , b[i] = b[i-1] + a[i];
    cerr << b[10];
    int i = 1 , j = n ;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
            if ((b[j] - b[i-1]) % k == 0 ) 
                if (j - i + 1 > ans) ans = j - i + 1 , vt = i;
    }
    // for (int i = 1 ; i <= n ; i++)
    // {
    //     if (b[i] % k == 0) 
    //     {
    //         if (i > ans) ans = i , vt = 1;
    //     }
    //     else 
    //     {
    //         for (int j = 2 ; j < i ; j++)
    //         {
    //             if ( (b[i] - a[j]) % k == 0 )
    //             {
    //                 if (i - j + 1 > ans) ans = i-j + 1 , vt = j;
    //                 continue;
    //             }
    //             else b[i] -= a[j];
    //         }
    //     }
    // }
    cout << ans << " " << vt << endl;
} 
