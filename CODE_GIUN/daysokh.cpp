#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll oo = 1e18;
const ll maxn = 1e6 + 7;
ll ans = 0 , tmp = 1 , n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n;
    while (n > 0)
    {
        ans += (n % 2) * tmp;
        tmp *= 3;
        n /= 2;
    }
    cout << ans;
}
