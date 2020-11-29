#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define pp(a, b) pair<a, b>
#define vec(a) vector<a>
#define vecite(a) vector<a>::iterator
#define fi first
#define se second
#define mp(a, b) map<a, b>
#define setE(a, b) fill_n(a, sizeof(a)/sizeof(a[0]), b)
#define st(a) system((a).c_str());
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "dptree";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

ll n , x , f[(int) 1e6+7] ={0};
vector<int> g[(int)1e6+7];

void dfs(ll u)
{
    // cerr << g[u] << " ";
    for (int v :g[u]) dfs(v);
    for (int i = 0  ; i < g[u].size() ; i++) f[u] += f[g[u][i]]+1; 
    // cerr << f[u] << endl;
}
int main(){
    opt;
    file;
    cin >> n ;
    for (int i = 2 ; i <= n ; i++) cin >> x , g[x].push_back(i);
    dfs(1);
    for (int i = 1 ; i <= n ; i++) cout << f[i] << " ";
}
