#include<bits/stdc++.h>
using namespace std;

int n , a[(int) 1e6+9] , d[(int) 1e7+7]={0} , ans = 0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("dannhan.inp","r",stdin);
    freopen("dannhan.out","w",stdout);
    cin >> n ;
    for (int i =1 ; i <= n ; i++) 
    {
        cin >> a[i] ;
        d[a[i]]++ ;
        if (d[a[i]] > 1) ans++;
    }
    cout << ans;
}