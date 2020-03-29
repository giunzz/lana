#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define fin(tenfile) freopen(tenfile, "r", stdin)
#define fout(tenfile) freopen(tenfile, "w", stdout)
#define errl(variable) cerr << variable << "\n"
#define loop(variable, valuegan, valuebehonbang) for(long long variable = valuegan; variable <= valuebehonbang; variable++)
#define loopd(variable, valuegan, valuelonhonbang) for(long long variable = valuegan; variable >= valuelonhonbang; variable--)
#define loopdk(variable, valuegan, conditions, thaydoi) for(long long variable = valuegan; conditions; thaydoi) 
#define pp(type) pair<type, type>
#define mp make_pair
#define fi first
#define se second
#define vec(type) vector<type>
#define vecite(type) vector<type>::iterator
using namespace std;
const int maxn = INT_MAX/100;
int n, m, d[1007] = {maxn};
bool f[1007] = {1};
vec(vec(pp(int))) g;

void enter(){
    int u, v, w;
    loop(i, 1, m){
        cin >> u >> v >> w;
        g[u].push_back(mp(v, w));
        g[v].push_back(mp(u, w));
    }
}

void dijkstra(){
    int u = 1, mi, v;
    d[u] = 0;
    while(true){
      u = 0, mi = maxn;
      loop(i, 1, n)
        if(f[i] && d[i] < mi)
          u = i, mi = d[i];
      if(!u || u == n) break;
      f[u] = 0;
      loop(i, 0, g[u].size() - 1){
        if (d[g[u][i].fi] > (d[u] + g[u][i].se)){
          d[g[u][i].fi] = d[u] + g[u][i].se;
        }
      }
    }
}

int main(){
    opt;
    fin("input.inp");
    fout("output.txt");
    cin >> n >> m;
    g.resize(n + 2);
    enter();
    dijkstra();
    cout << d[n];
}
