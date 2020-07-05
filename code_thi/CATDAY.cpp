#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll m , k , x ,y;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("CATDAY.inp","r",stdin);freopen("CATDAY.out","w",stdout);
    freopen("giun.inp","r",stdin);freopen("giun.out","w",stdout);
    cin >> m >> k ;
    x = m/ (1+k);
    y = x *k;
    if ( x + y == m) cout << min(x,y) << " " << max(x,y) ;
    else cout << -1;
    return 0;
}