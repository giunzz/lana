#include<bits/stdc++.h>
using namespace std;
int n , p , a[(int) 1e5+7] , t , d1 = 0, d2= 0, d3 = 0,ans[(int) 1e5+7];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("balls.inp","r",stdin);
    freopen("balls.out","w",stdout);
    cin >> n >> p ;
    for (int i = 1 ;i <= n ; i++) 
    {
        cin >> a[i];
        if (a[i] == 1) d1++;
        else if (a[i] == 2) d2++;
        else if (a[i] == 3) d3++;
        if (d1 == 2) d2++ , d1 = 0;
        if (d2 == 2) d3++, d2 = 0;
        ans[i] = d1+d2+d3;
    } 
    for (int i = 1 ; i <= p ; i++) 
    {
        cin >> t;
        cout << ans[t] << " ";
    }
}

