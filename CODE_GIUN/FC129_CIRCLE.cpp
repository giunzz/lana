#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 1e5 + 7;
using namespace std;

ll n , ans = 1;
pl a[maxn];
unordered_map<ll,ll> b;

bool cmp (pl &x , pl &y)
{
    return x.se < y.se;
}

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);    
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i].fi >> a[i].se;
    sort (a + 1 , a + 1 + n , cmp);
    for (int i = 1 ; i <= n ; i++)
    {
        ll  I = a[i].fi , R = a[i].se;
        ll right = I + R , left , cnt = 1;
        while (b.find(right) != b.end() && (left = b[right]) >= I-R )
        {
            //left =  b[right];
            //if (left  >= I - R) 
            right = left;
        }
        if (right == I - R) cnt++;
        b[I + R] = I-R;
        ans += cnt;
    }
    cout << ans;
}