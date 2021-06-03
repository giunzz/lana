#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
const ll maxn = 300007 ;
ll n , a , b , ans = INT_MAX ;
pair < ll , ll > d[maxn];
inline bool cmp (pl &a , pl&b)
{
    return (a.first <= b.first);
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> a >> b;
    for (int i = 1 ; i <= n ; i++) cin >> d[i].first >> d[i].second ;
    sort(d + 1 , d + 1 + n , cmp );
    ll j = 1, cnta = (d[1].second == 1), cntb = (d[1].second == 2);
    for (int i =  1 ; i <= n ; i++)
    {
        while (j < n && (cnta < a or cntb < b))
        {
            j++;
            if (d[j].second == 1 ) cnta ++;
            else cntb ++ ;
        }
        if(cnta >= a and cntb >=  b)
            ans = min(ans , d[j].first - d[i].first);
        if(d[i].second == 1) --cnta;
        else --cntb;
    }
    if (ans == INT_MAX) cout << -1;
    else cout << ans;
}
