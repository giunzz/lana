#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define Name "TREE"
#define ft(vt,i) for(__typeof((vt).begin()) i = (vt).begin() ; i != (vt).end() ; ++i)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
const int maxN = 5000 + 190;
const ll oo = 1e12;
int n ;
ll a[maxN] , f[maxN][maxN];
vii adj;
template<class T> int chkmin(T &a , const T b) {return (a >b ) ? a = b , 1 : 0;}
ll Abs(ll x) {return ((x < 0) ?  -x : x);}
void visit(int u)
{
    if(!adj[u].size()) return ;
    ft(adj[u] , v)
		visit(*v);
    if(adj[u].size() == 1)
	{
        for(int i = 0 ; i <= n ; ++i) f[u][i] = min(f[u][i] , f[adj[u][0]][i] + Abs(i - a[u]));
	}
    if(adj[u].size() == 2)
	{
        for(int i = 0 ; i <= n ; ++i) for(int j = 0 ; j <= i ; ++j)
        f[u][i] = min(f[u][i] , f[adj[u][0]][j] + f[adj[u][1]][i - j] + Abs(i - a[u]));
	}
}
int main()
{
    freopen(Name".inp","r",stdin);
    freopen(Name".out","w",stdout);
	scanf("%d",&n);
	for(int i = 1; i <= n ; ++i)scanf("%lld",&a[i]);
    adj.assign(n + 10 , vi());
    for(int i = 1; i < n ; ++i)
	{
		int u ,v;
		scanf("%d%d",&u,&v);
        adj[u].push_back(v);
	}
    for(int i = 1;  i <= n ; ++i) for(int j = 0 ; j <= n ; ++j) f[i][j] = oo;
    for(int i = 1 ; i <= n ; ++i) if(!adj[i].size())
	{
        f[i][0] = a[i];
        f[i][1] = Abs(a[i] - 1);
	}
	visit(1);
	ll ans = oo;
	for(int i = 0 ; i <= n ; ++i) ans = min(ans , f[1][i]);
	printf("%lld",ans);
    return 0;
}
