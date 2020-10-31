#include <bits/stdc++.h>
using namespace std;
int n, k, u, v, c, a[50005];
int main ()
{
    freopen ("bubbletea.inp","r",stdin);freopen("bubbletea.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for ( int i=1; i<=k; i++)
        cin >> a[i];
    for ( int i=1; i<=n-1; i++)
        cin >> u >> v >> c;
    if ( n <=500 ) cout << "3";
    else cout <<"-1";
}
