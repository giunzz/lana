#include <bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
<<<<<<< HEAD
#define ll long long 
vector<int> a[(int) 1e5+7];
ll  cnt = 0 ,low[(int) 1e5+7], num[(int) 1e5+7], ans = 0, n , m , f[(int)1e5+7]={0};

void check (ll u)
{
    for (int v : a[u])  check(v);
    for (int v : a[u]) f[u] += f[v]+1;
}
void dfs(int u, int p) 
{
    num[u] = low[u] = cnt++;
    for(int v : a[u]) {
        if (num[v] == -1) 
		{
            dfs(v, u);
            if (low[v] > num[u]) 
			{
				cerr << u << " " << low[u] << " " << v << " " << num[v] << endl;
                memset(f, 0, sizeof f);
                check(u); check(v);
                for (int i = 1 ; i <= u ; i++) cerr << f[u] << " ";
                ll nga = f[u] + f[v];
				ans = max(ans,nga);
			}
            low[u] = min(low[u], low[v]);
        } 
    }
}
int main() {
	freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
=======
int n, m;
vector<int> a[(int) 1e5+7];
int cnt = 0, low[(int) 1e5+7], num[(int) 1e5+7], ans = 0;
void dfs(int u, int p) 
{
    num[u] = low[u] = cnt++;
    for(int v : a[u]) {
        if (num[v] == -1) 
		{
            dfs(v, u);
            if (low[v] > num[u]) 
			{
				//cerr << u << " " << low[u] << " " << v << " " << num[v] << endl;
				ans = max(ans,low[u]*(n-num[v]+1));
			}
            low[u] = min(low[u], low[v]);
        } 
    }
}
int main() {
	//freopen("giun.inp","r",stdin);
    //freopen("g.out","w",stdout);
>>>>>>> 629bcf8a162a36dcd07dff5f8c32b46fea2880b7
    cin >> n >> m;
    for(int i = 1; i <= m; i++) 
	{         
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
<<<<<<< HEAD
=======

>>>>>>> 629bcf8a162a36dcd07dff5f8c32b46fea2880b7
    memset(num, -1, sizeof num);
    memset(low, 0, sizeof low);
    for(int u = 1; u <= n; u++)
	{
        if (num[u] == -1) dfs(u, u);
	}
	cout << ans;
    return 0;
}