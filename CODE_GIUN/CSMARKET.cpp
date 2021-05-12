#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
#define ll long long 
#define pi pair<int,int>
const int MAXN = 1e3+7;
const ll oo = 1e9 + 7;
ll N,M;
long long d[MAXN][MAXN]={0}, opt[MAXN];
ll p[MAXN][MAXN]={0}  ;

#define vec(a) vector<a>
#define pp(a, b) pair<a, b>

vec(pp(ll, ll)) g[MAXN];
vec(pp(ll, pp(ll, ll))) e;

void floy()
{
    for (int k = 1 ; k <= N ; k++)
    {
        for (int i = 1 ; i <= N ; i++)
        {
            for (int j = 1 ; j <= N ; j++)
            {
                if (d[i][j] > (d[i][k] + d[j][k]))
                {
                    d[i][j] = d[i][k] + d[j][k];
                    p[i][j] = k;
                }
            }
        }
    }
}

ll dj(ll cur){
    vec(ll) dp(N + 1, 1e18);
    dp[cur] = 0;
    priority_queue<pp(ll, ll), vec(pp(ll, ll)), greater<pp(ll, ll)>> q;
    q.push({0, cur});
    while(q.size()){
        ll u = q.top().second, cu = q.top().first;
        q.pop();
        if(cu != dp[u]) continue;
        for(pp(ll, ll) i : g[u]){
            ll v = i.second, uv = i.first;
            if(dp[v] > dp[u] + uv){
                dp[v] = dp[u] + uv;
                q.push({v, dp[v]});
            }
        }
    }
    return *max_element(dp.begin() + 1, dp.end());
}

int main()
{
    giuncute;
    freopen("CSMARKET.inp","r",stdin);
    freopen("CSMARKET.out","w",stdout);
    cin >> N >> M;
    ll x, y;
    long long l;
    for(int i = 1; i<=N; ++i) 
        for(int j = 1; j<=N; ++j) d[i][j] = 1e17;
    for(int i = 1; i<=N; ++i) d[i][i] = 0;
    for (int i = 1 ; i <= M ; i++)
    {
        cin >> x >> y >> l;
        d[x][y] = l; 
        d[y][x] = l;
        g[x].push_back({l, y});
        g[y].push_back({l, x});
        e.push_back({l, {x, y}});
    }   
    double ans = 1e18;
    for(int i = 1; i<=N; ++i){
        opt[i] = dj(i);
    }
    for(auto i : e){
        ans = min({ans, (opt[i.second.first] + opt[i.second.second] + i.first) / (2 * 1.0), opt[i.second.second] * 1.0,  opt[i.second.first] * 1.0});
    }
    cout << setprecision(2) << fixed << ans;
    // if (ans % 2 == 0  ) cout << ".00";
    // else cout << ".50";
}