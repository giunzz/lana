#include<bits/stdc++.h>

using namespace std;

int  n, a [(int) 1e6+8] , t = 1 , ans = 1;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("daytang.inp","r",stdin);
    freopen("daytang.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    
    for (int i = 2 ; i <= n ; i++)
    {
        if (a[i] >= a[i-1]) t++;
        else t = 1 ;
        ans = max(ans,t);
    }
    cout << ans;
    return 0;
}