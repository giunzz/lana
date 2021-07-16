#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0)

const ll maxn = 1e5+7;
ll n , f[maxn] ={0},ans = 0 , ma , vt;
struct giun
{
    int x,y , id;
}a[maxn];

bool cmp (giun &a , giun &b) {
    return (a.y <= b.y);
}

int main()
{ 
    giuncute;
    freopen("chonhd.inp", "r", stdin);
    freopen("chonhd.out", "w", stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i].x >> a[i].y , a[i].id = i ;
    sort (a+1, a+1+n , cmp);
    for (int i = 1 ; i <= n ; i++)
    {
        ma = 0;
        for (int j = 1 ; j < i ; j++)
            if (a[j].y <= a[i].x ) ma = max(f[j],ma);
        f[i] = ma + 1;
        if(f[i] > ans) ans = f[i], vt = i;
    }
    cout << ans << endl;
    ll i = vt;
    vector<ll> trace;
    trace.push_back(a[vt].id);
    while (1)
    {
        bool ok = 0;
        for (int j = 1; j < i ; j++)
        {
            if(f[j] == f[i] - 1)
            { 
                trace.push_back(a[j].id);
                i = j;
                ok = 1;
                break;
            }
        }
        if(!ok) break;
    }
    sort(trace.begin() , trace.end());
    for( ll v : trace) cout << v << ' ';
}

