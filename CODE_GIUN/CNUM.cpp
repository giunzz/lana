#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll oo = 1e18;
const ll maxn = 1e6 + 7;
ll ans = -oo , x[maxn] , n ;
vector<ll> chk;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> x[i];
    for (int i = 0 ; i <= n + 7 ; i++) chk.push_back(oo);
    chk[0] = -oo;
    for (int i = 1 ; i <= n ; i++)
    {
        ll vt = upper_bound(chk.begin() , chk.end() , x[i]) - chk.begin();
        //cerr << vt << " ";
        chk[vt] = x[i];
        ans = max (ans , vt);
    }
    cout << n - ans;
}