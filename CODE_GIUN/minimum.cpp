// #include <bits/stdc++.h>
// #define ll long long
// #define cll const ll
// #define giuncute  ios_base::sync_with_stdio(0),cin.tie(0); cout.tie(0);
// #define balololabobo freopen("giun.inp", "r" , stdin) , freopen("giun.out", "w" , stdout);
// using namespace std;
// cll maxn = 2e5+7;
// struct giun
// {
//     ll vl , vt;
// } a[maxn];
// bool cmp (giun x , giun y)
// {
//     return (x.vl <= y.vl);
// }
// ll n , ans = (ll) 1e18;
// int main()
// {
//     balololabobo;
//     giuncute;
//     cin >> n;
//     for (int i = 1 ; i <= n ; i++) cin >> a[i].vl , a[i].vt = i;
//     sort(a+1,a+1+n,cmp);
//     for (int i = 1 ; i <= n ; i++) cerr << a[i].vl << " "<< a[i].vt << endl;
//     for (int i = 2 ; i <= n ; i++)
//         if (a[i].vt < a[i-1].vt) ans = min(ans, a[i].vl - a[i-1].vl);
//     cout << ans;
// }


#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 4e5 + 7;
using namespace std;
ll n , t , x , f[maxn] = {0};
vector<pl> g[maxn];
ll DIJKSTRA (int s)
{
    priority_queue<pl, vector<pl> , greater<pl>> pq;
    for (int i = 1 ; i <= n ; i++) f[i] = MOD ;
    f[s] = 0;
    pq.push(make_pair(0,s));
    while (!pq.empty())
    {
        ll u = pq.top().second ; 
        ll dis_u = pq.top().first;
        pq.pop();
        if(f[u] != dis_u) continue;
        for (pl v : g[u])
        {
            if (f[v.first] > dis_u + v.second) 
            {
                f[v.first] = dis_u + v.second;
                pq.push(make_pair(f[v.first] , v.first));
            }
        }
    }
    return f[n];
}
int main()
{
    giuncute;
    freopen("MINIMUM.inp","r",stdin);
    freopen("MINIMUM.out","w",stdout);
    cin >> t ;
    while (t--)
    {   
        cin >> n;
        for (int i = 1 ; i <= n ; i++) g[i].clear();
        for (int i = 1 ; i <= n ; i++)
        {
            cin >> x;
            g[i].push_back(make_pair(i+1,1));
            g[i].push_back(make_pair(i-1,1));
            g[i].push_back(make_pair(x,0));
        }
        cout << DIJKSTRA(1) << endl;
    }
}