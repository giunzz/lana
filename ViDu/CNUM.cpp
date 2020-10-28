#include<bits/stdc++.h>
using namespace std;
int d[5] = {0} , x[(int) 1e6] , n ;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> x[i], d[x[i]]++;
    if (d[2] == 0 ) cout << d[1];
    else if (d[1] == 1 ) cout << d[2];
    else cout << min(d[1],d[2]);
}