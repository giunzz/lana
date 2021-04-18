#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
#define ll long long 
const ll MAXN = 4e6+7;
ll a[MAXN] , b[MAXN] , ans = 0 , n ;
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= 2*n ; i++)
    {
        cin >> a[i] >> b[i];
        ans += a[i];
        b[i] = a[i] - b[i];
    }
    sort(b+1,b+1+2*n);
    for (int i = 2*n ; i > n ; i--) ans = ans-b[i];
    cout << ans ;
}
