#include <bits/stdc++.h>
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
using namespace std;
int n , x[(int) 3e6+7] , ans = 0 ;
int main()
{
    giuncute;
    freopen("book.inp","r",stdin);
    freopen("book.out","w",stdout);
    cin >> n;
    int v = n ;
    for (int i = 1 ; i <= n ; i++) cin >> x[i];
    for (int i = n ; i >= 1 ; i--)
    {
        if (x[i] == v) ans++ , v--;
    }
    cout << n-ans;
}
