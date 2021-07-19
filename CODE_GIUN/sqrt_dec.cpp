#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
const ll maxn = 1e5 + 7 ;
using namespace std;
ll ans = 0 , n , l , r , block , cnt[320][maxn] , q , k , a[maxn];
string s;
int main()
{
    giuncute;
    freopen("sqrt_dec.inp","r",stdin);
    freopen("sqrt_dec.out","w",stdout);
    cin >> n >> q;
    ll b = sqrt(n);
    for (int i = 1 ; i <= n ; i++) 
    {
        cin >> a[i] ;
        cnt[i / b][a[i]]++;
    }
    for (int i = 1 ; i <= q ; i++)
    {
        ans = 0 ;
        cin >> l >> r >> k;
        block = r/b;
        for (int j = l ; j <= block * b-1 ; j++)
            if (j != (j/b) * b) ans += (a[j] == k);
            else ans += cnt[j/b][k] , j = (j/b + 1 ) * b -1;
        for (int j = max(l , block * b) ; j <= r ; j++) ans += (a[j] == k);
        cout << ans << endl;
    }
}
