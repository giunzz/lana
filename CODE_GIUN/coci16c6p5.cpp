#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll int
#define pl pair<ll,ll>
const ll MOD = 1e9 + 7;
const ll maxm = 1e7 + 7;
const ll maxn = 1e5 + 7;
using namespace std;

ll n , p[maxn] , a[maxn] , size[maxn] , vt[maxm] ={0} ; 
bool visited[maxm] = {0};
ll naj[maxm] ;
vector<pl> g[maxm];

ll get (ll u)
{
    if (p[u] == u) return u;
    return p[u] = get(p[u]);
}

bool ghep (ll u , ll v)
{
    u = get(u) , v = get(v);
    if (u == v) return 0;
    if (size[u] < size[v]) swap(u , v);
    size[u] += size[v];
    p[v] = u ;
    return 1;
} 

void meo()
{
    for (int i = 1 ; i <= n ; i++)
    {
        if (visited[a[i]]) continue;
        visited[a[i]] = 1;
        if ((naj[a[i] + 1] != -1) && (a[i] * 2 > 1e7 || naj[a[i] * 2] != naj[a[i] + 1]))
        {
            g[naj[a[i] + 1] - a[i]].push_back({i , vt[naj[a[i] + 1]]});
            //cerr << i << " " << vt[naj[a[i] + 1]] << endl;
        }
        for (int j = a[i] * 2 ; j <= 1e7 ; j += a[i])
            if ((naj[j] != -1 ) && (j + a[i] > 1e7 || naj[j + a[i]] != naj[j]))
                g[naj[j] - j].push_back({i , vt[naj[j]]});
                    //cerr << i << " " << vt[naj[j]] << endl;
        //cerr << endl;
    }
}

int main()
{
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    scanf("%d",&n);
    for (int i = 0 ; i <= 1e7 + 3 ; i++) naj[i] = -1;
    for (int i = 1 ; i <= n ; i++)
    {
        p[i] = i , size[i] = 1;
        scanf("%d",&a[i]);
        if (vt[a[i]]) continue;
        vt[a[i]] = i , naj[a[i]] = a[i];
    }
    for (int i = 1e7 ; i >= 1 ; i--)
        if (naj[i] == -1) naj[i] = naj[i+1];
    meo();
    ll cnt = 0 , ans = 0 ;
    for (int i = 0 ; i <= 1e7 ; i++)
    {
        for(pl j : g[i]) 
            if(ghep(j.first, j.second)) ++cnt, ans += i ;
        if(cnt == n - 1) break;
    }
    printf("%d" , ans);
}
