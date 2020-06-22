#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n , a[(int) 1e6+3] , k , s = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("giun.inp","r",stdin); freopen("giun.out","w",stdout);
    freopen("BTMAX.INP", "r", stdin);
    freopen("BTMAX.OUT", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n ; i++) cin >> a[i];
    sort ( a + 1 , a + 1 + n);
    for (int i = 1 ; i <= k  ; i++) s -= a[i];
    for (int i = k + 1 ; i <= n ; i++ ) s += a[i];
    cout << s ;
    return 0;
}
