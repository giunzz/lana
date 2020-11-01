#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
#define mp make_pair
#define task "gifts"
#define N 1000001
int n, a[N], k, d[N], dem = 0, dem2 = 0, p[N];
vector < pair < int , int > > b;
pair < int , pair < int , int > > v[N];

int giao(int x, int y, int l, int r)
{
    if (x <= l && l <= y) return 1;
    if (l <= x && x <= r) return 1;
    return 0;
}
int check(int x)
{
    while (!b.empty()) b.pop_back();
    for(int i=1; i<=dem; i++)
        if (v[i].F == x)
            {
                b.pb(mp(v[i].S.F, v[i].S.S));
            }
        else if (v[i].F > x)
            {
                int x = v[i].S.F;
                int y = v[i].S.S;
                int ok = 0;
                for(int j=0; j<b.size(); j++)
                    {
                        int x1 = b[j].F;
                        int y1 = b[j].S;
                        if (giao(x,y,x1,y1)) ok = 1;
                        if (ok == 1) break;
                    }
                if (ok == 0) return 0;
            }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i], d[i] = d[i-1] + a[i];
    for(int i=k; i<=n; i++)
        {
            int s = d[i] - d[i-k];
            v[++dem] = mp(s, mp(i-k+1, i));
        }
    sort(v+1, v+1+dem);
    p[++dem2] = v[1].F;
    for(int i=2; i<=dem; i++)
        if (v[i].F != v[i-1].F)
            p[++dem2] = v[i].F;
    int l = 0, r = dem2+1;
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (check(p[m])) r = m;
        else l = m;
    }
    cout << p[r];
    return 0;
}
