#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pd pair<double,double>
#define fi first
#define se second
const ll MOD = 1e18;
const ll maxn = 4e6 + 7;
using namespace std;

ll  n ;
double ans = 1e19 ;
pd a[2][maxn] , nearest[4];

double kc(pd x, pd y) 
{
    double d = (x.fi - y.fi ) * (x.fi - y.fi )  + (x.se - y.se) * (x.se - y.se) ;
    return d;
}

void solve (ll l , ll r , ll state)
{
    if (l == r) return ;
    ll mid = (l + r) >> 1;
    double midx = a[state][mid].fi;
    solve( l, mid, 1 - state );
    solve( mid + 1, r, 1 - state );

    ll vt1 = l , vt2 = mid + 1 , now = l;
    for (int i = l ; i <= r ; i++)
    {
        if (vt1 > mid) a[state][now] = a[1-state][vt2] , vt2 ++;
        else if (vt2 > r)  a[state][now] = a[1-state][vt1] , vt1 ++;
        else if (a[1-state][vt1].se < a[1-state][vt2].se)
                a[state][now] = a[1-state][vt1] , vt1++;
        else a[state][now] = a[1-state][vt2] , vt2++;
        now++;
    }

    for (int i = 0 ; i <= 3 ; i++) nearest[i].fi = nearest[i].se = 1e18;
    ll vt = 0;
    for (int i = l ; i <= r ; i++)
    {
        if (abs(a[state][i].fi - midx) < ans)
        {
            for (int j = 0 ; j <= 3 ; j++) ans = min( ans, kc(a[state][i], nearest[j]) );
            nearest[vt] = a[state][i];
            vt ++; 
            if (vt == 4) vt = 0;
        }
    }
}


int main()
{
    freopen("NEAREST.inp","r",stdin);
    freopen("NEAREST..out","w",stdout);
    giuncute;
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[0][i].fi >> a[0][i].se;
    sort(a[0] + 1 , a[0] + 1 + n);
    for (int i = 1 ; i <= n ; i++) a[1][i] = a[0][i];
    solve( 1, n , 0 );
    cout << fixed << setprecision(3) << sqrt(ans);
    return 0;
}
