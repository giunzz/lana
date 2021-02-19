#include <bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long 
const ll maxn = 1e6+7;
ll p[maxn]  , m ,n , size[maxn] ;
struct giun
{
    int u , v , w;
} a[maxn];

bool cmp (giun &x , giun &y)
{
    return (x.w < y.w);
}
ll get(int u)
{
    if (p[u] == u) return u;
    return p[u] = get(p[u]);
}
bool ghep(giun& a){
    ll x = get(a.u), y = get(a.v);
    if(x == y) return 0;
    if( size[x] < size[y]) swap(x, y);
    size[x] += size[y];
    p[y] = x;
    return 1;
}
int main()
{
    giuncute;
  //  freopen("giun.inp","r",stdin);
  //  freopen("giun.out","w",stdout);
    cin >> n >> m ;// n dinh m canh
    for (int i = 1 ; i <= m ; i++) cin >> a[i].u >> a[i].v >> a[i].w;
    for (int i = 1 ; i <= m ; i++) p[i] = i , size[i] = 1;
    sort (a+1 , a+1+m , cmp);
    ll ans = 0 , cnt = 0 ;
    for (int i = 1 ; i <= m ; i++ )
    {
        if(ghep(a[i]) && cnt != n - 1)
        {
            ++cnt;
            ans += a[i].w;
        }
    }
    cout << ans;
}
