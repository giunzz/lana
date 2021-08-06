#include <bits/stdc++.h>
using namespace std;
#define ll int
#define pll pair<ll, ll>
#define fi first
#define se second
#define pb push_back

const int N = 205;
const ll mod = 1e9;
const int base = 300;

ll m, n, t, k, d[N][N], a[N], x[N*N], w[N*N], y[N*N], b[N], id[N], c[N];
bool cmp(const ll& x, const ll& y)
{
    return c[x] < c[y];
}
void sol()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            if(i == j)continue;
            d[i][j] = mod;
        }
    }
    for(int i = 1; i <= m; i ++)
    {
        cin >> x[i] >> y[i] >> w[i];
        d[x[i]][y[i]] = min(d[x[i]][y[i]], w[i]);
        d[y[i]][x[i]] = min(d[y[i]][x[i]], w[i]);
    }
    for(int k = 1; k <= n; k ++)
    {
        for(int i = 1; i <= n; i ++)
        {
            for(int j = 1; j <= n; j ++)d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
    }
    
    long double ans = mod;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            a[i] = max(a[i], d[i][j]);
        }
        ans = min(ans,(long double) a[i]);
    }

    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            if(i == j)continue;
            priority_queue< pll > pq;
            for(int k = 1; k <= n; k ++)
            {
                pq.push({d[j][k], k});
                b[k] = 0;
                c[k] = d[i][k];
                id[k] = k;
            }
            sort(id+1, id+1+n, cmp);
            for(int k = 1; k <= n; k ++)
            {
                ll c1 = c[id[k]], c2;
                b[id[k]] = 1;
                while(!pq.empty() && b[pq.top().se])pq.pop();
                c2 = pq.empty() ? 0 : pq.top().fi;
                if(abs(c1 - c2) > d[i][j])continue;
                ans = min(ans,(long double) (c1 + d[i][j] + c2) / 2.0);
            }

        }
    }
    cout << fixed << setprecision(2) << ans;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    #define task "csmarket"
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    int ntest = 1;
    //cin >> ntest;
    while(ntest -- > 0)
    sol();
}
/*
4 4
1 2 1
3 4 3
2 3 2
4 2 3
*/
