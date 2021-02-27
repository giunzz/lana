#include <bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long 
const ll maxn = 1e5+7;
ll f[maxn] ={0} , h[maxn] , n ;

int main()
{
    giuncute;
    //freopen("giun.inp","r",stdin);
    //freopen("g.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> h[i];
    f[2] = abs(h[2]-h[1]);
    for (int i = 3 ; i <= n ; i++) f[i] = min(f[i-1] + abs(h[i] - h[i-1]), f[i-2] + abs(h[i] - h[i-2]));
    cout << f[n];
}
